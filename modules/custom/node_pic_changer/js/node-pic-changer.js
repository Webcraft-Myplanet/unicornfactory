/**
 * @file
 * UI handling for the Profile Pic Changer module
 */

(function ($) {
  Drupal.NodePicChanger = Drupal.NodePicChanger || {};

  Drupal.NodePicChanger.pic_updated = function(context, params) {
    var new_img = params['argument'];
    $('.node-picture img').attr('src', new_img);
  };

  Drupal.behaviors.NodePicChanger = {
    attach: function() {
      // change the title so the tooltip text indicates what to do
      $('.node-picture img').attr('title', Drupal.t("Click on the image to change your profile picture"));
    }
  };

  Drupal.ajax.prototype.commands.pic_updated = Drupal.NodePicChanger.pic_updated;

})(jQuery);
