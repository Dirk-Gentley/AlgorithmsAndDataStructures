angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Coding Style Guide', content:'Coding StyleV2.docx' },
    { title:'Requirements and Specifications', content:'Requirements and Specifications V1.2_Jim.docx'}
  ];
});