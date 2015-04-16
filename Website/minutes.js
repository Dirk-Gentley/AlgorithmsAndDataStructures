angular.module('ui.bootstrap.demo', ['ui.bootstrap'])
.constant('minuetsConfig', {
        fullHeight: true
    })
angular.module('ui.bootstrap.demo').controller('minuets', function ($scope) {
  $scope.oneAtATime = true;

  $scope.groups = [
    {
      title: 'Dynamic Group Header - 1',
      content: 'meeting-minutes-02-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 2',
      content: 'meeting-minutes-06-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 1',
      content: 'meeting-minutes-02-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 2',
      content: 'meeting-minutes-06-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 1',
      content: 'meeting-minutes-02-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 2',
      content: 'meeting-minutes-06-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 1',
      content: 'meeting-minutes-02-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 2',
      content: 'meeting-minutes-06-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 1',
      content: 'meeting-minutes-02-03-2015.pdf'
    },
    {
      title: 'Dynamic Group Header - 2',
      content: 'meeting-minutes-06-03-2015.pdf'
    }
  ];
  });