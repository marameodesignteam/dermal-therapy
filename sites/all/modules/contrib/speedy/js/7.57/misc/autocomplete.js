(function($){Drupal.behaviors.autocomplete={attach:function(context,settings){var acdb=[];$("input.autocomplete",context).once("autocomplete",function(){var uri=this.value;if(!acdb[uri]){acdb[uri]=new Drupal.ACDB(uri)}var $input=$("#"+this.id.substr(0,this.id.length-13)).attr("autocomplete","OFF").attr("aria-autocomplete","list");$($input[0].form).submit(Drupal.autocompleteSubmit);$input.parent().attr("role","application").append($('<span class="element-invisible" aria-live="assertive"></span>').attr("id",$input.attr("id")+"-autocomplete-aria-live"));new Drupal.jsAC($input,acdb[uri])})}};Drupal.autocompleteSubmit=function(){return $("#autocomplete").each(function(){this.owner.hidePopup()}).length==0};Drupal.jsAC=function($input,db){var ac=this;this.input=$input[0];this.ariaLive=$("#"+this.input.id+"-autocomplete-aria-live");this.db=db;$input.keydown(function(event){return ac.onkeydown(this,event)}).keyup(function(event){ac.onkeyup(this,event)}).blur(function(){ac.hidePopup();ac.db.cancel()})};Drupal.jsAC.prototype.onkeydown=function(input,e){if(!e){e=window.event}switch(e.keyCode){case 40:this.selectDown();return false;case 38:this.selectUp();return false;default:return true}};Drupal.jsAC.prototype.onkeyup=function(input,e){if(!e){e=window.event}switch(e.keyCode){case 16:case 17:case 18:case 20:case 33:case 34:case 35:case 36:case 37:case 38:case 39:case 40:return true;case 9:case 13:case 27:this.hidePopup(e.keyCode);return true;default:if(input.value.length>0&&!input.readOnly){this.populatePopup()}else{this.hidePopup(e.keyCode)}return true}};Drupal.jsAC.prototype.select=function(node){this.input.value=$(node).data("autocompleteValue");$(this.input).trigger("autocompleteSelect",[node])};Drupal.jsAC.prototype.selectDown=function(){if(this.selected&&this.selected.nextSibling){this.highlight(this.selected.nextSibling)}else if(this.popup){var lis=$("li",this.popup);if(lis.length>0){this.highlight(lis.get(0))}}};Drupal.jsAC.prototype.selectUp=function(){if(this.selected&&this.selected.previousSibling){this.highlight(this.selected.previousSibling)}};Drupal.jsAC.prototype.highlight=function(node){if(this.selected){$(this.selected).removeClass("selected")}$(node).addClass("selected");this.selected=node;$(this.ariaLive).html($(this.selected).html())};Drupal.jsAC.prototype.unhighlight=function(node){$(node).removeClass("selected");this.selected=false;$(this.ariaLive).empty()};Drupal.jsAC.prototype.hidePopup=function(keycode){if(this.selected&&(keycode&&keycode!=46&&keycode!=8&&keycode!=27||!keycode)){this.select(this.selected)}var popup=this.popup;if(popup){this.popup=null;$(popup).fadeOut("fast",function(){$(popup).remove()})}this.selected=false;$(this.ariaLive).empty()};Drupal.jsAC.prototype.populatePopup=function(){var $input=$(this.input);var position=$input.position();if(this.popup){$(this.popup).remove()}this.selected=false;this.popup=$('<div id="autocomplete"></div>')[0];this.popup.owner=this;$(this.popup).css({top:parseInt(position.top+this.input.offsetHeight,10)+"px",left:parseInt(position.left,10)+"px",width:$input.innerWidth()+"px",display:"none"});$input.before(this.popup);this.db.owner=this;this.db.search(this.input.value)};Drupal.jsAC.prototype.found=function(matches){if(!this.input.value.length){return false}var ul=$("<ul></ul>");var ac=this;for(key in matches){$("<li></li>").html($("<div></div>").html(matches[key])).mousedown(function(){ac.hidePopup(this)}).mouseover(function(){ac.highlight(this)}).mouseout(function(){ac.unhighlight(this)}).data("autocompleteValue",key).appendTo(ul)}if(this.popup){if(ul.children().length){$(this.popup).empty().append(ul).show();$(this.ariaLive).html(Drupal.t("Autocomplete popup"))}else{$(this.popup).css({visibility:"hidden"});this.hidePopup()}}};Drupal.jsAC.prototype.setStatus=function(status){switch(status){case"begin":$(this.input).addClass("throbbing");$(this.ariaLive).html(Drupal.t("Searching for matches..."));break;case"cancel":case"error":case"found":$(this.input).removeClass("throbbing");break}};Drupal.ACDB=function(uri){this.uri=uri;this.delay=300;this.cache={}};Drupal.ACDB.prototype.search=function(searchString){var db=this;this.searchString=searchString;searchString=searchString.replace(/^\s+|\.{2,}\/|\s+$/g,"");if(searchString.length<=0||searchString.charAt(searchString.length-1)==","){return}if(this.cache[searchString]){return this.owner.found(this.cache[searchString])}if(this.timer){clearTimeout(this.timer)}this.timer=setTimeout(function(){db.owner.setStatus("begin");$.ajax({type:"GET",url:db.uri+"/"+Drupal.encodePath(searchString),dataType:"json",success:function(matches){if(typeof matches.status=="undefined"||matches.status!=0){db.cache[searchString]=matches;if(db.searchString==searchString){db.owner.found(matches)}db.owner.setStatus("found")}},error:function(xmlhttp){Drupal.displayAjaxError(Drupal.ajaxError(xmlhttp,db.uri))}})},this.delay)};Drupal.ACDB.prototype.cancel=function(){if(this.owner)this.owner.setStatus("cancel");if(this.timer)clearTimeout(this.timer);this.searchString=""}})(jQuery);
