angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Group Meeting 1', content:'02-03-15.pdf' },
    { title:'Group Meeting 2', content:'06-03-15.pdf'},
    { title:'Group Meeting 3', content:'13-03-2015.pdf' },
    { title:'Group Meeting 4', content:'20-03-2015.pdf'},
    { title:'Group Meeting 5', content:'27-03-15.pdf' },
    { title:'Group Meeting 6', content:'10-04-2015.pdf'},
    { title:'Group Meeting 7', content:'17-04-15.pdf'}
  ];
});