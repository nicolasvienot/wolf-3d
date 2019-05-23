/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 17:59:36 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/13 17:16:16 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr(int n)
{
	long nblong;

	nblong = n;
	while (nblong < 0)
	{
		ft_putchar('-');
		nblong = -nblong;
	}
	if (nblong > 9)
	{
		ft_putnbr(nblong / 10);
		ft_putnbr(nblong % 10);
	}
	else
		ft_putchar(nblong + '0');
}
