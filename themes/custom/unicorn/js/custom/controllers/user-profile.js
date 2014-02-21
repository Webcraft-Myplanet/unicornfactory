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
    var fields = 'field_skill,field_status';
    $http({url: '/api/uf_field.jsonp?callback=JSON_CALLBACK&fields=' + fields, method: 'jsonp'})
    .success(function(options){
      $scope.options = options;
    });

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

    // Update function.
    $scope.updateUser = function() {
      return $http({
        url: '/api/uf_edit_user/' + $scope['uid'] + '.json',
        method: 'post',
        'headers': headers,
        data: $scope.page})
      .success(function(status){
        $scope.status = status;
        return true;
      });
    }
}]);