/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 20:58:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 16:55:32 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		draw_textured(t_win *win, t_render *r)
{
	int y;

	r->floor_x_wall = (r->player_x - r->final_x) / 64;
	r->floor_y_wall = (r->player_y - r->final_y) / 64;
	r->dist_wall = r->dist / 64;
	y = 0;
	while (y < r->draw_start)
	{
		put_pixel_to_surface(win->surface, r->x, y, \
			get_floor_tex(r, win, y, 1));
		y++;
	}
	while (y < r->draw_end)
	{
		put_pixel_to_surface(win->surface, r->x, y, \
			get_wall_tex(r, win, y));
		y++;
	}
	while (y < WIN_Y)
	{
		put_pixel_to_surface(win->surface, r->x, y, \
			get_floor_tex(r, win, y, 2));
		y++;
	}
}

static void		draw_untextured(t_win *win, t_render *r)
{
	if (r->draw_start > 0)
	{
		r->color = COLOR_ROOF;
		draw_line_ver(win->surface, r, 0, r->draw_start);
	}
	if (r->draw_end < WIN_Y)
	{
		r->color = COLOR_FLOOR;
		draw_line_ver(win->surface, r, r->draw_end, WIN_Y);
	}
	if (r->dist_hor < r->dist_ver)
		r->color = r->color_h;
	else
		r->color = r->color_v;
	draw_line_ver(win->surface, r, r->draw_start, r->draw_end);
}

static void		check_limit_draw(t_render *r)
{
	if (r->draw_start < 0)
		r->draw_start = 0;
	if (r->draw_start > WIN_Y)
		r->draw_start = WIN_Y;
	if (r->draw_end > WIN_Y)
		r->draw_end = WIN_Y;
	if (r->draw_end < 0)
		r->draw_end = 0;
}

static void		init_calc(t_win *win, t_render *r)
{
	r->ray_angle = win->dir_player + (FOV * 0.5) \
		- (r->x * ((double)FOV / (double)WIN_X));
	if (r->ray_angle >= 360)
		r->ray_angle = r->ray_angle - 360.f;
	if (r->ray_angle < 0)
		r->ray_angle = r->ray_angle + 360.f;
	r->ray_angle_rad = r->ray_angle * M_PI / 180.f;
	r->alph_angle = fabs(win->dir_player - r->ray_angle);
	r->alph_angle_rad = r->alph_angle * M_PI / 180.f;
	r->player_x = win->pos_x * CUBE_SIZE;
	r->player_y = win->pos_y * CUBE_SIZE;
}

void			*calc(void *thrds)
{
	t_thrd		*thrd;
	t_render	r;

	thrd = (t_thrd *)thrds;
	r.x = (WIN_X * thrd->id) / NB_THREADS;
	while (r.x < ((WIN_X * (thrd->id + 1) / NB_THREADS)))
	{
		init_calc(thrd->w, &r);
		r.ray_angle <= 180 ? test_walls_hor_up(thrd->w, &r) \
			: test_walls_hor_down(thrd->w, &r);
		r.ray_angle >= 90 && r.ray_angle <= 270 ? \
			test_walls_ver_left(thrd->w, &r) \
				: test_walls_ver_right(thrd->w, &r);
		calc_wall_height(thrd->w, &r);
		check_limit_draw(&r);
		if (thrd->w->tex == 0)
			draw_untextured(thrd->w, &r);
		else
			draw_textured(thrd->w, &r);
		r.x++;
	}
	pthread_exit(NULL);
}
