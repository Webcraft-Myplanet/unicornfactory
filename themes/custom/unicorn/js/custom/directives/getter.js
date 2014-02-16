;'use strict';

angular.module('getter.directives', [])
.factory('getter', ['$http', 'localStorageService', function ($http, localStorageService) {
  return {
    getData: function($scope, config) {
        // Set global data var.
        var data;

        // Set default event.
        if (config.eventId === undefined) {
          config.eventId = 'dataLoaded';
        }

        // Get the data from json.
        var getJson = function () {
          $http.jsonp(config.url)
          .success(function(jsonData) {
              // Parse the data.
              data = config.parser(jsonData);

              if (config.cacheId !== undefined) {
                // Compare to cached, and set if needed.
                var cachedPageData = localStorageService.get(config.cacheId);

                if (JSON.stringify(cachedPageData) != JSON.stringify(data)) {
                  localStorageService.add(config.cacheId, data);
                  $scope.$emit(config.eventId, data);
                }
              }
              else {
                $scope.$emit(config.eventId, data);
              }
            });
        };

        // Try to get/set data.
        if (config.cacheId === undefined || !localStorageService.get(config.cacheId)) {
          // If no cookie data, retrieve it and set it.
          getJson();
        }
        else {
          // Get data from cookie.
          data = localStorageService.get(config.cacheId);
          $scope.$emit(config.eventId, data);
          getJson();
        }
      }
    }
  }])
;
