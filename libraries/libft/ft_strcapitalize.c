/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 21:23:06 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/20 16:09:00 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	int i;
	int cpt;

	i = 0;
	cpt = 1;
	while (str[i] != '\0')
	{
		if (ft_isnumber(str[i]) == 1 || ft_islower(str[i]) == 1 \
			|| ft_isupper(str[i]) == 1)
		{
			if (cpt && ft_islower(str[i]) == 1)
				str[i] = str[i] - 32;
			else if (!cpt && ft_isupper(str[i]) == 1)
				str[i] = str[i] + 32;
			cpt = 0;
		}
		else
			cpt = 1;
		i++;
	}
	return (str);
}
