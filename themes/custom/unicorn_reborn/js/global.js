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
    }
  };
})(jQuery);
