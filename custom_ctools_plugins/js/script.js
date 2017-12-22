(function($) {
  Drupal.behaviors.customCtoolsPlugins = {
    attach: function(context, settings) {
        
        setInterval(showContent, 1000);

        function showContent(){
            
            var minutes = 1000 * 60;
            var dadte = new Date();
            var time = dadte.getTime();
            var currentTime = Math.round(time / minutes);
            
            if (currentTime % 2 == 0) {
                $('#content', context).hide();
            } else {
                $('#content', context).show();
            }
        }
        
    }
  };
})(jQuery);