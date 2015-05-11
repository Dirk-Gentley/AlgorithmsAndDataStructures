angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Group Meeting 1', content:'minutes/02-03-15.pdf' },
    { title:'Group Meeting 2', content:'minutes/06-03-15.pdf'},
    { title:'Group Meeting 3', content:'minutes/13-03-2015.pdf' },
    { title:'Group Meeting 4', content:'minutes/20-03-2015.pdf'},
    { title:'Group Meeting 5', content:'minutes/27-03-15.pdf' },
    { title:'Group Meeting 6', content:'minutes/10-04-2015.pdf'},
    { title:'Group Meeting 7', content:'minutes/17-04-15.pdf'},
    ( title:'Group Meeting 8', content:'minutes/27-04-15.pdf')
  ];
});