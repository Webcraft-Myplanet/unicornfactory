'use strict';

angular.module('ufApp')
  .controller('ProjectsTimelineCtrl', ['$scope', 'getter', function ($scope, getter) {
    // Add an event listener.
    $scope.$on('dataLoaded', function(event, page) {
      $scope.page = page;
    });

    $scope.addSamples = function () {
      $scope.loadData($scope.page.gantt);
    }

    // Set config var.
    var config = {
      'id': 'projects',
      'url': '/api/projects-timeline.jsonp?callback=JSON_CALLBACK',
      'parser': function(data) {
        // Set up page data.
        var page = {};
        page.projects = data;

        ///console.log(page);

        // Prepare data for Gantt graph
        var tasks = new Object();
        page.gantt = Array();
        var gantt = new Object();
        var index;
        for (index = 0; index < page.projects.length; index++) {
          gantt = new Object();
          tasks[index] = new Object();
          tasks[index].id = page.projects[index].nid + '-t';
          tasks[index].subject = page.projects[index].title;
          tasks[index].from = new Date(page.projects[index].projectStartDate);
          tasks[index].to = new Date(page.projects[index].projectEndDate);

        }

        var gantt = new Object();
        gantt.id = 'abcdefgh';
        gantt.description = 'Active Projects';
        gantt.tasks = tasks;

        page.gantt = Array(gantt);

        // Then return it.
        return page;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
