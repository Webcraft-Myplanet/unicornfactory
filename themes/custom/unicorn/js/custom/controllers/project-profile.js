'use strict';

angular.module('ufApp')
.controller('ProjectProfileCtrl', ['$scope', '$http', 'getter', function ($scope, $http, getter) {
    // Get session token so we can submit data.
    var headers = {};
    $http.get('/services/session/token')
    .success(function(token){
      headers = {'X-CSRF-Token': token};
    });

    // Fields to request data for.
    var fields = 'field_skill,field_status';
    $http({url: '/api/uf_field.jsonp?callback=JSON_CALLBACK&fields=' + fields, method: 'jsonp'})
    .success(function(options){
      $scope.options = options;
    });

    // Add an event listener for node data.
    $scope.$on('dataLoaded', function(event, data) {
      $scope.page = data;
    });

    // Add a new skill.
    $scope.addSkill = function (data) {
      // If there's no data, do nothing.
      if (data == '') {
        return false;
      }

      // Otherwise, add it to the scope var, and push to drupal.
      $scope.page.field_skill.und.push($scope.newSkill);
      $scope.updateProject();
    }

    // Validate new skills.
    $scope.validateSkill = function (data, index) {
      // Trim whitespace.
      data = data.trim();

      // Setup return var.
      var returnVal = true;

      // Check for first skill.
      if (index === -1 && typeof $scope.page.field_skill.und !== 'object') {
        $scope.page.field_skill.und = [];
      }
      // Check for empty data, AKA removing a skill.
      else if (data == '') {
        $scope.page.field_skill.und.splice(index, 1);
      }
      // Check for duplicates.
      else if ($scope.page.field_skill.und.indexOf(data) !== -1) {
        return 'Skill already exists.';
      }

      return returnVal;
    }

    // Create config var.
    var config = {};

    $scope.$watch('nid', function () {
      // Set config var.
      var config = {
        'cacheId': 'project-' + $scope.nid,
        'url': '/api/uf_edit/project_profile_node_form/' + $scope.nid + '.jsonp?callback=JSON_CALLBACK',
        'parser': function(data) {
          // Remove empty skills array.
          if (data.field_skill.und[0] == '') {
            delete data.field_skill.und;
          }

          // Set up page data.
          var page = {};
          page = data;

          // Then return it.
          return page;
        }
      };

      // Get data, and fire event when ready.
      getter.getData($scope, config);
    });

    // Update function.
    $scope.updateProject = function() {
      return $http({
        url: '/api/uf_edit/project_profile_node_form/' + $scope.page.nid + '.json',
        method: 'post',
        'headers': headers,
        data: $scope.page})
      .success(function(status){
        $scope.status = status;
        return true;
      });
    }
  }]);
