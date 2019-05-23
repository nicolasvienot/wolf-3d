/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 15:02:50 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/20 16:08:20 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_base(int nb, int base)
{
	char	*base1;
	char	*base2;
	int		i;

	base1 = "0123456789abcdef";
	base2 = "0123456789ABCDEF";
	i = 0;
	while (i < base)
	{
		if (nb == base1[i] || nb == base2[i])
			return (i);
		i++;
	}
	return (-1);
}

int			ft_atoi_base(const char *str, int base)
{
	int	nb;
	int	neg;
	int	i;

	nb = 0;
	neg = 0;
	i = 0;
	while (((str[i] >= 8 && str[i] <= 13) || str[i] == ' ') && str[i])
		i++;
	if (str[i] == '-')
		neg++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (ft_ishexa(str[i]))
	{
		nb = nb * base + (ft_base(str[i], base));
		i++;
	}
	return (neg ? -nb : nb);
}
