/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 18:14:52 by abechet           #+#    #+#             */
/*   Updated: 2019/05/21 17:15:57 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	end_anim(t_win *win)
{
	int time;
	int	tmp;

	time = 40 * (6 - win->ammo1);
	if (win->reloading != 0 && win->reloading > time)
	{
		SDL_FreeSurface(win->gun);
		if ((win->gun = IMG_Load("resources/textures/all/gun.png")) == NULL)
			clear_n_exit(win, 14);
		win->dst3.x = (WIN_X / 2 - 370 / 8);
		win->dst3.y = (WIN_Y - 305);
		win->reloading = 0;
		tmp = win->ammo2;
		win->ammo2 = win->ammo2 - (6 - win->ammo1);
		if (win->ammo2 < 0)
			win->ammo2 = 0;
		if (win->ammo2 < 6)
			win->ammo1 = win->ammo1 + tmp;
		else
			win->ammo1 = 6;
		if (win->ammo1 > 6)
			win->ammo1 = 6;
	}
	if (win->reloading != 0)
		win->reloading++;
}

void	firing(t_win *win)
{
	if (win->firing == 1)
	{
		if (win->ammo1 > 0)
			win->ammo1 -= 1;
	}
	if (win->firing > win->current_fps / 3)
		win->firing = 0;
	if (win->firing != 0)
		win->firing++;
}

void	reload(t_win *win)
{
	win->dst3.x = 0;
	win->dst3.y = 200;
	SDL_FreeSurface(win->gun);
	if ((win->gun = IMG_Load("resources/textures/all/reload.png")) == NULL)
		clear_n_exit(win, 14);
}
