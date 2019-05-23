/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortinttab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 17:58:04 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 17:58:32 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_sortinttab(int *tab, unsigned int size)
{
	unsigned int i;

	i = 0;
	while (i < size - 1)
	{
		if (tab[i] <= tab[i + 1])
			i++;
		else
		{
			ft_swap(&tab[i], &tab[i + 1]);
			i = 0;
		}
	}
}
