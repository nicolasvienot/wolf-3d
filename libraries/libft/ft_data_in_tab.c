/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_data_in_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 12:37:14 by auguyon           #+#    #+#             */
/*   Updated: 2019/02/17 19:45:43 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int	ft_data_in_tab(int *tab, int data, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		if (data == tab[i])
			return (1);
		i++;
	}
	return (0);
}
