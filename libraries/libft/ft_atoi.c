/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:35:00 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 17:19:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		neg;
	long	repatoi;

	i = 0;
	repatoi = 0;
	neg = 0;
	while ((str[i] >= 9 && str[i] <= 13) || (str[i] == 32))
		i++;
	if ((str[i] == '+') && (str[i + 1] != '-'))
		i++;
	if (str[i] == '-')
	{
		neg = 1;
		i++;
	}
	while (ft_isdigit(str[i]) == 1)
	{
		repatoi = repatoi * 10 + (str[i] - '0');
		i++;
	}
	if (neg == 1)
		return (-repatoi);
	return (repatoi);
}
