angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Coding Style Guide', content:'Coding-Style.pdf' },
    { title:'Requirements and Specifications', content:'Requirements-and-Specifications.pdf'}
  ];
});