'use strict';

angular.module('ufApp')
.controller('ProjectProfileCtrl', ['$scope', '$http', 'getter', function ($scope, $http, getter) {
    // Add an event listener for page data display.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
      console.log($scope.page);
    });

    // Get session token.
    var headers = {};
    $http.get('/services/session/token')
      .success(function(token){
        console.log(token);
        headers = {'X-CSRF-Token': token};
      }
    );
    // Add an event listener for node data and create var.
    var nodeData = {};
    $scope.$on('projectNodeLoaded', function(event, data) {
      nodeData = data;

      // Add our uid to the node data.
      nodeData.uid = $scope.uid;

      // Remove "extra" data.
      delete nodeData.changed;
      delete nodeData.comment;
      delete nodeData.created;
      delete nodeData.data;
      delete nodeData.field_start_date;
      delete nodeData.field_avatar;
      delete nodeData.field_skill;
      delete nodeData.field_status;
      delete nodeData.log;
      delete nodeData.name;
      delete nodeData.path;
      delete nodeData.picture;
      delete nodeData.promote;
      delete nodeData.revision_timestamp;
      delete nodeData.revision_uid;
      delete nodeData.status;
      delete nodeData.sticky;
      delete nodeData.tnid;
      delete nodeData.translate;

      console.log(data);
    });

    $scope.$watch('nid', function () {

      // Set config var.
      var config = {
        'id': 'project',
        'url': '/api/project.jsonp?callback=JSON_CALLBACK&nid=' + $scope.nid,
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


      // Set config var.
      var config = {
        'event': 'projectNodeLoaded',
        'url': '/api/node/' + $scope.nid + '.jsonp?callback=JSON_CALLBACK',
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
    $scope.updateProject = function(element, data) {
      switch (element) {
        case 'title':
        nodeData.title = data;
        break;
        default:
        break;
      }

      return $http({url: '/api/node/' + nodeData.nid + '.json', method: 'put', 'headers': headers, data: nodeData});
    }
  }]);
