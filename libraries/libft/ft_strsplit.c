/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:18:01 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/22 16:21:10 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_cnt_decoupe(char const *s, char c)
{
	int		cpt;
	int		cnt;

	cpt = 0;
	cnt = 0;
	while (*s != '\0')
	{
		if (cpt == 1 && *s == c)
			cpt = 0;
		if (cpt == 0 && *s != c)
		{
			cpt = 1;
			cnt++;
		}
		s++;
	}
	return (cnt);
}

static int		ft_cnt_len(char const *str, int i, char c)
{
	int		cnt;

	cnt = i;
	while (str[cnt] && str[cnt] != c)
		cnt++;
	return (cnt - i);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(char*) * ft_cnt_decoupe(s, c) + 1)))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] && s[i] != c)
		{
			k = 0;
			if (!(tab[j] = ft_memalloc(ft_cnt_len(s, i, c) + 1)))
				return (NULL);
			while (s[i] && s[i] != c)
				tab[j][k++] = s[i++];
			tab[j++][k] = '\0';
		}
	}
	tab[j] = NULL;
	return (tab);
}
