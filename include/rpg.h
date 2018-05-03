/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** RPG functions (header file)
*/

# ifndef _RPG_H
# define _RPG_H

typedef struct game_s game_t;
typedef struct state_interface_s state_interface_t;
typedef struct play_s play_t;
typedef struct ressource_s ressource_t;
typedef struct tileset_s tileset_t;
typedef struct draw_interface_s draw_interface_t;
typedef struct map_s map_t;
typedef struct sprite_s sprite_t;
typedef struct anim_s anim_t;

# ifndef SFML_GRAPHICS_H
# include <SFML/Graphics.h>
# endif

# ifndef SFML_AUDIO_H
# include <SFML/Audio.h>
# endif

# ifndef _MATH_H
# include <math.h>
# endif

# ifndef _MY_H
# include "my.h"
# endif

# ifndef _CL_H
# include "cl.h"
# endif

# ifndef _UTILS_H
# include "utils.h"
# endif

# ifndef _LUA_H
# include "lua.h"
# endif

#ifndef _DRAW_H
#include "draw.h"
#endif

#ifndef _RESSOURCE_H
#include "ressource.h"
#endif

#ifndef _STATE_H
#include "state.h"
#endif

# ifndef _GAME_H
# include "game.h"
# endif

# ifndef _EVENT_H
# include "event.h"
# endif

int		main_rpg(void);

# endif
