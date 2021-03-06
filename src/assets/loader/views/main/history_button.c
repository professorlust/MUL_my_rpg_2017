/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** history button configuration
*/

# include "rpg.h"

static sfIntRect set_rect(sfTexture *texture)
{
	sfIntRect rec;

	rec.top = 0;
	rec.left = 0;
	rec.height = (sfTexture_getSize(texture).y / 7);
	rec.width = (sfTexture_getSize(texture).x / 6);

	return (rec);
}

void configure_main_history_button(rpg_t *rpg)
{
	button_t conf;
	assets_t *asset = get_asset(rpg, "booksheet");
	sfIntRect rec = { 0, 0, 195, 200 };

	if (!asset || asset->texture == NULL)
		return;
	asset->rec = set_rect(asset->texture);
	conf.name = "btn_history";
	conf.pos.x = 875;
	conf.pos.y = 720;
	conf.onClick = cb_void_action;
	conf.onHover = cb_play_sound1;
	conf.onStart = cb_goto_history_view;
	conf.state = gameWait;
	conf.sprite = NULL;
	conf.rect = rec;
	conf.next = NULL;
	sfSprite_setTextureRect(asset->sp, asset->rec);
	add_button(rpg, conf);
}
