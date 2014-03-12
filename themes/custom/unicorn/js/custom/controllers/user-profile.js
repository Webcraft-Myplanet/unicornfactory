'use strict';

angular.module('ufApp')
.controller('UserProfileCtrl', ['$scope', '$http', 'getter', function ($scope, $http, getter) {

  // Get session token so we can submit data.
  var headers = {};
  $http.get('/services/session/token')
  .success(function(token){
    headers = {'X-CSRF-Token': token};
  });

  // Fields to request data for.
  var fields = 'field_skill,field_member_of,field_working_on';
  $http({url: '/api/uf_field.jsonp?callback=JSON_CALLBACK&fields=' + fields, method: 'jsonp'})
  .success(function(options){
    $scope.options = options;
  });

  // Add an event listener.
  $scope.$on('dataLoaded', function(event, page) {
    $scope.page = page;
  });

  // Wait for nid value.
  $scope.$watch('uid', function () {
    // Set config var.
    var config = {
      'id': 'user-skills',
      'url': '/api/uf_user/' + $scope['uid'] + '.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Return the data.
        return data;
      }
    };

    // Get data, and fire event when ready.
    getter.getData($scope, config);
  });

  // Validate name field.
  $scope.validateName = function(data) {
    if (data === '') {
      return "You cannot have a blank name.";
    }
  }

  // Want to add a team show the Team form to allow users to select teams
  $scope.addTeam = function(data) {
    $scope.tmpTeam.name = data;
    $scope.page.related_teams.push({ 'name': data} );
  }

  // Remove Team remove from related_teams array.
  $scope.removeTeam = function(index) {
    $scope.page.related_teams.splice(index, 1);
  }

  // Validate name field.
  $scope.addSkill = function() {
    $scope.page.skills.push({skill:'',current:'',desired:''});
  }

  // Update function.
  $scope.updateUser = function() {
    var out = $http({
      url: '/api/uf_user/' + $scope['uid'] + '.json',
      method: 'post',
      'headers': headers,
      data: $scope.page})
    .success(function(status){
      $scope.status = status;
      return true;
    });
  }

}]);
