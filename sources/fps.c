/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:04:24 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 19:37:06 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static int	ammo(t_win *win)
{
	char	*ammoitoa;

	if ((ammoitoa = ft_itoa(win->ammo1)) == NULL)
		clear_n_exit(win, 18);
	win->txtammo = TTF_RenderText_Blended(win->police,
		ammoitoa, win->color_font_r);
	free(ammoitoa);
	if ((SDL_BlitSurface(win->txtammo, NULL, win->surface, &win->dst6)) < 0)
		clear_n_exit(win, 19);
	SDL_FreeSurface(win->txtammo);
	if ((ammoitoa = ft_itoa(win->ammo2)) == NULL)
		clear_n_exit(win, 18);
	win->txtammo = TTF_RenderText_Blended(win->police,
		ammoitoa, win->color_font_r);
	free(ammoitoa);
	if ((SDL_BlitSurface(win->txtammo, NULL, win->surface, &win->dst7)) < 0)
		clear_n_exit(win, 19);
	SDL_FreeSurface(win->txtammo);
	return (0);
}

int			fps(t_win *win)
{
	char	*fpstxt;
	char	*fpsitoa;

	win->delta_clock = SDL_GetTicks() - win->start_clock;
	win->start_clock = SDL_GetTicks();
	if (win->delta_clock != 0)
	{
		win->current_fps = 1000 / win->delta_clock;
		win->move_speed = (2 / (double)win->current_fps) \
			* win->sensibility_move;
		if ((fpsitoa = ft_itoa(win->current_fps)) == NULL)
			clear_n_exit(win, 18);
		if ((fpstxt = ft_strjoinnfree("FPS : ", fpsitoa, 2)) == NULL)
			clear_n_exit(win, 18);
		win->txtfps = TTF_RenderText_Blended(win->police, \
			fpstxt, win->color_font_r);
		if ((SDL_BlitSurface(win->txtfps, NULL, win->surface, &win->dst)) < 0)
			clear_n_exit(win, 19);
		SDL_FreeSurface(win->txtfps);
		free(fpstxt);
		ammo(win);
	}
	return (0);
}
