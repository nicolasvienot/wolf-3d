/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_max.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 23:58:53 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 19:28:41 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>
#include <stdlib.h>

t_liste		*gestion_list(t_liste *tmp, int fd, t_liste **list)
{
	t_liste				*new;

	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		if (tmp->next == NULL)
			break ;
		tmp = tmp->next;
	}
	if (!(new = (t_liste *)malloc(sizeof(t_liste))))
		return (NULL);
	new->fd = fd;
	if ((new->buftemp = ft_strnew(0)) == NULL)
		return (NULL);
	new->next = NULL;
	if (tmp)
		tmp->next = new;
	else
		*list = new;
	return (new);
}

int			ft_read(char **str, int fd)
{
	int					i;
	char				*linetmp;
	char				*buf;
	int					drop;

	drop = 0;
	if (!(buf = (char*)malloc(sizeof(char*) * (BUFF_SIZE + 1))))
		return (-1);
	while ((ft_strchr(*str, '\n')) == NULL)
	{
		if ((i = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		buf[i] = '\0';
		linetmp = *str;
		if ((*str = ft_strjoin(*str, buf)) == NULL)
			return (-1);
		free(linetmp);
		if (i == 0 || drop > 10)
			break ;
		drop++;
	}
	free(buf);
	return (i);
}

void		ft_end_of_file(t_liste *tmp, t_liste **list)
{
	t_liste		*tmp2;

	if (tmp == *list)
	{
		*list = (*list)->next;
		free(tmp->buftemp);
		free(tmp);
	}
	else
	{
		tmp2 = *list;
		while (tmp2->next != tmp)
			tmp2 = tmp2->next;
		tmp2->next = tmp->next;
		free(tmp->buftemp);
		free(tmp);
	}
	return ;
}

int			get_next_line_max(const int fd, char **line)
{
	static t_liste		*list;
	t_liste				*tmp;
	int					i;
	char				*str;
	char				**tab;

	if (fd == 1 || !line)
		return (-1);
	tmp = list;
	tmp = gestion_list(tmp, fd, &list);
	if ((str = ft_strdup(tmp->buftemp)) == NULL)
		return (-1);
	if ((i = ft_read(&str, fd)) < 0)
		return (-1);
	if ((tab = ft_strsplit_at_first_c(str, EOL)) == NULL)
		return (-1);
	free(str);
	*line = tab[0];
	if (tmp->buftemp)
		free(tmp->buftemp);
	tmp->buftemp = tab[1];
	if (i == 0 && *line[0] == '\0')
		ft_end_of_file(tmp, &list);
	free(tab);
	return ((i == 0 && *line[0] == '\0') ? 0 : 1);
}
