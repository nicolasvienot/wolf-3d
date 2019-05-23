/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:18:46 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 02:19:45 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	ft_int_len(int n)
{
	int		i;

	i = 0;
	if (n < 0)
	{
		i++;
		n = -n;
	}
	while (n > 0)
	{
		n = (n - (n % 10)) / 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		len;
	char	*repitoa;

	len = ft_int_len(n);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (!(repitoa = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (n < 0)
	{
		repitoa[0] = '-';
		n = -n;
	}
	repitoa[len] = '\0';
	while (n > 0)
	{
		repitoa[len - 1] = n % 10 + '0';
		n = (n - (n % 10)) / 10;
		len--;
	}
	return (repitoa);
}
