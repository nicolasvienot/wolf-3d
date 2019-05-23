/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 18:05:31 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 18:11:50 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		secure_tex_x(int tex_x, int surface_w)
{
	if (tex_x < 0)
		tex_x = 1;
	else if (tex_x > surface_w)
		tex_x = surface_w;
	return (tex_x);
}

int		secure_tex_y(int tex_y, int surface_h)
{
	if (tex_y < 0)
		tex_y = 1;
	else if (tex_y > surface_h)
		tex_y = surface_h;
	return (tex_y);
}

int		check_map(t_win *win)
{
	int	i;
	int	j;

	j = 0;
	while (win->map[j])
	{
		i = 0;
		while (win->map[j][i])
		{
			if ((win->map[j][i]) == '0')
			{
				win->pos_y = (double)j + 0.5;
				win->pos_x = (double)i + 0.5;
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}

void	put_map(char **map)
{
	int i;

	i = 0;
	ft_putendl("MAP :");
	while (map[i])
	{
		ft_putendl(map[i]);
		i++;
	}
}
