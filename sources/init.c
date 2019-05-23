/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:44:25 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 19:35:52 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	init_dst(t_win *win)
{
	win->dst.x = 3;
	win->dst.y = 3;
	win->dst2.x = 0;
	win->dst2.y = 0;
	win->dst2.w = WIN_X;
	win->dst2.h = WIN_Y;
	win->dst3.x = (WIN_X / 2 - 370 / 8);
	win->dst3.y = (WIN_Y - 305);
	win->dst4.x = 0;
	win->dst4.y = 0;
	win->dst5.x = 500;
	win->dst5.y = 655;
	win->dst6.x = WIN_X - 100;
	win->dst6.y = WIN_Y - 50;
	win->dst7.x = WIN_X - 70;
	win->dst7.y = WIN_Y - 50;
	win->dst8.x = WIN_X - 60;
	win->dst8.y = WIN_Y - 45;
	win->color_font_r.r = 255;
	win->color_font_o.r = 246;
	win->color_font_o.g = 100;
	win->color_font_o.b = 15;
	win->w_win = WIN_X;
	win->h_win = WIN_Y;
}

static int	init_assets(t_win *win)
{
	win->police = TTF_OpenFont("resources/fonts/tf2build.ttf", 30);
	win->intro = IMG_Load("resources/textures/all/intro.png");
	win->menu = IMG_Load("resources/textures/all/menu.png");
	win->gun = IMG_Load("resources/textures/all/gun.png");
	win->ceiling = IMG_Load("resources/textures/tf2/ceiling31.jpg");
	win->floor = IMG_Load("resources/textures/tf2/floor.png");
	win->side1 = IMG_Load("resources/textures/tf2/side1.png");
	win->side2 = IMG_Load("resources/textures/tf2/side2.png");
	win->side3 = IMG_Load("resources/textures/tf2/side3.png");
	win->side4 = IMG_Load("resources/textures/tf2/side4.png");
	win->theme = Mix_LoadMUS("resources/sounds/danger.ogg");
	win->headshot = Mix_LoadWAV("resources/sounds/206.wav");
	win->medic = Mix_LoadWAV("resources/sounds/scout5.wav");
	if (win->police == NULL)
		clear_n_exit(win, 13);
	if (win->intro == NULL || win->menu == NULL || win->gun == NULL
		|| win->ceiling == NULL || win->floor == NULL || win->side1 == NULL
			|| win->side2 == NULL || win->side3 == NULL || win->side4 == NULL)
		clear_n_exit(win, 14);
	if (win->theme == NULL || win->headshot == NULL || win->medic == NULL)
		clear_n_exit(win, 15);
	return (0);
}

static int	init_struct(t_win *win)
{
	win->dir_player = 270.0;
	win->vertical_mouse = 0.0;
	win->sensibility_hor = 0.5;
	win->sensibility_ver = 1.8;
	win->sensibility_move = 2;
	win->move_speed = 0;
	win->h_win_tmp = 0;
	win->w_win_tmp = 0;
	win->tex = 0;
	win->text = 1;
	win->firing = 0;
	win->delta_clock = 0;
	win->current_fps = 0;
	win->start_clock = SDL_GetTicks();
	win->minimap = 1;
	win->ammo1 = 6;
	win->ammo2 = 32;
	win->aff = 1;
	win->reloading = 0;
	win->resize = 0;
	if (win->map_width < 90 && win->map_height < 90)
		win->minimap_style = 1;
	else
		win->minimap_style = 2;
	return (0);
}

static int	init_sdl(t_win *win)
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
		clear_n_exit(win, 8);
	if (TTF_Init() == -1)
		clear_n_exit(win, 9);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT,
		MIX_DEFAULT_CHANNELS, 1024) == -1)
		clear_n_exit(win, 10);
	Mix_AllocateChannels(10);
	if ((win->window = SDL_CreateWindow("Wolf3D", SDL_WINDOWPOS_CENTERED, \
		SDL_WINDOWPOS_CENTERED, WIN_X, WIN_Y, SDL_WINDOW_SHOWN | \
			SDL_WINDOW_RESIZABLE)) == NULL)
		clear_n_exit(win, 11);
	if ((win->renderer = SDL_CreateRenderer(win->window, -1, \
		SDL_RENDERER_ACCELERATED)) == NULL)
		clear_n_exit(win, 11);
	if ((win->surface = SDL_CreateRGBSurface(0, WIN_X, WIN_Y, \
		32, 0, 0, 0, 0)) == NULL)
		clear_n_exit(win, 6);
	return (0);
}

int			init(t_win *win)
{
	if (init_sdl(win) != 0)
		clear_n_exit(win, 4);
	if (init_struct(win) != 0)
		clear_n_exit(win, 4);
	if (init_assets(win) != 0)
		clear_n_exit(win, 4);
	init_dst(win);
	return (0);
}
