/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit_at_first_c.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:18:01 by nvienot           #+#    #+#             */
/*   Updated: 2018/12/06 18:28:33 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cnt_len(char const *str, int i)
{
	int		cnt;

	cnt = i;
	if (str[cnt] == '\0')
		return (1);
	while (str[cnt] != '\0')
		cnt++;
	return (cnt - i);
}

char			**ft_rest_after_first_c(char **tab, char const *s, int i)
{
	int j;
	int k;

	j = 1;
	k = 0;
	if (!(tab[j] = ft_memalloc(ft_cnt_len(s, i))))
		return (NULL);
	if (s[i] != '\0')
	{
		i++;
		while (s[i] != '\0')
			tab[j][k++] = s[i++];
	}
	tab[j][k] = '\0';
	return (tab);
}

char			**ft_strsplit_at_first_c(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	k = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * 2)))
		return (NULL);
	while (s[i] && s[i] != c)
		i++;
	if (!(tab[j] = ft_memalloc(i + 1)))
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		tab[j][k] = s[i];
		k++;
		i++;
	}
	tab[j][k] = '\0';
	tab = ft_rest_after_first_c(tab, s, i);
	return (tab);
}
