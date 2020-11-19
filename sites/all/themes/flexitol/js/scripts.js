//set active class on sidebar menu -  product category page

(function($) {
  $(document).ready(function() {

    var product_nav = $('[id*="block-views-products-block"]');

    if (product_nav.length > 0) {

      var title = product_nav.find("a.active").parent();

      title.addClass("category-active")

      title.nextAll().each(function(i) {

        if ($(this).is("h3")) {
          return false;
        }

        $(this).addClass("category-active")

      });

    }

  });

})(jQuery);


(function($) {
  $(document).ready(function() {
    $(".node-homepage-featured-content .group-hover").on("click", function() {

      if ($(window).width() < 992) {
        var location = typeof $(this).find(".btn").attr("href") == "string" ? $(this).find(".btn").attr("href") : $(this).parent().find("h2 a").attr("href");

        window.location = location;
      }
    })
  })
})(jQuery);


(function($) {
  $(document).ready(function() {
    $(".navbar-nav .first > *").on("click", function() {

      if ($(window).width() < 769) {
        window.location = "/products";
      }
    })
  })
})(jQuery);

/*
Wait until we can see the bottom - then set to fixed.

Then, if top = bottom of above - position absolute
*/

(function($) {
  $(document).ready(function() {



    $(".sblock").hide();
    $('.searchicon').click(function() {
      $(this).siblings(".sblock").slideToggle(400)
        .siblings('.sblock:visible').slideUp(400);


      /*
        $(this).siblings('.sblock').togg"leClass('visible-lg');
        $(this).siblings('.sblock').toggleClass('visible-md');
        $(this).siblings('.sblock').toggleClass('visible-sm');
        $(this).siblings('.sblock').toggleClass('heightsb');

         $('.header-fluid').toggleClass('heightheader');
         */
    });
  });
})(jQuery);

(function($) {
  $(document).ready(function() {
    $('.dropdown-toggle').dropdown();
  });
})(jQuery);


if (jQuery(window).width() >= 768) {
  function CheckMega() {

    (function($) {
      //Function for bottom-fixed sidebar image
      function checkOffset() {
        var bottom = jQuery('#block-views-conditions-menu-block').offset().top + jQuery('#block-views-conditions-menu-block').outerHeight(true);
        if ($('#block-views-8a88aca1c0589e095165a67e4cdec26f').offset().top + $('#block-views-8a88aca1c0589e095165a67e4cdec26f').height() >=
          $('.container-fluid.footer-fluid').offset().top - 20)
          $('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('position', 'absolute');
        if ($(document).scrollTop() + window.innerHeight < $('.container-fluid.footer-fluid').offset().top)
          $('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('position', 'fixed');
        $('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('bottom', '0px');

        if ($('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('position') == 'absolute') {
          $('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('bottom', '0px');
        } else if ($('#block-views-8a88aca1c0589e095165a67e4cdec26f').offset().top <= bottom) {
          //$('#block-views-8a88aca1c0589e095165a67e4cdec26f').css('bottom', 'initial !important');
          $('#block-views-8a88aca1c0589e095165a67e4cdec26f').attr('style', 'bottom:initial !important');

        }




      }

      $(document).scroll(function() {

        checkOffset();
      });
    })(jQuery);
  }


  //Checking if conditions picture is in view
  jQuery(function() {

    jQuery('#block-views-8a88aca1c0589e095165a67e4cdec26f').bind('inview', function(event, isInView, visiblePartX, visiblePartY) {
      if (isInView) {
        // element is now visible in the viewport

        if (visiblePartY == 'both') {
          // top part of element is visible
          jQuery('#block-views-8a88aca1c0589e095165a67e4cdec26f').unbind('inview');
          CheckMega();

        } else if (visiblePartY == 'top') {
          // top part of element is visible
        } else if (visiblePartY == 'bottom') {

        }

      } else {
        // element has gone out of viewport

      }
    });
  });

}
//resize fixed image (Conditions)
(function($) {
  $(window).on('resize', function() {

    var new_width = $('.region.region-sidebar-first').width();
    $('#block-views-8a88aca1c0589e095165a67e4cdec26f img').css('max-width', new_width);
  });
})(jQuery);




(function($) {
  $(document).on("ready", function() {

    $('.region-sidebar-first, .content-column', '#content-wrapper>.container>.row').matchHeight();
    //$('#widget-links ul').matchHeight({target: $('.widget-side .view-content')});

  });

})(jQuery);

(function($) {

  $(document).on("ready", function() {
    function explodeWidth() {
      var browserWidth = $(document).width();
      var wrapWidth = $('.container').width();

      var margin = ((browserWidth - wrapWidth) / 2);
      $('.fullwidth').css('margin-left', -margin).css('margin-right', -margin);
      $('.efficacy').css('margin-left', -margin).css('margin-right', -margin);
      $('.healthcare-body').css('margin-left', -margin).css('margin-right', -margin);
    }
    explodeWidth();
    $(window).resize(explodeWidth);
  });
})(jQuery);
/*
(function($){
$(window).scroll(function(){
    $(".view.view-conditions-product-reference.view-id-conditions_product_reference.view-display-id-block").css("top",Math.max(0,650-$(this).scrollTop()));
});
})(jQuery);
*/

//Function to dynamically set height of main menu blocks
(function($) {
  if ($(window).width() < 768) {
    $(window).load(function() {
      for (i = 1; i < 4; i++) {
        //store current height of block
        var curheight = $("#views-bootstrap-grid-1 .row .col.col-sm-4:nth-child(" + i + ") .node-homepage-featured-content").height()
        //current height of hover copy
        var copyheight = $("#views-bootstrap-grid-1 .row .col.col-sm-4:nth-child(" + i + ") .node-homepage-featured-content .field-name-field-hfc-hover-text span").outerHeight(true)
        //set new block height to copy height + block height
        $("#views-bootstrap-grid-1 .row .col.col-sm-4:nth-child(" + i + ") .node-homepage-featured-content").height(curheight + copyheight);
      }
    });
  }
})(jQuery);

//Function to change the class for the products

(function($) {
  Drupal.behaviors.productcatclass = {
    attach: function(context, settings) {
      if ($('body').hasClass('productcat')) {
        if ($('.view-id-taxonomy_term_clone .view-content').children().length > 1) {
          $('.view-id-taxonomy_term_clone .view-content').children('.views-row').each(function() {

            $(this).removeClass('col-sm-12');
            $(this).addClass('col-sm-6');

          });

        } else {
          $('.view-id-taxonomy_term_clone .view-content').children('.views-row').each(function() {

            $(this).removeClass('col-sm-12');
            $(this).addClass('col-sm-12');

          });

        }

      }
    }
  };
}(jQuery));

(function($) {

  $(document).on("ready", function() {
    if ($('body').hasClass('domain-singapore-dt')) {
      $('span.footer-icon.footer-icon-insta').addClass('hidden');
      $('admin-menu section#block-flexitol-global-social-footer-links-block a:nth-child(2)').attr("href", "https://www.facebook.com/dermaltherapysg");
      $('section#block-flexitol-global-social-footer-links-block a:nth-child(1)').attr("href", "https://www.facebook.com/dermaltherapysg");

    }

    $('.dropdown-toggle').click(function() {
      if (jQuery('.hamburger-menu').height() < 10) {
        var location = $(this).attr('href');
        window.location.href = location;
        return false;
      }
    });
  });

})(jQuery);


(function($) {

  $(document).on("ready", function() {

    var hash = window.location.hash.substr(1);

    if (hash == "video") {

      var slider = $('#product-gallery').data('flexslider');

      if (slider.length > 0) {

        //check if there is a video

        var index = slider.find(".video").index();

        if (index > 0) {

          var animationSpeed = slider.vars.animationSpeed; //save animation speed to reset later
          slider.vars.animationSpeed = 0;
          slider.flexAnimate(index); //position index for desired slide
          slider.vars.animationSpeed = animationSpeed;

          //scroll to video
          $('html, body').animate({
            scrollTop: $("#product-gallery").offset().top - 20
          }, 800);

        }
      }

    }
  });

})(jQuery);
