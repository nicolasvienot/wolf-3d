/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 19:13:14 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/20 18:45:01 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	d;

	d = (unsigned char)c;
	i = 0;
	str = (unsigned char*)s;
	while (i < n)
	{
		if (str[i] == d)
			return (str + i);
		i++;
	}
	return (NULL);
}
