'use strict';

angular.module('ufApp')
  .controller('ProjectsTimelineCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, pageData) {
      $scope.page = pageData;
      console.log($scope.page);
    });

    // Set config var.
    var config = {
      'id': 'projects',
      'url': '/api/projects-timeline.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var pageData = {};
        pageData.projects = data;

        // Set up a timestamp for right now
        var currTime = Date.now();

        // Set up the number of days in each month
        var daysInMonth = new Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

        var bootColToTime = new Array();
        var index;
        var colIndex = 0;
        for (index = currTime.getMonth(); index < (currTime.getMonth() + 4); ++index) {
          bootColToTime[3 * index] = currTime + (daysInMonth[index] * 86400 / 3);
          bootColToTime[3 * index + 1] = currTime + (daysInMonth[index] * 86400 * 2 / 3);
          bootColToTime[3 * index + 2] = currTime + (daysInMonth[index] * 86400);
        }
        console.log(bootColToTime[0]);
        console.log("Hello!");
        // Set up some temp vars
        var startDiff, bootOffset, bootSize;

        for (index = 0; index < pageData.projects.length; ++index) {
          // Convert each projectStartDate and projectEndDate into a usable Date object
          pageData.projects[index].projectStartDateObj = new Date(pageData.projects[index].projectStartDate);
          pageData.projects[index].projectEndDateObj = new Date(pageData.projects[index].projectEndDate);
          //console.log(pageData.projects[index]);
          // Determine the Bootstrap offset to visually represent the starting date in the Timeline
          //startDiff = pageData.projects[index].projectStartDateObj.getTime() - currTime;
        }

        // Then return it.
        return pageData;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
