/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 13:29:43 by abechet           #+#    #+#             */
/*   Updated: 2019/05/21 15:22:24 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	fill_empty_line(int i, int j, int maxlen, char **map)
{
	while (j <= maxlen)
	{
		map[i][j] = '0';
		j++;
	}
	map[i][j] = '1';
	map[i][j + 1] = '\0';
}

static void	fill_line(int i, int j, int maxlen, char **map)
{
	while (j <= maxlen + 1)
	{
		map[i][j] = '1';
		j++;
	}
	map[i][j] = '\0';
}

static void	whitespace(char **map, char *line, int i, int j)
{
	if (ft_iswhitespace(line[j]) || line[j] == '0')
		map[i][j + 1] = '0';
	else
		map[i][j + 1] = '1';
}

char		**fill_map(int fd, char **map, int maxlen)
{
	char	*line;
	int		ret;
	int		i;
	int		j;

	i = 1;
	fill_line(0, 0, maxlen, map);
	while ((ret = get_next_line_max(fd, &line)) > 0)
	{
		j = -1;
		map[i][0] = '1';
		while (line[++j])
			whitespace(map, line, i, j);
		j = j + 1;
		fill_empty_line(i, j, maxlen, map);
		i++;
		free(line);
	}
	if (ret < 0)
		return (NULL);
	fill_line(i, 0, maxlen, map);
	free(line);
	return (map);
}

int			info_file(int fd, int *nblines)
{
	char	*line;
	int		ret;
	int		maxlen;

	maxlen = 0;
	while ((ret = get_next_line_max(fd, &line)) > 0)
	{
		*nblines += 1;
		if ((size_t)maxlen < ft_strlen(line))
			maxlen = ft_strlen(line);
		if (maxlen > MAP_MAX_LENGHT || *nblines > MAP_MAX_HEIGHT)
		{
			if (maxlen > MAP_MAX_LENGHT)
				ft_putendl("Map trop longue en largeur...");
			else
				ft_putendl("Map trop longue en hauteur...");
			return (0);
		}
		free(line);
	}
	if (ret < 0)
		return (0);
	free(line);
	return (maxlen);
}
