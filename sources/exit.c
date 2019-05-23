/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:10:22 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 19:10:12 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		free_surface(t_win *win)
{
	SDL_FreeSurface(win->ceiling);
	SDL_FreeSurface(win->floor);
	SDL_FreeSurface(win->side1);
	SDL_FreeSurface(win->side2);
	SDL_FreeSurface(win->side3);
	SDL_FreeSurface(win->side4);
}

static void	free_map(t_win *win)
{
	int		i;

	if (win->map)
	{
		i = 0;
		while (i < win->map_height)
		{
			free(win->map[i]);
			win->map[i] = NULL;
			i++;
		}
		free(win->map);
		win->map = NULL;
	}
}

static void	put_error_2(int error)
{
	if (error == 10)
		ft_putendl(ERR_10);
	else if (error == 11)
		ft_putendl(ERR_11);
	else if (error == 12)
		ft_putendl(ERR_12);
	else if (error == 13)
		ft_putendl(ERR_13);
	else if (error == 14)
		ft_putendl(ERR_14);
	else if (error == 15)
		ft_putendl(ERR_15);
	else if (error == 16)
		ft_putendl(ERR_16);
	else if (error == 17)
		ft_putendl(ERR_17);
	else if (error == 18)
		ft_putendl(ERR_18);
	else if (error == 19)
		ft_putendl(ERR_19);
}

static void	put_error(int error)
{
	if (error == 0)
		return ;
	else if (error == 1)
		ft_putendl(ERR_1);
	else if (error == 2)
		ft_putendl(ERR_2);
	else if (error == 3)
		ft_putendl(ERR_3);
	else if (error == 4)
		ft_putendl(ERR_4);
	else if (error == 5)
		ft_putendl(ERR_5);
	else if (error == 6)
		ft_putendl(ERR_6);
	else if (error == 7)
		ft_putendl(ERR_7);
	else if (error == 8)
		ft_putendl(ERR_8);
	else if (error == 9)
		ft_putendl(ERR_9);
	else
		put_error_2(error);
}

int			clear_n_exit(t_win *win, int error)
{
	put_error(error);
	if (win->surface != NULL)
		SDL_FreeSurface(win->surface);
	if (win->renderer != NULL)
		SDL_DestroyRenderer(win->renderer);
	if (win->window != NULL)
		SDL_DestroyWindow(win->window);
	if (win->police != NULL)
		TTF_CloseFont(win->police);
	if (win->theme != NULL)
		Mix_FreeMusic(win->theme);
	if (win->headshot != NULL)
		Mix_FreeChunk(win->headshot);
	if (win->medic != NULL)
		Mix_FreeChunk(win->medic);
	if (win->ceiling != NULL)
		free_surface(win);
	Mix_CloseAudio();
	TTF_Quit();
	SDL_Quit();
	if (win->map != NULL && win->secu == 1)
		free_map(win);
	if (error > 0)
		exit(EXIT_FAILURE);
	exit(EXIT_SUCCESS);
}
