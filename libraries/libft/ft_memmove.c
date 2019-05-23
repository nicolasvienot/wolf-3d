/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 18:21:48 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/20 17:05:59 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*dst2;
	const char	*src2;

	i = -1;
	dst2 = (char*)dst;
	src2 = (const char*)src;
	if (dst2 < src2)
	{
		while (++i < len)
		{
			dst2[i] = src2[i];
		}
	}
	else
	{
		while (len-- > 0)
		{
			dst2[len] = src2[len];
		}
	}
	return (dst2);
}
