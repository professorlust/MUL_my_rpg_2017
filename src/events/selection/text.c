/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** text selection events
*/

# include "rpg.h"

void perform_text_entered(rpg_t *rpg, sfTextEvent type)
{
	int i = 0;

	if ((type.unicode > 47 && type.unicode < 128)) {
		while (rpg->player->name[i])
			i++;
		if (i < 18) {
			rpg->player->name[i] = ((char)type.unicode);
		}
	}
}

void perform_backspace(rpg_t *rpg, sfTextEvent type)
{
	int i = 18;

	if (type.unicode == 8 && my_strlen(rpg->player->name) > 0) {
		while (!rpg->player->name[i])
			i--;
		rpg->player->name[i] = 0;
		sfText_setString(rpg->text, rpg->player->name);
	}
}

bool ev_selection_text(rpg_t *rpg, sfEvent *event)
{
	sfTextEvent type;
	sfVector2f pos = { 610, 732 };
	sfColor color = sfColor_fromRGB(16, 17, 16);

	if (event->type == sfEvtTextEntered) {
		type = event->text;
		perform_text_entered(rpg, type);
		perform_backspace(rpg, type);
	}

	sfText_setCharacterSize(rpg->text, 60);
	sfText_setColor(rpg->text, color);
	sfText_setPosition(rpg->text, pos);
	sfText_setString(rpg->text, rpg->player->name);

	return (true);
}
