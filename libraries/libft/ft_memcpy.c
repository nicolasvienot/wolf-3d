/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 16:30:35 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 19:17:54 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t		i;
	char		*dst2;
	char		*src2;

	i = 0;
	dst2 = (char*)dst;
	src2 = (char*)src;
	if (!dst && !src)
		return (NULL);
	while (i < n)
	{
		dst2[i] = src2[i];
		i++;
	}
	return (dst2);
}
