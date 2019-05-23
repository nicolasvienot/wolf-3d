/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:51:31 by abechet           #+#    #+#             */
/*   Updated: 2019/05/22 16:12:20 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	key_w_s(t_win *win)
{
	double		cos_rad;
	double		sin_rad;

	if (win->keystate[SDL_SCANCODE_W])
	{
		cos_rad = cos(-win->dir_player * M_PI / 180);
		if (win->map[(int)(win->pos_y)][(int)(win->pos_x + cos_rad * 0.3 \
			+ cos_rad * win->move_speed)] == '0')
			win->pos_x += cos_rad * win->move_speed;
		sin_rad = -sin(win->dir_player * M_PI / 180);
		if (win->map[(int)(win->pos_y + sin_rad * 0.3 + sin_rad \
			* win->move_speed)][(int)(win->pos_x)] == '0')
			win->pos_y += sin_rad * win->move_speed;
	}
	if (win->keystate[SDL_SCANCODE_S])
	{
		cos_rad = cos((-win->dir_player + 180) * M_PI / 180);
		if (win->map[(int)(win->pos_y)][(int)(win->pos_x + cos_rad \
			* 0.3 + cos_rad * win->move_speed)] == '0')
			win->pos_x += cos_rad * win->move_speed;
		sin_rad = -sin((win->dir_player + 180) * M_PI / 180);
		if (win->map[(int)(win->pos_y + sin_rad * 0.3 + sin_rad \
			* win->move_speed)][(int)(win->pos_x)] == '0')
			win->pos_y += sin_rad * win->move_speed;
	}
}

void	key_a_d(t_win *win)
{
	double		cos_rad;
	double		sin_rad;

	if (win->keystate[SDL_SCANCODE_A])
	{
		cos_rad = -cos((-win->dir_player + 90) * M_PI / 180);
		if (win->map[(int)(win->pos_y)][(int)(win->pos_x + cos_rad \
			* 0.3 + cos_rad * win->move_speed)] == '0')
			win->pos_x += cos_rad * win->move_speed;
		sin_rad = -sin((win->dir_player + 90) * M_PI / 180);
		if (win->map[(int)(win->pos_y + sin_rad * 0.3 + sin_rad \
			* win->move_speed)][(int)(win->pos_x)] == '0')
			win->pos_y += sin_rad * win->move_speed;
	}
	if (win->keystate[SDL_SCANCODE_D])
	{
		cos_rad = -cos((-win->dir_player + 270) * M_PI / 180);
		if (win->map[(int)(win->pos_y)][(int)(win->pos_x + cos_rad \
			* 0.3 + cos_rad * win->move_speed)] == '0')
			win->pos_x += cos_rad * win->move_speed;
		sin_rad = -sin((win->dir_player + 270) * M_PI / 180);
		if (win->map[(int)(win->pos_y + sin_rad * 0.3 + sin_rad \
			* win->move_speed)][(int)(win->pos_x)] == '0')
			win->pos_y += sin_rad * win->move_speed;
	}
}

void	key_e_m(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_E])
	{
		if (Mix_Playing(1) != 1)
			Mix_PlayChannel(1, win->medic, 0);
	}
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_M])
	{
		if (win->minimap == 0)
			win->minimap = 1;
		else
			win->minimap = 0;
	}
}

void	key_n_rshift(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_N])
	{
		if (win->minimap_style == 1)
			win->minimap_style = 2;
		else
			win->minimap_style = 1;
	}
	if (win->keystate[SDL_SCANCODE_RSHIFT])
	{
		if (Mix_Playing(1) != 1)
			Mix_PlayChannel(1, win->headshot, 0);
	}
}

void	key_1_2_3(t_win *win)
{
	if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_KP_1])
	{
		win->text = 1;
		choose_texture(win);
	}
	else if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_KP_2])
	{
		win->text = 2;
		choose_texture(win);
	}
	else if (win->event.type == SDL_KEYDOWN && win->keystate[SDL_SCANCODE_KP_3])
	{
		win->text = 3;
		choose_texture(win);
	}
}
