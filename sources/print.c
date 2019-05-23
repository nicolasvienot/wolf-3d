/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/26 21:07:38 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 19:14:42 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	choose_style(t_win *win)
{
	if (win->text == 2)
		win->txttext = TTF_RenderText_Blended(win->police, \
			"Wolf3D", win->color_font_o);
	else if (win->text == 3)
		win->txttext = TTF_RenderText_Blended(win->police, \
			"Minecraft", win->color_font_o);
	else
		win->txttext = TTF_RenderText_Blended(win->police, \
			"TF2", win->color_font_o);
}

static void	set_window(t_win *win)
{
	if (win->h_win_tmp != win->h_win || win->w_win_tmp != win->w_win)
	{
		if (win->w_win_tmp != win->w_win && win->h_win_tmp == win->h_win)
		{
			win->h_win = win->w_win / 16 * 9;
			win->dst2.x = 0;
			win->dst2.y = 0;
			win->dst2.w = win->w_win;
			win->dst2.h = win->h_win;
			win->h_win_tmp = win->h_win;
			win->w_win_tmp = win->w_win;
			SDL_SetWindowSize(win->window, win->w_win, win->h_win);
		}
		else
		{
			win->w_win = win->h_win * 16 / 9;
			win->dst2.x = 0;
			win->dst2.y = 0;
			win->dst2.w = win->w_win;
			win->dst2.h = win->h_win;
			win->h_win_tmp = win->h_win;
			win->w_win_tmp = win->w_win;
			SDL_SetWindowSize(win->window, win->w_win, win->h_win);
		}
	}
}

int			print_menu(t_win *win)
{
	char	*sensitoa;

	if ((sensitoa = ft_itoa((int)(win->sensibility_hor * 100))) == NULL)
		clear_n_exit(win, 18);
	win->txtsensi = TTF_RenderText_Blended(win->police,
		sensitoa, win->color_font_o);
	free(sensitoa);
	if ((SDL_BlitSurface(win->txtsensi, NULL, win->surface, &win->dst8)) < 0)
		clear_n_exit(win, 19);
	SDL_FreeSurface(win->txtsensi);
	win->dst5.x = 620;
	win->dst5.y = 680;
	choose_style(win);
	if ((SDL_BlitSurface(win->txttext, NULL, win->surface, &win->dst5)) < 0)
		clear_n_exit(win, 19);
	SDL_FreeSurface(win->txttext);
	win->texture = SDL_CreateTextureFromSurface(win->renderer, win->surface);
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_GetWindowSize(win->window, &win->w_win, &win->h_win);
	set_window(win);
	if ((SDL_RenderCopy(win->renderer, win->texture, NULL, &win->dst2)) < 0)
		clear_n_exit(win, 17);
	SDL_RenderPresent(win->renderer);
	SDL_DestroyTexture(win->texture);
	return (0);
}

int			print_game(t_win *win)
{
	draw_crosshair(win->surface);
	if ((SDL_BlitSurface(win->gun, NULL, win->surface, &win->dst3)) < 0)
		clear_n_exit(win, 19);
	if (win->reloading == 0 && win->firing == 0)
	{
		win->dst3.x = (WIN_X / 2 - 370 / 8);
		win->dst3.y = (WIN_Y - 305);
	}
	win->texture = SDL_CreateTextureFromSurface(win->renderer, win->surface);
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_GetWindowSize(win->window, &win->w_win, &win->h_win);
	set_window(win);
	if ((SDL_RenderCopy(win->renderer, win->texture, NULL, &win->dst2)) < 0)
		clear_n_exit(win, 17);
	SDL_RenderPresent(win->renderer);
	SDL_DestroyTexture(win->texture);
	end_anim(win);
	firing(win);
	return (0);
}

int			print_intro(t_win *win)
{
	win->texture = SDL_CreateTextureFromSurface(win->renderer, win->surface);
	SDL_SetRenderTarget(win->renderer, NULL);
	SDL_GetWindowSize(win->window, &win->w_win, &win->h_win);
	set_window(win);
	if ((SDL_RenderCopy(win->renderer, win->texture, NULL, &win->dst2)) < 0)
		clear_n_exit(win, 17);
	SDL_RenderPresent(win->renderer);
	SDL_DestroyTexture(win->texture);
	return (0);
}
