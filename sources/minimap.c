/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:00:20 by abechet           #+#    #+#             */
/*   Updated: 2019/05/22 17:50:59 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_player2(t_win *win)
{
	int		count;
	double	x_dir;
	double	y_dir;

	count = 0;
	x_dir = 0;
	y_dir = 0;
	while (count < 15)
	{
		x_dir = x_dir + -cos((270 + win->dir_player) * M_PI / 180);
		y_dir = y_dir + -sin((270 + win->dir_player) * M_PI / 180);
		put_pixel_to_surface(win->surface, (win->pos_x * 3) + ((sin(100)
			* x_dir) + (cos(100) * y_dir)) + 20, (win->pos_y * 3)
				+ ((cos(100) * x_dir) + (-sin(100) * y_dir)) + 40, 155);
		put_pixel_to_surface(win->surface, (win->pos_x * 3) + ((sin(-100)
			* x_dir) + (cos(-100) * y_dir)) + 20, (win->pos_y * 3) + ((cos(-100)
				* x_dir) + (-sin(-100) * y_dir)) + 40, 155);
		count++;
	}
}

static void	draw_player1(t_win *win)
{
	put_pixel_to_surface(win->surface, (win->pos_x * 3)
		+ 20, (win->pos_y * 3) + 39, 155);
	put_pixel_to_surface(win->surface, (win->pos_x * 3)
		+ 20 + 1, (win->pos_y * 3) + 39, 155);
	put_pixel_to_surface(win->surface, (win->pos_x * 3)
		+ 20, (win->pos_y * 3) + 39 + 1, 155);
	put_pixel_to_surface(win->surface, (win->pos_x * 3)
		+ 20 + 1, (win->pos_y * 3) + 39 + 1, 155);
	draw_player2(win);
}

void		draw_bloc(t_win *win, int i, int j)
{
	int color;

	color = SDL_MapRGBA(win->surface->format, 213, 214, 210, 20);
	if (win->text == 1)
		color = 150150;
	if (win->minimap_style == 1)
	{
		if (i == 0 || j == 0 || i == ((win->map_width - 1) * 3)
			|| j == ((win->map_height - 1) * 3))
			color = 10;
	}
	if (win->minimap_style == 2)
	{
		if (i == 0 || j == 0 || i == 117 || j == 117)
			color = 10;
	}
	put_pixel_to_surface(win->surface, 20 + i, 40 + j, color);
	put_pixel_to_surface(win->surface, 21 + i, 40 + j, color);
	put_pixel_to_surface(win->surface, 19 + i, 40 + j, color);
	put_pixel_to_surface(win->surface, 20 + i, 41 + j, color);
	put_pixel_to_surface(win->surface, 20 + i, 39 + j, color);
	put_pixel_to_surface(win->surface, 19 + i, 39 + j, color);
	put_pixel_to_surface(win->surface, 21 + i, 41 + j, color);
	put_pixel_to_surface(win->surface, 19 + i, 41 + j, color);
	put_pixel_to_surface(win->surface, 21 + i, 39 + j, color);
}

static void	minimap1(t_win *win)
{
	int		i;
	int		j;

	j = 0;
	while (j < win->map_height)
	{
		i = 0;
		while (i < win->map_width)
		{
			if (win->map[j][i] != '0')
				draw_bloc(win, i * 3, j * 3);
			i++;
		}
		j++;
	}
	draw_player1(win);
}

void		draw_minimap(t_win *win)
{
	if (win->minimap_style == 1)
		minimap1(win);
	else
		minimap2(win);
}
