/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 15:13:38 by nvienot           #+#    #+#             */
/*   Updated: 2018/11/20 17:02:21 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;

	if (!lst || !f)
		return (NULL);
	lst2 = (f)(lst);
	if (lst2 && lst->next)
		lst2->next = ft_lstmap(lst->next, f);
	return (lst2);
}
