/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:04:11 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 18:12:11 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	t_win	win;

	win.secu = 0;
	if (argc != 2)
		clear_n_exit(&win, 1);
	if (!(win.map = get_map(argv[1], &win)))
		clear_n_exit(&win, 2);
	win.secu = 1;
	if (!(check_map(&win)))
		clear_n_exit(&win, 3);
	put_map(win.map);
	if (init(&win) == 1)
		clear_n_exit(&win, 4);
	if (Mix_PlayMusic(win.theme, -1) == -1)
		clear_n_exit(&win, 5);
	loop_intro(&win);
	if (SDL_SetRelativeMouseMode(SDL_TRUE) < 0)
		clear_n_exit(&win, 7);
	loop_play(win);
	clear_n_exit(&win, 0);
	return (EXIT_SUCCESS);
}
