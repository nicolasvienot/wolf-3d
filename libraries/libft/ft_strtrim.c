/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:17:05 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/21 17:50:44 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int i;
	int len;

	i = 0;
	if (!s)
		return (NULL);
	while (ft_iswhitespace(s[i]) == 1)
	{
		i++;
		if (s[i] == '\0')
			return (ft_strdup(""));
	}
	len = ft_strlen(s) - 1;
	while (ft_iswhitespace(s[len]) == 1)
		len--;
	return (ft_strsub(s, i, len - i + 1));
}
