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

  // Load a list of Teams in the system based on options.field_member_of
  $scope.teams = [];
  $scope.loadTeams = function() {
    var n = 0;
    $scope.teams.splice(0, $scope.teams.length); // clear out the list and recreate
    for (n in $scope.options.field_member_of ) {
        $scope.teams.push( $scope.options.field_member_of[n]);
    }
  }

  // Want to add a team show the Team form to allow users to select teams
  $scope.addTeam = function(nid) {
    if ( nid === null || nid === 0) {
      // don't do anything
      return false;
    } else {
      console.log('adding node ' + nid);
      $scope.page.myTeams.push(nid);
      return true;
    }
  }

  // Remove Team remove from related_teams array. Expecting index into myTeams array.
  $scope.removeTeam = function(index) {
    console.log('removing index ' + index);
    $scope.page.myTeams.splice(index, 1);
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
