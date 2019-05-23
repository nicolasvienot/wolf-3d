/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 16:28:24 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/13 17:17:22 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t d;
	size_t s;

	d = 0;
	s = 0;
	while (dst[d] != '\0' && d < size)
		d++;
	if (dst[d] == '\0')
	{
		while (src[s] != '\0' && (d + s) < size - 1)
		{
			dst[d + s] = src[s];
			s++;
		}
		dst[d + s] = '\0';
	}
	while (src[s] != '\0')
		s++;
	return (d + s);
}
