'use strict';

angular.module('ufApp')
  .controller('ProjectsTimelineCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
    });

    $scope.centerDate = function () {
      $scope.scrollToToday(new Date());
    }

    // Set config var.
    var config = {
      'id': 'projects',
      'url': '/api/projects-timeline.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var page = {};
        page.projects = data;

        // Prepare final Gantt projects output
        var gantt = Array();

        // Set up temporary variables
        var proj;
        var task;
        var index;

        // Set up a colour array to make things look nicer
        var colours = Array('#BED661','#89E894','#78D5E3','#7AF5F5','#34DDDD','#93E2D5');

        for (index = 0; index < page.projects.length; index++) {
          proj = new Object();
          task = new Object();
          // The project needs to be allocated in its own row along with a task showing its timeframe within the row
          proj.id = page.projects[index].nid;
          proj.description = page.projects[index].title;
          proj.status = page.projects[index].status;
          if (!page.projects[index].projectStartDate) {
            task.id = page.projects[index].nid;
            task.subject = page.projects[index].title;
            task.from = new Date(page.projects[index].projectStartDate);
            if (!page.projects[index].projectEndDate && page.projects[index].projectStartDate != page.projects[index].projectEndDate) {
              task.to = new Date(page.projects[index].projectEndDate);
            } else {
              task.to = new Date();
              task.rightArrow = 'right-arrow';
            }
            task.description = page.projects[index].description;
            task.color = colours[index % colours.length];
            proj.tasks = Array(task);
          } else {
            proj.tasks = Array();
          }
          // Add the final project Object to the gantt output
          gantt[index] = proj;
        }

        // Assign the gantt output to the page var
        page.gantt = gantt;

        // Then return it.
        return page;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
