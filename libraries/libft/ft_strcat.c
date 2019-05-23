/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 13:10:08 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/13 17:16:44 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	char	*d;

	d = dest;
	while (*d)
		d++;
	while (*src)
		*d++ = *src++;
	*d = '\0';
	return (dest);
}
