/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:11:49 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 19:44:39 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*s2;

	i = 0;
	if (!s || !f || !(s2 = ((char *)malloc(sizeof(char) * ft_strlen(s) + 1))))
		return (NULL);
	while (s[i])
	{
		s2[i] = (f)(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
