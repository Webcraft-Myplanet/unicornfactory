'use strict';

var app = angular.module('ufApp', [
  'getter.directives',
  'LocalStorageModule',
  'ngSanitize',
  'ngRoute',
  'xeditable'
]);

app.run(function(editableOptions) {
  // Set bootstrap 3 theme for "inline editor"
  editableOptions.theme = 'bs3';
});
