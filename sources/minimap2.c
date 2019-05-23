/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:56:05 by abechet           #+#    #+#             */
/*   Updated: 2019/05/22 17:52:01 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_player4(t_win *win)
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
		put_pixel_to_surface(win->surface, 77 + ((sin(100) * x_dir) + (cos(100)
			* y_dir)), 97 + ((cos(100) * x_dir) + (-sin(100) * y_dir)), 155);
		put_pixel_to_surface(win->surface, 77 + ((sin(-100) * x_dir)
			+ (cos(-100) * y_dir)), 97 + ((cos(-100) * x_dir)
				+ (-sin(-100) * y_dir)), 155);
		count++;
	}
}

static void	draw_player3(t_win *win)
{
	put_pixel_to_surface(win->surface, 77, 97, 155);
	put_pixel_to_surface(win->surface, 77 + 1, 97, 155);
	put_pixel_to_surface(win->surface, 77, 97 + 1, 155);
	put_pixel_to_surface(win->surface, 77 + 1, 97 + 1, 155);
	draw_player4(win);
}

void		minimap2(t_win *win)
{
	int		i;
	int		j;

	win->my = win->pos_y - 20;
	j = -1;
	while (++j < 40)
	{
		i = -1;
		win->mx = win->pos_x - 20;
		while (++i < 40)
		{
			if (i == 0 || j == 0 || i == 39 || j == 39)
				draw_bloc(win, i * 3, j * 3);
			if (win->mx >= 0 && win->mx <= win->map_width - 1 && win->my >= 0
					&& win->my <= win->map_height - 1)
			{
				if (win->map[win->my][win->mx] != '0')
					draw_bloc(win, i * 3, j * 3);
			}
			win->mx++;
		}
		win->my++;
	}
	draw_player3(win);
}
