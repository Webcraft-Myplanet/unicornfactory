'use strict';

angular.module('ufApp')
.controller('ProjectProfileCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, pageData) {
      $scope.page = pageData;
      console.log($scope.page);
    });

    $scope.$watch('nid', function () {

      // Set config var.
      var config = {
        'id': 'project',
        'url': '/api/project.jsonp?callback=JSON_CALLBACK&nid=' + $scope.nid,
        'parser': function(data) {
          // Set up page data.
          var pageData = {};
          pageData.project = data[0];

          // Then return it.
          return pageData;
        }
      };

      // Get data, and fire event when ready.
      getter.getData($scope, config);

    });
  }]);
