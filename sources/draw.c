/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/23 16:04:40 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/21 13:42:15 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_crosshair(SDL_Surface *surface)
{
	int x1;
	int x2;
	int y1;
	int y2;

	x1 = WIN_X / 2 - 15;
	x2 = WIN_X / 2 + 15;
	while (x1 <= x2)
	{
		put_pixel_to_surface(surface, x1, WIN_Y / 2, 0);
		x1++;
	}
	y1 = WIN_Y / 2 - 15;
	y2 = WIN_Y / 2 + 15;
	while (y1 <= y2)
	{
		put_pixel_to_surface(surface, WIN_X / 2, y1, 0);
		y1++;
	}
}

void	draw_line_ver(SDL_Surface *surf, t_render *r, int y1, int y2)
{
	while (y1 <= y2)
	{
		put_pixel_to_surface(surf, r->x, y1, r->color);
		y1++;
	}
}

void	put_pixel_to_surface(SDL_Surface *srfc, int x, int y, Uint32 color)
{
	Uint32		*pixels;

	pixels = srfc->pixels;
	if (x >= 0 && y >= 0 && x < srfc->w && y < srfc->h)
		pixels[y * srfc->w + x] = color;
}

Uint32	get_pixel_from_surface(SDL_Surface *srfc, int x, int y)
{
	Uint32		*pixels;
	Uint32		color;

	color = 0;
	pixels = srfc->pixels;
	if (x >= 0 && y >= 0 && x < srfc->w && y < srfc->h)
		color = pixels[y * srfc->w + x];
	return (color);
}
