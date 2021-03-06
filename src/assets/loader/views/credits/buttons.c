/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** credits_buttons configuration
*/

# include "rpg.h"

void configure_credits_return_button(rpg_t *rpg)
{
	button_t conf;
	sfIntRect rec = { 265, 0, 265, 80 };
	sfTexture *texture = get_texture(rpg, "buttons");

	conf.name = "btn_return";
	conf.pos.x = 320;
	conf.pos.y = 885;
	conf.onClick = cb_click_action;
	conf.onHover = cb_hover_action;
	conf.onStart = cb_return_action;
	conf.state = gameOnCredits;
	conf.sprite = sfSprite_create();
	sfSprite_setTexture(conf.sprite, texture, sfFalse);
	sfSprite_setTextureRect(conf.sprite, rec);
	sfSprite_setPosition(conf.sprite, conf.pos);
	conf.rect = rec;
	conf.next = NULL;
	add_button(rpg, conf);
}
