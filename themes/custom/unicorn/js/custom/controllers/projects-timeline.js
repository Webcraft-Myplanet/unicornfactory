'use strict';

angular.module('ufApp')
  .controller('ProjectsTimelineCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
    });

    // Set config var.
    var config = {
      'id': 'projects',
      'url': '/api/projects-timeline.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var page = {};
        page.projects = data;

        // Set up a timestamp for right now
        var currTime = new Date();

        // Set up the number of days in each month
        var daysInMonth = new Array(31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31);

        // Pick out some special colours
        var timelineColours = new Array("blue","red","green","yellow","black","#CCC")

        // This will serve as the boundaries between timestamps for bootstrap columns
        var bootColToTime = new Array();

        var index;
        // We need to keep track of the current month for the next loop
        var firstMonth = currTime.getMonth();
        // We also need to keep track of the timestamp of the first day of each month
        var firstDayOfMonth = Array();

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

        for (index = 0; index < page.projects.length; index++) {

          // Convert each projectStartDate and projectEndDate into a usable Date object
          page.projects[index].projectStartDateObj = new Date(page.projects[index].projectStartDate);
          page.projects[index].projectEndDateObj = new Date(page.projects[index].projectEndDate);

          // Determine the Bootstrap offset to visually represent the starting date in the Timeline
          tempTimestamp = page.projects[index].projectStartDateObj.getTime();
          for (bootIndex = 0; bootIndex < bootColToTime.length; bootIndex++) {
            // If the start date's timestamp falls within a certain bootstrap boundary
            if (bootColToTime[bootIndex] <= tempTimestamp && tempTimestamp < bootColToTime[bootIndex + 1]) {
              // Set the bootstrap offset to that boundary
              bootOffset = bootIndex;
              // No need to keep going
              break;
            }
          }

          // Special exception: If the start date is past the last column boundary, set offset to 12
          if (tempTimestamp >= bootColToTime[12]) {
            bootOffset = 12;
          }

          // Special exception: If the start date is before the first column boundary, set offset to 0
          if (tempTimestamp < bootColToTime[0]) {
            bootOffset = 0;
            // Also show a left arrow on the timeline to represent a project before the 4-month scope
            page.projects[index].leftArrow = true;
          }

          // Determine the Bootstrap size to visually represent how long the project runs
          tempTimestamp = page.projects[index].projectEndDateObj.getTime();
          for (bootIndex = 0; bootIndex < bootColToTime.length; bootIndex++) {
            // If the end date's timestamp falls within a certain bootstrap boundary
            if (bootColToTime[bootIndex] <= tempTimestamp && tempTimestamp < bootColToTime[bootIndex + 1]) {
              // Set the bootstrap size to that boundary
              bootSize = bootIndex;
              // No need to keep going
              break;
            }
          }

          // Special exception: If the end time is past the last column boundary, set size to maximum
          // also handle Start and End Dates that are exactly the same as a Project with indefinite end time
          if (tempTimestamp >= bootColToTime[12] || tempTimestamp == page.projects[index].projectStartDateObj.getTime()) {
            bootSize = 12;
            page.projects[index].rightArrow = true;
          }

          // We have to reduce the size of the Timeline bar because of the offset
          bootSize = bootSize - bootOffset;

          // Special exception: If the offset has declared a valid start date but the bootSize is too small
          if (bootOffset > 0 && bootOffset < 12 && bootSize == 0) {
            bootSize = 1;
          }

          // Special exception: If the end time isn't even past the first column boundary, reduce size to 0
          if (tempTimestamp < bootColToTime[0]) {
            bootSize = 0;
          }

          // Convert offset and size into classes for Bootstrap to visually display
          if (bootOffset > 0) {
            page.projects[index].bootOffset = 'col-xs-offset-' + bootOffset;
          }
          if (bootSize > 0) {
            page.projects[index].bootSize = 'col-xs-' + bootSize;
            // Make the object showable since there is a size
            page.projects[index].show = true;
          }

          // Lastly set a colour for this timeline bar
          page.projects[index].bootColour = timelineColours[index % timelineColours.length];
        }

        // Then return it.
        return page;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
