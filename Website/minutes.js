angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Dynamic Title 1', content:'meeting-minutes-02-03-2015.pdf' },
    { title:'Dynamic Title 2', content:'meeting-minutes-06-03-2015.pdf'}
  ];
});