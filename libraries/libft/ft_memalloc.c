/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 22:04:43 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/22 16:20:33 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	char	*mem;

	if (!(mem = (char *)malloc(sizeof(char) * size)) || size == 0)
		return (NULL);
	ft_memset(mem, 0, size);
	return ((void *)mem);
}
