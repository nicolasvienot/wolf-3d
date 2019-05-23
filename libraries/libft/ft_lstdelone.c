/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:09:00 by nvienot           #+#    #+#             */
/*   Updated: 2018/12/04 18:17:34 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (*alst && del)
	{
		(del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void**)alst);
	}
	return ;
}
