'use strict';

angular.module('ufApp')
  .controller('UserProfileCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
      console.log($scope.page);
    });

  $scope.$watch('uid', function () {

    $scope.$watch('$elements', function() {
      // Set config var.
      var config = {
        'id': 'user-profile',
        'url': '/api/user-profile.jsonp?callback=JSON_CALLBACK&uid=' + $scope['uid'],
        'parser': function(data) {
          // Set up page data.
          var page = {};
          page = data[0];


          // Then return it.
          return page;
        }
      };
      // Get data, and fire event when ready.
      getter.getData($scope, config);
    });
  });
}]);

