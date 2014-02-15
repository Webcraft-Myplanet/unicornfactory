'use strict';

angular.module('ufApp')
.controller('ProjectProfileCtrl', ['$scope', '$http', '$filter', 'getter', function ($scope, $http, $filter, getter) {
    // Get session token so we can submit data.
    var headers = {};
    $http.get('/services/session/token')
      .success(function(token){
        headers = {'X-CSRF-Token': token};
      }
    );

    // Add an event listener for node data.
    $scope.$on('dataLoaded', function(event, data) {
      console.log(data);
      $scope.page = data;
    });

    $scope.$watch('nid', function () {
      // Set config var.
      var config = {
        'cacheId': 'project-' + $scope.nid,
        'url': '/api/uf_edit/project_profile_node_form/' + $scope.nid + '.jsonp?callback=JSON_CALLBACK',
        'parser': function(data) {
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
      return $http({url: '/api/uf_edit/project_profile_node_form/' + $scope.page.nid + '.json', method: 'post', 'headers': headers, data: $scope.page});
    }
  }]);
