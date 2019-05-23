/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 16:12:27 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/15 17:46:08 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	while (*s)
		s++;
	while ((*s != c) && (i != 0))
	{
		s--;
		i--;
	}
	if (*s == c)
		return ((char*)s);
	return (NULL);
}
