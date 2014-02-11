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

        /*var index;
        for (index = 0; index < pageData.projects.length; ++index) {
          var startDate = new Date(pageData.projects[index].projectStartDate);
          var endDate = new Date(pageData.projects[index].projectEndDate);
          //pageData.projects[index][projectStartDateObj] = startDate;
          //pageData.projects[index][projectEndDateObj] = endDate;
          //console.log(pageData.projects[index]);
        } */

        // Then return it.
        return pageData;
      }
    };
    // Get data, and fire event when ready.
    getter.getData($scope, config);
  }]);
