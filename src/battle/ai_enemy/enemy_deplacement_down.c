/*
** EPITECH PROJECT, 2018
** enemy_deplacement_anim
** File description:
** rpg
*/

#include "rpg.h"

static void draw_anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->fight[battle->id]->enemy[x]->rec.left += 64;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
	draw_all(rpg);
	display_hero(rpg, battle);
	display_other_enemy(rpg, battle, x);
	sfRenderWindow_drawSprite(rpg->win,
		battle->fight[battle->id]->enemy[x]->form, NULL);
	sfRenderWindow_display(rpg->win);
}

static void anim(rpg_t *rpg, battle_t *battle, int x)
{
	sfVector2f pos = sfSprite_getPosition(
		battle->fight[battle->id]->enemy[x]->form);

	for (int i = 0; i < 9;) {
		sfClock_restart(battle->clock);
		battle->time = sfTime_Zero;
		while (sfTime_asSeconds(battle->time)
		< sfTime_asSeconds(sfSeconds(0.08)))
			battle->time = sfClock_getElapsedTime(battle->clock);
		pos.y += 1 * (B_Y / 8);
		sfSprite_setPosition(
			battle->fight[battle->id]->enemy[x]->form, pos);
		draw_anim(rpg, battle, x);
		i++;
	}
	sfRenderWindow_clear(rpg->win, sfBlack);
	battle->fight[battle->id]->enemy[x]->rec.left = 0;
	sfSprite_setTextureRect(
		battle->fight[battle->id]->enemy[x]->form,
		battle->fight[battle->id]->enemy[x]->rec);
}

bool enemy_go_down(rpg_t *rpg, battle_t *battle, int x,
		sfVector2f pos)
{
	sfVector2f hero = {battle->hero->pos.x, battle->hero->pos.y};
	int b = hero.y - pos.y;
	int c = pos.y;
	int d = pos.x;

	if (pos.y <= 8 && b > 0 && battle->map[c + 1][d] == 0) {
		pos.y += 1;
		battle->fight[battle->id]->enemy[x]->pos.y += 1;
		battle->fight[battle->id]->enemy[x]->rec.top = 128;
		anim(rpg, battle, x);
		draw_all(rpg);
		display_enemy(rpg, battle);
		display_hero(rpg, battle);
		sfRenderWindow_display(rpg->win);
		return (true);
	}
	return (false);
}
