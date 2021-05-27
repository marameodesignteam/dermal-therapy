(function($){
  $(function(){
    if($('input[id^=edit-reactions-plugins-lazy-load-dom-elements-element-type]:checked').val()=='1')
      $('#custom-element-wrapper').hide();
    else
      $('#custom-element-wrapper').show();

     $('input[id^=edit-reactions-plugins-lazy-load-dom-elements-element-type]').click(function(){
       if($(this).val()==1)
         $('#custom-element-wrapper').fadeOut();
       else
         $('#custom-element-wrapper').fadeIn();
     })

 });
})(jQuery);
