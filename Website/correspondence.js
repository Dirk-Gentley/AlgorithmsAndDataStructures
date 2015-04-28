angular.module('ui.bootstrap.demo', ['ui.bootstrap']);
angular.module('ui.bootstrap.demo').controller('TabsDemoCtrl', function ($scope, $window) {
  $scope.tabs = [
    { title:'Wednesday 01/04/2015', content:"We have a week long break coming up, and though it would be amazing to spend the time working on our amazing project, it just isn't feasible due to work and other commitments. We should still meet Friday week though as we have two tasks ahead of us. ​The first project milestone is the presentation which will happen on Monday April 20th. I need everyone to forward me their availability for that date by Monday April 6th. I have a second draft of the slides, so we can practice the presentation We should have a full dress rehearsal for Gene to offer some constructive criticism, hopefully on Friday April 17th. I plan to have the requirements properly documented and cataloged We already have a good handle on the functional and non functional requirements If we break them down into sub-categories, they amount to about 50-60 so far It's a horrible job, I know, so if we all do it together it should only take a few hours We need some "+"shall not's"+" and some "+"should not's"+" We need to finalize the coding style guide We already have some snippits of sample code We already have a prototype "+"project skeleton"+" on the repository The sooner we get the documentation up to scratch, the sooner we can start pumping out prototypes! I have been in touch with Dr Xia regarding two previous attempts at a similar project.  He was even kind enough to openly discuss relative, general marks and  where one of the projects went wrong, and where the other went particularly well. On Thursday morning I am going to pick up the documentation and binaries for those projects so we can perhaps get some idea of what to do, and what not to do. Just an aside -Gene mentioned the previous project, Luke pointed me to Dr Xia, and my inquiries have led me to believe this is all well above board. Thanks everyone. Happy Easter!"},
    { title:'Friday 10/04/2015', content:"Hey everyone. In the interest of keeping you all informed, we have three key deliverables due in one week. ​Project Diary Plan Presentation Requirements Specification They are all due on Monday 20th.  This date marks a major project milestone for the following reasons: ​The above deliverables represent 15% of our total possible mark The above deliverables set a weak upper bound for our overall mark.  Read that point again and ponder for a moment. I have attached our requirements specification as it stands.  Jim is working on our non-functional requirements which have yet to be added to the document. Further, there are three key parts missing ​Risks and risk management <-- I will do these Because our target audience includes secondary students, we need to address certain criteria in accordance with keeping an Australian Classification Board rating of G. <-- Perhaps best suited to Jim? Should nots. Though we discussed them, we as yet don't have anything listed that our application should not do or conform to. There is one further thing we all need to be careful of.  Our system architecture is a combination of MVC, and state driven design.  Although there is very little documentation out there on the latter, it's arguably the best way to approach our project -it's the way RGP games are designed ...you know the ones where you spend as much time in the menu equipping items as you do running around the dungeons?  It's how Dwarf Fortress is programmed.  The thing is, we can't really sight these as examples. Please take a look over my drawing of the application structure in the requirements documentation.  If you have any questions, or can offer a solution on how to better represent it, let us all know! Perhaps Gene can point us in the right direction there? Finally some housekeeping. Update your personal diaries after today's work! Pete, can you work on a group diary for us please? I really want this these tasks finished before next Friday so we can work on the presentation and nothing else.  If we manage our time properly ...as we have been doing ...we won't need to spend any nights in the lab! Thanks again everyone, Ben :)"},
    { title:'Friday 15/04/2015', content:"Hey all, So I just found out the diaries are due Friday, 7:00pm -it's only the presentation that was delayed. This includes all our individual diaries, and the group diary/meeting minutes. Please take time to ensure your diaries are up to scratch, that they include all the work you have done so far, and are somewhat presentable. We should spend a little time on Friday going through the meeting minutes/group diary. Can you please reply when you've read this email :p Regards, Ben"}

  ];
});