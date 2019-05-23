/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/03 14:47:43 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 18:10:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void			choose_texture_2(t_win *win)
{
	win->ceiling = IMG_Load("resources/textures/2/mcwood.jpg");
	win->floor = IMG_Load("resources/textures/2/mcfloor.png");
	win->side1 = IMG_Load("resources/textures/2/mcbrick.png");
	win->side2 = IMG_Load("resources/textures/2/mcstone2.png");
	win->side3 = IMG_Load("resources/textures/2/mcobsi.png");
	win->side4 = IMG_Load("resources/textures/2/mcstone.jpg");
}

void				choose_texture(t_win *win)
{
	free_surface(win);
	if (win->text == 1)
	{
		win->ceiling = IMG_Load("resources/textures/tf2/ceiling31.jpg");
		win->floor = IMG_Load("resources/textures/tf2/floor.png");
		win->side1 = IMG_Load("resources/textures/tf2/side1.png");
		win->side2 = IMG_Load("resources/textures/tf2/side2.png");
		win->side3 = IMG_Load("resources/textures/tf2/side3.png");
		win->side4 = IMG_Load("resources/textures/tf2/side4.png");
	}
	else if (win->text == 2)
	{
		win->ceiling = IMG_Load("resources/textures/1/ceiling8.jpg");
		win->floor = IMG_Load("resources/textures/1/floor.png");
		win->side1 = IMG_Load("resources/textures/1/side1.png");
		win->side2 = IMG_Load("resources/textures/1/side2.png");
		win->side3 = IMG_Load("resources/textures/1/side3.png");
		win->side4 = IMG_Load("resources/textures/1/side4.png");
	}
	else if (win->text == 3)
		choose_texture_2(win);
	if (win->ceiling == NULL || win->floor == NULL || win->side1 == NULL \
	|| win->side2 == NULL || win->side3 == NULL || win->side4 == NULL)
		clear_n_exit(win, 14);
}

static SDL_Surface	*choose_side(t_render *r, t_win *win)
{
	if (r->side == 1)
	{
		if (r->ray_angle <= 180)
			return (win->side1);
		else
			return (win->side2);
	}
	else
	{
		if (r->ray_angle >= 90 && r->ray_angle <= 270)
			return (win->side3);
		else
			return (win->side4);
	}
}

Uint32				get_wall_tex(t_render *r, t_win *win, int y)
{
	SDL_Surface	*surface;
	Uint32		color;
	int			y_wall;
	int			x_tex;
	int			y_tex;

	surface = choose_side(r, win);
	if (r->side == 1)
		x_tex = surface->w - (int)((r->floor_x_wall \
			- (int)r->floor_x_wall) * surface->w) - 1;
	else
		x_tex = surface->w - (int)((r->floor_y_wall \
			- (int)r->floor_y_wall) * surface->w) - 1;
	y_wall = y - win->vertical_mouse - WIN_Y / 2 + r->wall_height / 2;
	y_tex = (y_wall * surface->h) / r->wall_height;
	x_tex = secure_tex_x(x_tex, surface->w);
	y_tex = secure_tex_x(y_tex, surface->h);
	color = get_pixel_from_surface(surface, x_tex, y_tex);
	return (color);
}

Uint32				get_floor_tex(t_render *r, t_win *win, int y, int type)
{
	SDL_Surface	*surface;
	double		coef;
	Uint32		color;

	if (type == 1)
		surface = win->ceiling;
	if (type == 1)
		coef = -1.5;
	if (type == 2)
		surface = win->floor;
	if (type == 2)
		coef = 1.5;
	r->current_dist = (double)WIN_Y / (2.0 * (double)y \
		- ((int)win->vertical_mouse * 2) - (double)WIN_Y);
	r->dist_floor = (r->current_dist * coef) / (r->dist_wall);
	r->current_floor_x = r->dist_floor * r->floor_x_wall \
		+ (1.0 - r->dist_floor) * win->pos_x;
	r->current_floor_y = r->dist_floor * r->floor_y_wall \
		+ (1.0 - r->dist_floor) * win->pos_y;
	r->floor_tex_x = (int)(r->current_floor_x * surface->w) % surface->w;
	r->floor_tex_y = (int)(r->current_floor_y * surface->h) % surface->h;
	r->floor_tex_x = secure_tex_x(r->floor_tex_x, surface->w);
	r->floor_tex_y = secure_tex_y(r->floor_tex_y, surface->h);
	color = get_pixel_from_surface(surface, r->floor_tex_x, r->floor_tex_y);
	return (color);
}
