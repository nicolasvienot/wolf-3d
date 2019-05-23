/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/18 18:41:16 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/21 17:49:42 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		malloc_map_case(t_win *win, int nblines, int maxlen, char **map)
{
	int i;

	i = 0;
	while (i < nblines + 2)
	{
		if (!(map[i] = (char*)malloc(sizeof(char) * (maxlen + 3))))
			clear_n_exit(win, 2);
		i++;
	}
	win->map_width = maxlen + 2;
	win->map_height = nblines + 2;
	map[i] = NULL;
}

char			**get_map(char *argv, t_win *win)
{
	char	**map;
	int		fd;
	int		nblines;
	int		maxlen;

	map = NULL;
	nblines = 0;
	if ((fd = open(argv, O_RDONLY)) < 0)
		clear_n_exit(win, 16);
	if (!(maxlen = info_file(fd, &nblines)))
		clear_n_exit(win, 2);
	close(fd);
	if (!(map = (char**)malloc(sizeof(char*) * (nblines + 3))))
		clear_n_exit(win, 2);
	malloc_map_case(win, nblines, maxlen, map);
	if ((fd = open(argv, O_RDONLY)) < 0)
		clear_n_exit(win, 16);
	if (!(map = fill_map(fd, map, maxlen)))
		clear_n_exit(win, 2);
	close(fd);
	return (map);
}
