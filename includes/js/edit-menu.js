jQuery(function($){
	
	var menu = $('ul.edit-menu');
	if(menu.length > 0){
		
		// create new menu item form
		$('<div id="edit-menu-new-item-form"></div>').html('Menu Item Label: <input type="text" id="edit-menu-item-label" value="" />').hide().appendTo('body');
		
		// setup events
		menu.hover(function(event){
						
			// create ghost item
			$('> li:first-child', this).not('li.edit-menu-ghost-item').clone().css({opacity: 0.5}).addClass('edit-menu-ghost-item').removeClass('current_page_item').hover(function() {
				$(this).css('opacity', 1);
			}, function(){
				$(this).css('opacity', 0.5);
			}).click(function(){
				
				var ghostItem = $('li.edit-menu-ghost-item', menu).removeClass('edit-menu-ghost-item');				
				
				$('#edit-menu-new-item-form').dialog({
					modal: true,
					buttons: {
						'Add New Item': function() {
							$(ghostItem).css('opacity', 1).unbind().children('a').text($('#edit-menu-item-label', this).val());
							$(this).dialog('close');							
						},
						'Cancel': function() {
							$(ghostItem).addClass('edit-menu-ghost-item');
							$(menu).trigger('mouseleave');
							$(this).dialog('close');
						}
					},
				});
				
				event.preventDefault();
				return false;								
			}).appendTo(this).children('a').text('New Item');
			
		}, function(){
			
			// handle mouse leave
			$('.edit-menu-ghost-item', this).remove();
		});
	}	
});