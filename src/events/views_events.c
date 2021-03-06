/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** views_events functions
*/

# include "rpg.h"

void views_events(rpg_t *rpg, sfEvent *event)
{
	void (*tab[])(rpg_t *, sfEvent *) = {
		NULL, NULL, ev_run, NULL, NULL, NULL, NULL, NULL, NULL,
		ev_selection, NULL, NULL, NULL, ev_inventory, ev_skills,
		ev_quests
	};

	if ((*tab[rpg->state]) == NULL)
		return;

	(*tab[rpg->state])(rpg, event);
}
