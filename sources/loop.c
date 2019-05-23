/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 20:15:25 by abechet           #+#    #+#             */
/*   Updated: 2019/05/22 19:32:49 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	txt_intro(t_win *win)
{
	win->txtintro = TTF_RenderText_Blended(win->police,
			"Press Enter to play", win->color_font_o);
	if ((SDL_BlitSurface(win->txtintro, NULL, win->surface, &win->dst5)) < 0)
		clear_n_exit(win, 19);
	SDL_FreeSurface(win->txtintro);
}

void		loop_menu(t_win *win)
{
	while (42)
	{
		if ((SDL_BlitSurface(win->menu, NULL, win->surface, &win->dst4)) < 0)
			clear_n_exit(win, 19);
		SDL_PollEvent(&win->event);
		if (win->event.type == SDL_QUIT \
			|| win->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			clear_n_exit(win, 0);
		if (win->event.key.keysym.scancode == SDL_SCANCODE_RETURN)
			break ;
		key_1_2_3(win);
		key_sensi(win);
		print_menu(win);
	}
}

void		loop_play(t_win win)
{
	win.surface = SDL_CreateRGBSurface(0, WIN_X, WIN_Y, 32, 0, 0, 0, 0);
	while (42)
	{
		multithreading(&win);
		if (win.minimap == 1)
			draw_minimap(&win);
		fps(&win);
		SDL_PollEvent(&win.event);
		sdl_event(&win);
		print_game(&win);
	}
}

void		loop_intro(t_win *win)
{
	win->act_time = 0;
	win->tmp_time = 0;
	while (42)
	{
		if ((SDL_BlitSurface(win->intro, NULL, win->surface, &win->dst4)) < 0)
			clear_n_exit(win, 19);
		if (win->aff == 1)
			txt_intro(win);
		win->act_time = SDL_GetTicks();
		if (win->act_time - win->tmp_time > 500)
		{
			if (win->aff == 1)
				win->aff = 0;
			else
				win->aff = 1;
			win->tmp_time = win->act_time;
		}
		SDL_PollEvent(&win->event);
		if (win->event.key.keysym.scancode == SDL_SCANCODE_RETURN)
			break ;
		if (win->event.type == SDL_QUIT \
			|| win->event.key.keysym.scancode == SDL_SCANCODE_ESCAPE)
			clear_n_exit(win, 0);
		print_intro(win);
	}
}
