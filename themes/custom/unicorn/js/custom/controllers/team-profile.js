'use strict';

angular.module('ufApp')
.controller('TeamProfileCtrl', ['$scope', '$http', 'getter', function ($scope, $http, getter) {
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

    // Create config var.
    var config = {};

    $scope.$watch('nid', function () {
      // Set config var.
      var config = {
        'cacheId': 'team-' + $scope.nid,
        'url': '/api/uf_node/team_profile_node_form/' + $scope.nid + '.jsonp?callback=JSON_CALLBACK',
        'parser': function(data) {
          // Remove empty skills array.
          if (data.field_skills.und[0] == '') {
            delete data.field_skills.und;
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
    $scope.updateTeam = function() {
      return $http({
        url: '/api/uf_node/team_profile_node_form/' + $scope.page.nid + '.json',
        method: 'post',
        'headers': headers,
        data: $scope.page})
      .success(function(status){
        $scope.status = status;
        return true;
      });
    }
  }]);
