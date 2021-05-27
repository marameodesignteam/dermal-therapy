(function($) {
  // Check for window load.
  $(window).load(function() {
    // For standard image lazy loading
    $('.context-lazy-load').each(function() {
      var delay = $(this).attr('delay');
      var lazy_load_div = $(this);
      var cur_div = $(this);
      if(!cur_div.width()) {
        while(!cur_div.width()) {
          //find parent div width
          cur_div = cur_div.parent();
        }
        console.log('Div : ' +lazy_load_div.attr('class'));
        console.log('final width : '  + cur_div.width());
        lazy_load_div.css('width', cur_div.width());
      }

      cur_div = $(this);
      if(!cur_div.height()) {
        while(!cur_div.height()) {
          //find parent div width
          cur_div = cur_div.parent();
        }
        console.log('Div : ' +lazy_load_div.attr('class'));
        console.log('final height : '  + cur_div.height());
        lazy_load_div.css('height', cur_div.height());
      }
      lazy_load_div.find('img').each(function() {
        $(this).removeClass('hidden-loader-temp');
      });

      if(lazy_load_div.attr('set_on_scroll')==0 || (lazy_load_div.attr('set_on_scroll')==1 && isInViewport(lazy_load_div) && !lazy_load_div.hasClass('in-view-port'))) {
        lazy_load_div.addClass('in-view-port');
        lazy_load_div.find('img').each(function() {
          console.log('window load', $(this).attr('org-src'));
        });
        setTimeout(function() {
          lazy_load_div.find('img').each(function() {
            $(this).hide();
            var orgsrc = $(this).attr('org-src');
            if (orgsrc) {
              $(this).attr('src', orgsrc);
              $pardiv = $(this).closest('.context-lazy-load');
              $pardiv.removeClass('context-lazy-load');
              $pardiv.removeAttr('delay');
              $pardiv.removeAttr('set_on_scroll');
              $pardiv.css('position','');
              $pardiv.css('height', '');
              $pardiv.css('width', '');
              $pardiv.find('.context-img-loader-div').remove();
              $(this).fadeIn();
            }
          })
        }, delay);
      }
      
    });

    // For background image lazy loading
    $('.context-lazy-background').each(function() {
      var delay = $(this).attr('delay');
      var lazy_load_div = $(this);
      setTimeout(function() {
        lazy_load_div.parent().find('.context-lazy-background').each(function() {
          var orgsrc = $(this).attr('org-src').split(",");
          var arrayLength = orgsrc.length;
          for (var i = 0; i < arrayLength; i++) {
            $prop = orgsrc[i].split("::");
            $(this).css($prop[0],"url("+$prop[1]+")");
          }
        });
      } , delay);
    });
  });

  // Check for window scroll.
  $(window).scroll(function () {
    $('.context-lazy-load').each(function() {
      var delay = $(this).attr('delay');
      var lazy_load_div = $(this);
      var cur_div = $(this);
      if(lazy_load_div.attr('set_on_scroll')==0 || (lazy_load_div.attr('set_on_scroll')==1 && isInViewport(lazy_load_div) && !lazy_load_div.hasClass('in-view-port'))) {
        lazy_load_div.addClass('in-view-port');
        lazy_load_div.find('img').each(function() {
          console.log('window scroll', $(this).attr('org-src'));
        });
        setTimeout(function() {
          lazy_load_div.find('img').each(function() {
            $(this).hide();
            var orgsrc = $(this).attr('org-src');
            if (orgsrc) {
              $(this).attr('src', orgsrc);
              $pardiv = $(this).closest('.context-lazy-load');
              $pardiv.removeClass('context-lazy-load');
              $pardiv.removeAttr('delay');
              $pardiv.removeAttr('set_on_scroll');
              $pardiv.css('position','');
              $pardiv.css('height', '');
              $pardiv.css('width', '');
              $pardiv.find('.context-img-loader-div').remove();
              $(this).fadeIn();
            }
          })
        }, delay);
      }
    });
    
  });

  // Check for automatic div movement.
  setInterval(function(){ 
    console.log('automated script fired');
    $(".context-lazy-load").each(function(){
      var delay = jQuery(this).attr('delay');
      var lazy_load_div = jQuery(this);
      console.log('auto delay' + delay);
      console.log('auto scroll start' + lazy_load_div.attr('set_on_scroll'));
      
      var cur_div = jQuery(this);
      if(lazy_load_div.attr('set_on_scroll')==1 && isInViewport(lazy_load_div) && !lazy_load_div.hasClass('in-view-port')) {
        lazy_load_div.addClass('in-view-port');
        console.log('auto scroll found' + lazy_load_div.attr('set_on_scroll'));
        lazy_load_div.find('img').each(function() {
          console.log('window scroll', jQuery(this).attr('org-src'));
        });
        setTimeout(function() {
          lazy_load_div.find('img').each(function() {
            jQuery(this).hide();
            var orgsrc = jQuery(this).attr('org-src');
            if (orgsrc) {
              jQuery(this).attr('src', orgsrc);
              $pardiv = jQuery(this).closest('.context-lazy-load');
              $pardiv.removeClass('context-lazy-load');
              $pardiv.removeAttr('delay');
              $pardiv.removeAttr('set_on_scroll');
              $pardiv.css('position','');
              $pardiv.css('height', '');
              $pardiv.css('width', '');
              $pardiv.find('.context-img-loader-div').remove();
              jQuery(this).fadeIn();
            }
          })
        }, delay);
      }

    }); 
  },100);

})(jQuery);

// Method to check element in view port.
function isInViewport(jelem) {
  var elem = jelem[0];
  var bounding = elem.getBoundingClientRect();
  if( (bounding.top < 0 && bounding.bottom >0 ) || (bounding.top > 0 && bounding.top <(window.innerHeight || document.documentElement.clientHeight))) {
    if((bounding.left < 0 && bounding.right >0) || (bounding.left > 0 && bounding.left < (window.innerWidth || document.documentElement.clientWidth)))
      return true;
    else
      return false;
  } else
    return false;
};

