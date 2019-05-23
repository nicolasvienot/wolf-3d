/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithreading.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 12:27:56 by nvienot           #+#    #+#             */
/*   Updated: 2019/04/27 17:06:34 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		multithreading(t_win *win)
{
	t_mthrds	*mthrds;
	int			i;

	mthrds = &win->mthrds;
	i = -1;
	while (++i < NB_THREADS)
	{
		mthrds->thrd[i].id = i;
		mthrds->thrd[i].w = win;
		pthread_create(&mthrds->threads[i], NULL, calc, &mthrds->thrd[i]);
	}
	i = -1;
	while (++i < NB_THREADS)
	{
		pthread_join(mthrds->threads[i], NULL);
	}
}
