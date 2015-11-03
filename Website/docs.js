angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Coding Style Guide', content:'Documents/Coding-StyleV2.pdf' },
    { title:'Requirements and Specifications', content:'Documents/Requirements-Specifications.pdf'},
    { title:'Programmers Guide', content:'Documents/Programmers-Guide.pdf'}
  ];
});