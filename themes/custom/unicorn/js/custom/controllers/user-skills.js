'use strict';

angular.module('ufApp')
  .controller('UserSkillsCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
    });

    $scope.$watch('uid', function () {

    // Set config var.
    var config = {
      'id': 'user-skills',
      'url': '/api/uf_edit_user/' + $scope['uid'] + '.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var page = {};
        page = data;
        
        var index =[];
        for (var x in page.field_user_skill.und) {
          index.push(x);
        }
        // Then return it.
        return page;
        return index;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  });
}]);