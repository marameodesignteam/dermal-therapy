(function($) {
  $(window).load(function() {
    //alert(1);
    // For image loading during page load
    $('.context-scroll-load').each(function() {
      if(isInViewport($(this))) {
        $(this).find('img').each(function() {
          var orgsrc = $(this).attr('org-scroll-src');
          if (orgsrc) {
            $(this).attr('src', orgsrc);
            console.log('window load : ' + $(this).attr('org-scroll-src'));
            $(this).removeAttr('org-scroll-src');
            $pardiv = $(this).closest('.context-scroll-load');
            $pardiv.removeClass('context-scroll-load');
          }
        });
      }
    });
    // For image loading during page scroll
   $(window).scroll(function () {
      $('.context-scroll-load').each(function() {
        if(isInViewport($(this))) {
          $(this).find('img').each(function() {
            var orgsrc = $(this).attr('org-scroll-src');
            if (orgsrc) {
              $(this).attr('src', orgsrc);
              console.log('window scroll : ' + $(this).attr('org-scroll-src'));
              $(this).removeAttr('org-scroll-src');
              $pardiv = $(this).closest('.context-scroll-load');
              $pardiv.removeClass('context-scroll-load');               
            }
          });
        }
      });
   });

 });  

})(jQuery);



function isInViewport(jelem) {
  var elem = jelem[0];
  var bounding = elem.getBoundingClientRect();
  //console.log(bounding.top + ' : '+bounding.left );
  //console.log(bounding.bottom + ' : ' + window.innerHeight );
  //console.log(bounding.right + ' : ' + window.innerWidth);

  if( (bounding.top < 0 && bounding.bottom >0 ) || (bounding.top > 0 && bounding.top <(window.innerHeight || document.documentElement.clientHeight))) {
    if((bounding.left < 0 && bounding.right >0) || (bounding.left > 0 && bounding.left < (window.innerWidth || document.documentElement.clientWidth)))
      return true;
    else
      return false;
  } else
    return false;
};

