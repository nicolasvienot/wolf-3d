/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 01:22:00 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/20 16:08:47 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_str_is_alpha(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (1);
	while (str[i] != '\0')
	{
		if ((str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= 'a' && str[i] <= 'z'))
			i++;
		else
			return (0);
	}
	return (1);
}
