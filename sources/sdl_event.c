/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 17:28:53 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 17:54:55 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		key_sensi(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN \
		&& win->keystate[SDL_SCANCODE_KP_PLUS])
	{
		if (win->sensibility_hor < 5 && win->sensibility_ver < 5)
		{
			win->sensibility_hor += 0.05;
			win->sensibility_ver += 0.15;
		}
	}
	if (win->event.type == SDL_KEYDOWN \
		&& win->keystate[SDL_SCANCODE_KP_MINUS])
	{
		if (win->sensibility_hor > 0.1 && win->sensibility_ver > 0.5)
		{
			win->sensibility_hor -= 0.05;
			win->sensibility_ver -= 0.15;
		}
	}
}

static void	sdl_event_mouse(t_win *win)
{
	if (win->reloading == 0)
	{
		if (SDL_GetMouseState(NULL, NULL) == 1)
		{
			if (win->firing == 0 && win->ammo1 > 0)
			{
				Mix_PlayChannel(1, win->headshot, 0);
				win->firing = 1;
				win->dst3.x = (WIN_X / 2 - 280 / 8);
				win->dst3.y = (WIN_Y - 320);
				firing(win);
			}
		}
	}
}

static void	sdl_event_motion(t_win *win)
{
	int x;
	int y;

	SDL_GetRelativeMouseState(&x, &y);
	if (x || y)
	{
		win->dir_player -= (x * win->sensibility_hor);
		if (win->dir_player >= 360.0)
			win->dir_player -= 360.0;
		if (win->dir_player < 0.0)
			win->dir_player += 360.0;
		win->vertical_mouse -= (y * win->sensibility_ver);
		if (win->vertical_mouse >= 600.0)
			win->vertical_mouse = 600.0;
		if (win->vertical_mouse <= -600.0)
			win->vertical_mouse = -600.0;
	}
}

static void	sdl_event_key(t_win *win)
{
	win->keystate = (Uint8 *)SDL_GetKeyboardState(0);
	if (win->event.type == SDL_QUIT
		|| win->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
		clear_n_exit(win, 0);
	key_y(win);
	key_r_tab(win);
	key_t_lshift(win);
	key_right_left(win);
	key_up_down(win);
	key_w_s(win);
	key_a_d(win);
	key_e_m(win);
	key_n_rshift(win);
}

void		sdl_event(t_win *win)
{
	sdl_event_key(win);
	sdl_event_mouse(win);
	if (win->resize == 0)
		sdl_event_motion(win);
}
