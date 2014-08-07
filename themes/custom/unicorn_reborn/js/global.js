/**
 * @file
 * Global javascript
 */

/**
 * Responsive Scripts
 */
(function ($) {
  var mobile_breakpoint = 550;
  var landscape_breakpoint = 680;
  var tablet_breakpoint = 760;

  Drupal.behaviors.responiveFunctions = {
    // This function will return true if in mobile version.
    is_mobile: function() {
      var viewport_width = $(window).width();
      var viewport_height = $(window).height();

      if (viewport_width <= mobile_breakpoint) {
        return true;
      }
      // iPhone 5
      else if (viewport_width == 568 && viewport_height == 208 && this.is_ios()) {
        return true;
      }
      else {
        return false;
      }
    },
    is_landscape: function() {
      var viewport_width = $(window).width();

      if (viewport_width <= landscape_breakpoint) {
        return true;
      }
      else {
        return false;
      }
    },
    is_tablet: function() {
      var viewport_width = $(window).width();

      if (viewport_width <= tablet_breakpoint) {
        return true;
      }
      else {
        return false;
      }
    },
    is_ios: function() {
      var agent = navigator.userAgent.toLowerCase(),
        is_ios = agent.indexOf('iphone') !== -1 || agent.indexOf('ipad') !== -1;
      if(is_ios) {
        return true;
      }
      else {
        return false;
      }
    },
    is_ipad: function() {
      var agent = navigator.userAgent.toLowerCase(),
        is_ios = agent.indexOf('ipad') !== -1;
      if(is_ios) {
        return true;
      }
    },
    is_front: function() {
      if ($('body').hasClass('front')) {
        return true;
      }
      else {
        return false;
      }
    }
  }
})(jQuery);

/**
 * Content Body
 */
(function ($) {
  Drupal.behaviors.globalJS = {
    attach: function (context, settings) {
      var commentP= $('.comment .content .field-item');

      commentP.each(function(){
        if ($(this).children().length < 2){
          $(this).parents('div.content').siblings('.expand-button').hide();
        }
      });

      $('.expand-button').click(function(){
        $(this).parent().find('div.bounty-desc, div.content').toggleClass('trunk');
        $(this).text($(this).text() == "Less" ? "More" : "Less");
      });

      // Dropdown Selection

      $(".filter li, span.filter-button").on("click",function(){
        var status = $(this).text().toLowerCase();

        switch(status) {

          case "my bounties" :

            $(".all").fadeOut(300,function(){
              $(".bounty-user").fadeIn(500);
            });
          break;

          case "all" :

            $(".all, .bounty-user").fadeOut(300,function(){
              $(".all").fadeIn(500);
            });
          break;

          case "open" :

            $(".all, .bounty-user").fadeOut(300,function(){
              $(".bounty-open").fadeIn(500);
            });
          break;

          case "in progress" :

            $(".all, .bounty-user").fadeOut(300,function(){
              $(".bounty-in-progress").fadeIn(500);
            });
          break;

          case "postponed" :

            $(".all, .bounty-user").fadeOut(300,function(){
              $(".bounty-postponed").fadeIn(500);
            });
          break;

          case "closed" :

            $(".all, .bounty-user").fadeOut(300,function(){
              $(".bounty-closed").fadeIn(500);
            });
          break;

          default :
            $(".all").fadeOut(300,function(){
              $(".bounty-user").fadeIn(500);
            });
        } // end switch

      }); // end $
    } // end attach
  }; // end behaviours
})(jQuery);




