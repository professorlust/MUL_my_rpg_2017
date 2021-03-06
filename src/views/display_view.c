/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** array of pointers of the function representating the states of the game
*/

# include "rpg.h"

void display_view(rpg_t *rpg)
{
	void (*tab[])(rpg_t *) = {
		NULL,
		main_view,
		play_view,
		NULL,
		pause_view,
		settings_view,
		credits_view,
		history_view,
		NULL,
		select_view,
		NULL,
		game_load_view,
		NULL,
		inventory_view,
		skills_view,
		quests_view
	};

	(*tab[rpg->state])(rpg);
}
