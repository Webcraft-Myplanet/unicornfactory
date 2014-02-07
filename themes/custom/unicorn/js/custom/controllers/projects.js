'use strict';

angular.module('ufApp')
  .controller('ProjectsCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, pageData) {
      $scope.page = pageData;
      console.log($scope.page);
    });

    // Set config var.
    var config = {
      'id': 'projects',
      'url': 'api/projects.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var pageData = {};
        pageData.projects = data;

        // Then return it.
        return pageData;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
