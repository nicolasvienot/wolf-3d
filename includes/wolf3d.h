/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:06:30 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 18:21:20 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include <SDL.h>
# include <SDL_image.h>
# include <SDL_ttf.h>
# include <SDL_mixer.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <pthread.h>
# include <fcntl.h>
# include "libft.h"
# include "w3d_defines.h"
# include "w3d_structs.h"

/*
** anim.c
*/

void	end_anim(t_win *win);
void	firing(t_win *win);
void	reload(t_win *win);

/*
** calc.c
*/

void	*calc(void *thrds);

/*
** draw.c
*/

void	draw_crosshair(SDL_Surface *surface);
void	draw_line_ver(SDL_Surface *surf, t_render *r, int y1, int y2);
Uint32	get_pixel_from_surface(SDL_Surface *surface, int x, int y);
void	put_pixel_to_surface(SDL_Surface *surface, \
			int x, int y, Uint32 color);

/*
** exit.c
*/

void	free_surface(t_win *win);
int		clear_n_exit(t_win *win, int error);

/*
** fps.c
*/

int		fps(t_win *win);

/*
** init.c
*/

int		init(t_win *win);

/*
** loop.c
*/

void	loop_menu(t_win *win);
void	loop_play(t_win win);
void	loop_intro(t_win *win);

/*
** main.c
*/

int		main(int argc, char **argv);

/*
** minimap.c
*/

void	draw_bloc(t_win *win, int i, int j);
void	draw_minimap(t_win *win);

/*
** minimap2.c
*/

void	minimap2(t_win *win);

/*
** multithreading.c
*/

void	multithreading(t_win *win);

/*
** parser.c
*/

char	**get_map(char *av, t_win *win);

/*
** parser2.c
*/

char	**fill_map(int fd, char **map, int maxlen);
int		info_file(int fd, int *nblines);

/*
** print.c
*/

int		print_menu(t_win *win);
int		print_game(t_win *win);
int		print_intro(t_win *win);

/*
** sdl_event.c
*/

void	key_sensi(t_win *win);
void	sdl_event(t_win *win);

/*
** sdl_event2.c
*/

void	key_y(t_win *win);
void	key_r_tab(t_win *win);
void	key_t_lshift(t_win *win);
void	key_right_left(t_win *win);
void	key_up_down(t_win *win);

/*
** sdl_event3.c
*/

void	key_w_s(t_win *win);
void	key_a_d(t_win *win);
void	key_e_m(t_win *win);
void	key_n_rshift(t_win *win);
void	key_1_2_3(t_win *win);

/*
** test_walls.c
*/

void	calc_wall_height(t_win *win, t_render *r);
void	test_walls_ver_right(t_win *win, t_render *r);
void	test_walls_ver_left(t_win *win, t_render *r);
void	test_walls_hor_down(t_win *win, t_render *r);
void	test_walls_hor_up(t_win *win, t_render *r);

/*
** textures.c
*/

void	choose_texture(t_win *win);
Uint32	get_wall_tex(t_render *r, t_win *win, int y);
Uint32	get_floor_tex(t_render *r, t_win *win, int y, int type);

/*
** utils.c
*/

int		secure_tex_x(int tex_x, int surface_w);
int		secure_tex_y(int tex_y, int surface_h);
int		check_map(t_win *win);
void	put_map(char **map);

#endif
