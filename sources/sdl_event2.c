/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:32:53 by abechet           #+#    #+#             */
/*   Updated: 2019/05/21 19:28:58 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_y(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_Y])
	{
		if (win->resize == 0)
		{
			win->resize = 1;
			SDL_SetRelativeMouseMode(SDL_FALSE);
		}
		else
		{
			win->resize = 0;
			win->vertical_mouse = 0.0;
			SDL_SetRelativeMouseMode(SDL_TRUE);
		}
	}
}

void	key_r_tab(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_R])
	{
		if (win->ammo1 != 6 && win->ammo2 != 0)
		{
			if (win->reloading == 0)
			{
				win->reloading = 1;
				win->dst3.x = (WIN_X / 2 - 170 / 8);
				win->dst3.y = (WIN_Y - 4170);
				reload(win);
			}
		}
	}
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_TAB])
		loop_menu(win);
}

void	key_t_lshift(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_T])
	{
		if (win->tex == 0)
			win->tex = 1;
		else
			win->tex = 0;
	}
	if (win->keystate[SDL_SCANCODE_LSHIFT])
	{
		win->move_speed = (1 / (double)win->current_fps) * 15;
	}
}

void	key_right_left(t_win *win)
{
	if (win->keystate[SDL_SCANCODE_RIGHT])
	{
		win->dir_player -= 0.5;
		if (win->dir_player <= 0.0)
			win->dir_player += 360.0;
	}
	if (win->keystate[SDL_SCANCODE_LEFT])
	{
		win->dir_player += 0.5;
		if (win->dir_player >= 360.0)
			win->dir_player -= 360.0;
	}
}

void	key_up_down(t_win *win)
{
	if (win->keystate[SDL_SCANCODE_UP])
	{
		win->vertical_mouse += 2.0;
		if (win->vertical_mouse >= 500.0)
			win->vertical_mouse = 500.0;
	}
	if (win->keystate[SDL_SCANCODE_DOWN])
	{
		win->vertical_mouse -= 2.0;
		if (win->vertical_mouse <= -500.0)
			win->vertical_mouse = -500.0;
	}
}
