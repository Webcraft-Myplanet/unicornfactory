'use strict';

angular.module('ufApp')
  .controller('TeamsCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
      console.log($scope.page);
    });

    // Set config var.
    var config = {
      'id': 'teams',
      'url': '/api/teams.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var page = {};
        page.teams = data;

        // Then return it.
        return page;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
