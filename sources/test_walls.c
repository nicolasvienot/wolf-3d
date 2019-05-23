/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/16 22:13:05 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/16 23:41:21 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	calc_wall_height(t_win *win, t_render *r)
{
	r->dist_hor = sqrt((r->hor_x * r->hor_x) + (r->hor_y * r->hor_y)) \
		* cos(r->alph_angle_rad);
	r->dist_ver = sqrt((r->ver_x * r->ver_x) + (r->ver_y * r->ver_y)) \
		* cos(r->alph_angle_rad);
	if (r->dist_hor < r->dist_ver)
	{
		r->side = 1;
		r->dist = r->dist_hor;
		r->final_x = r->hor_x;
		r->final_y = r->hor_y;
	}
	else
	{
		r->side = 2;
		r->dist = r->dist_ver;
		r->final_x = r->ver_x;
		r->final_y = r->ver_y;
	}
	r->wall_height = 64 / r->dist * 1108;
	r->draw_start = (WIN_Y - r->wall_height) / 2 + (int)win->vertical_mouse;
	r->draw_end = (WIN_Y + r->wall_height) / 2 + (int)win->vertical_mouse;
}

void	test_walls_ver_right(t_win *win, t_render *r)
{
	r->color_v = COLOR_WALL_EAST;
	r->ver_x = floor(win->pos_x) * CUBE_SIZE + CUBE_SIZE;
	r->ver_y = r->player_y + (r->player_x - r->ver_x) * tan(r->ray_angle_rad);
	r->step_x = (CUBE_SIZE);
	r->step_y = -(r->step_x) * tan(r->ray_angle_rad);
	while (r->ver_x > 0 && r->ver_x < win->map_width * CUBE_SIZE \
		&& r->ver_y > 0 && r->ver_y < win->map_height * CUBE_SIZE)
	{
		if (win->map[(int)(r->ver_y / 64)][(int)((r->ver_x + 1) / 64)] == '1')
			break ;
		r->ver_x += r->step_x;
		r->ver_y += r->step_y;
	}
	r->ver_x = r->player_x - r->ver_x;
	r->ver_y = r->player_y - r->ver_y;
}

void	test_walls_ver_left(t_win *win, t_render *r)
{
	r->color_v = COLOR_WALL_WEST;
	r->ver_x = floor(win->pos_x) * CUBE_SIZE;
	r->ver_y = r->player_y + (r->player_x - r->ver_x) * tan(r->ray_angle_rad);
	r->step_x = -(CUBE_SIZE);
	r->step_y = -(r->step_x) * tan(r->ray_angle_rad);
	while (r->ver_x > 0 && r->ver_x < win->map_width * CUBE_SIZE \
		&& r->ver_y > 0 && r->ver_y < win->map_height * CUBE_SIZE)
	{
		if (win->map[(int)(r->ver_y
				/ 64)][(int)((r->ver_x - 1) / 64)] == '1')
			break ;
		r->ver_x += r->step_x;
		r->ver_y += r->step_y;
	}
	r->ver_x = r->player_x - r->ver_x;
	r->ver_y = r->player_y - r->ver_y;
}

void	test_walls_hor_down(t_win *win, t_render *r)
{
	r->color_h = COLOR_WALL_SOUTH;
	r->hor_y = floor(win->pos_y) * CUBE_SIZE + CUBE_SIZE;
	r->hor_x = r->player_x + (r->player_y - r->hor_y) / tan(r->ray_angle_rad);
	r->step_y = (CUBE_SIZE);
	r->step_x = -(r->step_y) / tan(r->ray_angle_rad);
	while (r->hor_x > 0 && r->hor_x < win->map_width * CUBE_SIZE \
		&& r->hor_y > 0 && r->hor_y < win->map_height * CUBE_SIZE)
	{
		if (win->map[(int)((r->hor_y + 1) / 64)][(int)(r->hor_x / 64)] == '1')
			break ;
		r->hor_y += r->step_y;
		r->hor_x += r->step_x;
	}
	r->hor_x = r->player_x - r->hor_x;
	r->hor_y = r->player_y - r->hor_y;
}

void	test_walls_hor_up(t_win *win, t_render *r)
{
	r->color_h = COLOR_WALL_NORTH;
	r->hor_y = floor(win->pos_y) * CUBE_SIZE;
	r->hor_x = r->player_x + (r->player_y - r->hor_y) / tan(r->ray_angle_rad);
	r->step_y = -(CUBE_SIZE);
	r->step_x = -(r->step_y) / tan(r->ray_angle_rad);
	while (r->hor_x > 0 && r->hor_x < win->map_width * CUBE_SIZE \
		&& r->hor_y > 0 && r->hor_y < win->map_height * CUBE_SIZE)
	{
		if (win->map[(int)((r->hor_y - 1) / 64)][(int)(r->hor_x / 64)] == '1')
			break ;
		r->hor_y += r->step_y;
		r->hor_x += r->step_x;
	}
	r->hor_x = r->player_x - r->hor_x;
	r->hor_y = r->player_y - r->hor_y;
}
