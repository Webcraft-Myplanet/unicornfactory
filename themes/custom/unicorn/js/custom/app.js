'use strict';

var app = angular.module('ufApp', [
  'gantt',
  'getter.directives',
  'LocalStorageModule',
  'ngSanitize',
  'ngRoute',
  'ui.bootstrap',
  'xeditable',
  'checklist-model'
]);

app.run(function(editableOptions, editableThemes) {
  // Set bootstrap 3 theme for "inline editor"
  editableThemes.bs3.buttonsClass = 'btn-xs';
  editableOptions.theme = 'bs3';
});
