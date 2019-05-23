/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:15:24 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 19:43:56 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	s2 = (char *)s;
	if (!s || !(s2 = ((char *)malloc(sizeof(char) * (len + 1)))))
		return (NULL);
	while (start != 0)
	{
		i++;
		start--;
	}
	while (j < len)
	{
		s2[j] = s[i];
		i++;
		j++;
	}
	s2[j] = '\0';
	return (s2);
}
