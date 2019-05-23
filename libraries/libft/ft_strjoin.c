/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:16:18 by nvienot           #+#    #+#             */
/*   Updated: 2019/03/16 02:07:23 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*dst;

	if (!s1 || !s2)
		return (NULL);
	if (!(dst = ft_memalloc((ft_strlen(s1) + ft_strlen(s2)) + 1)))
		return (NULL);
	ft_strcat((ft_strcpy(dst, s1)), s2);
	return (dst);
}
