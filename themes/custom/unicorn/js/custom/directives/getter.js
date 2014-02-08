;'use strict';

angular.module('getter.directives', [])
  .factory('getter', ['$http', 'localStorageService', function ($http, localStorageService) {
    return {
      getData: function($scope, config) {
        // Set global pageData var.
        var pageData;

        // Get the data from json.
        var getJson = function () {
          $http.jsonp(config.url)
            .success(function(jsonData) {
              // Parse the data.
              pageData = config.parser(jsonData);

              // Compare to cached, and set if needed.
              var cachedPageData = localStorageService.get(config.id);

              if (JSON.stringify(cachedPageData) != JSON.stringify(pageData)) {
                localStorageService.add(config.id, pageData);
                $scope.$emit('dataLoaded', pageData);
              }
            });
        };

        // Try to get/set pageData.
        if (!localStorageService.get(config.id)) {
          // If no cookie data, retrieve it and set it.
          getJson();
        }
        else {
          // Get data from cookie.
          pageData = localStorageService.get(config.id);
          $scope.$emit('dataLoaded', pageData);
          getJson();
        }
      }
    }
  }])
;
