/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 18:01:20 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 19:44:22 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char		*ft_strndup(const char *s1, size_t n)
{
	size_t	i1;
	size_t	i2;
	char	*str;

	i1 = 0;
	i2 = 0;
	while (s1[i1])
		i1++;
	if ((!(str = (char*)malloc(sizeof(char) * (n + 1)))))
		return (NULL);
	while (i2 < i1 && i2 < n)
	{
		str[i2] = s1[i2];
		i2++;
	}
	str[i2] = '\0';
	return (str);
}
