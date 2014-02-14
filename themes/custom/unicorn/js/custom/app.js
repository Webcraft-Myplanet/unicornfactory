'use strict';

var app = angular.module('ufApp', [
  'getter.directives',
  'LocalStorageModule',
  'ngSanitize',
  'ngRoute',
  'ui.bootstrap',
  'xeditable'
]);

app.run(function(editableOptions) {
  // Set bootstrap 3 theme for "inline editor"
  editableOptions.theme = 'bs3';
});
