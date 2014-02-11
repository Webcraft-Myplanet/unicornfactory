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
        var currTime = new Date();

        // Set up the number of days in each month
        var daysInMonth = new Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

        // Pick out some special colours
        var timelineColours = new Array("blue","red","green","yellow","black","#CCC")

        // This will serve as the boundaries between timestamps for bootstrap columns
        var bootColToTime = new Array();

        var index;
        var firstMonth = currTime.getMonth(); // We need to keep track of the current month for the next loop
        var firstDayOfMonth = Array(); // We also need to keep track of the timestamp of the first day of each month

        for (index = 0; index < 4; index++) {
          // Set up the timestamp for the 1st of every relevant month
          firstDayOfMonth[index] = new Date(currTime.getFullYear(), currTime.getMonth() + index);
          // Create boundaries (1/3 of each relevant month represents a column)
          bootColToTime[3 * index] = firstDayOfMonth[index].getTime();
          bootColToTime[3 * index + 1] = firstDayOfMonth[index].getTime() + (daysInMonth[index + firstMonth] * 86400000 / 3);
          bootColToTime[3 * index + 2] = firstDayOfMonth[index].getTime() + (daysInMonth[index + firstMonth] * 86400000 * 2 / 3);
          // This last line overlaps between loops but writes the same values so it's okay
          bootColToTime[3 * index + 3] = firstDayOfMonth[index].getTime() + (daysInMonth[index + firstMonth] * 86400000);
        }

        // Set up some temp vars for calculations in the next loop
        var tempTimestamp, bootOffset, bootSize, bootIndex;

        for (index = 0; index < pageData.projects.length; index++) {

          // Convert each projectStartDate and projectEndDate into a usable Date object
          pageData.projects[index].projectStartDateObj = new Date(pageData.projects[index].projectStartDate);
          pageData.projects[index].projectEndDateObj = new Date(pageData.projects[index].projectEndDate);

          // Determine the Bootstrap offset to visually represent the starting date in the Timeline
          tempTimestamp = pageData.projects[index].projectStartDateObj.getTime();
          for (bootIndex = 0; bootIndex < bootColToTime.length; bootIndex++) {
            // If the start date's timestamp falls within a certain bootstrap boundary
            if (bootColToTime[bootIndex] <= tempTimestamp && tempTimestamp <= bootColToTime[bootIndex + 1]) {
              bootOffset = bootIndex; // Set the bootstrap offset to that boundary
              break; // No need to keep going
            }
          }

          // Special exception: If the start date is past the last column boundary, set offset to 12
          if (tempTimestamp > bootColToTime[12]) bootOffset = 12;

          // Special exception: If the start date is before the first column boundary, set offset to 0
          if (tempTimestamp < bootColToTime[0]) bootOffset = 0;

          // Determine the Bootstrap size to visually represent how long the project runs
          tempTimestamp = pageData.projects[index].projectEndDateObj.getTime();
          for (bootIndex = 0; bootIndex < bootColToTime.length; bootIndex++) {
            // If the end date's timestamp falls within a certain bootstrap boundary
            if (bootColToTime[bootIndex] <= tempTimestamp && tempTimestamp <= bootColToTime[bootIndex + 1]) {
              bootSize = bootIndex; // Set the bootstrap size to that boundary
              break; // No need to keep going
            }
          }

          // Special exception: If the end time is past the last column boundary, set size to maximum
          if (tempTimestamp > bootColToTime[12]) bootSize = 12;

          // Special exception: If the end time isn't even past the first column boundary, reduce size to 0
          if (tempTimestamp < bootColToTime[0]) bootSize = 0;

          // We have to reduce the size of the Timeline bar because of the offset
          bootSize = bootSize - bootOffset;

          // Convert offset and size into classes for Bootstrap to visually display
          if (bootOffset > 0) pageData.projects[index].bootOffset = 'col-xs-offset-' + bootOffset;
          else pageData.projects[index].bootOffset = '';
          if (bootSize > 0) pageData.projects[index].bootSize = 'col-xs-' + bootSize;
          else pageData.projects[index].bootSize = 'hidden'; // Hide the bar if there is no timeframe

          // Lastly set a colour for this timeline bar
          pageData.projects[index].bootColour = timelineColours[index % timelineColours.length];
        }

        console.log(pageData.projects); // For debugging purposes

        // Then return it.
        return pageData;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
