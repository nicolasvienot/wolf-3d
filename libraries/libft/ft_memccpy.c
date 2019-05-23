/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:01:04 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 19:17:28 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
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
		if (src2[i] == (char)c)
		{
			i++;
			while (i != 0)
			{
				dst2++;
				i--;
			}
			return (dst2);
		}
		i++;
	}
	return (NULL);
}
