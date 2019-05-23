/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   w3d_structs.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nvienot <nvienot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/17 16:06:30 by nvienot           #+#    #+#             */
/*   Updated: 2019/05/22 17:02:40 by nvienot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef W3D_STRUCTS_H
# define W3D_STRUCTS_H

typedef struct s_win	t_win;
typedef struct s_mthrds	t_mthrds;
typedef struct s_thrd	t_thrd;
typedef struct s_render	t_render;

struct					s_render
{
	Uint32				color;
	Uint32				color_h;
	Uint32				color_v;
	int					x;
	int					draw_start;
	int					draw_end;
	int					line_height;
	int					hit;
	int					side;
	int					floor_tex_x;
	int					floor_tex_y;
	double				ray_angle;
	double				ray_angle_rad;
	double				alph_angle_rad;
	double				alph_angle;
	double				player_x;
	double				player_y;
	double				hor_x;
	double				hor_y;
	double				ver_x;
	double				ver_y;
	double				final_x;
	double				final_y;
	double				step_x;
	double				step_y;
	double				dist_ver;
	double				dist_wall;
	double				dist_hor;
	double				dist;
	double				current_dist;
	double				dist_player;
	double				dist_floor;
	double				wall_height;
	double				floor_x_wall;
	double				floor_y_wall;
	double				current_floor_x;
	double				current_floor_y;
};

struct					s_thrd
{
	int					id;
	t_win				*w;
};

struct					s_mthrds
{
	pthread_t			threads[NB_THREADS];
	t_thrd				thrd[NB_THREADS];
};

struct					s_win
{
	t_mthrds			mthrds;
	SDL_Window			*window;
	SDL_Renderer		*renderer;
	SDL_Texture			*texture;
	SDL_Surface			*surface;
	SDL_Surface			*ceiling;
	SDL_Surface			*floor;
	SDL_Surface			*txtfps;
	SDL_Surface			*txtintro;
	SDL_Surface			*txtammo;
	SDL_Surface			*txtsensi;
	SDL_Surface			*txttext;
	SDL_Surface			*gun;
	SDL_Surface			*intro;
	SDL_Surface			*menu;
	SDL_Surface			*side1;
	SDL_Surface			*side2;
	SDL_Surface			*side3;
	SDL_Surface			*side4;
	SDL_Event			event;
	SDL_Color			color_font_r;
	SDL_Color			color_font_o;
	SDL_Rect			dst;
	SDL_Rect			dst2;
	SDL_Rect			dst3;
	SDL_Rect			dst4;
	SDL_Rect			dst5;
	SDL_Rect			dst6;
	SDL_Rect			dst7;
	SDL_Rect			dst8;
	Mix_Music			*theme;
	Mix_Chunk			*headshot;
	Mix_Chunk			*medic;
	TTF_Font			*police;
	Uint32				start_clock;
	Uint32				delta_clock;
	Uint32				current_fps;
	Uint8				*keystate;
	char				**map;
	unsigned int		firing;
	int					resize;
	int					tex;
	int					map_width;
	int					map_height;
	int					h_win;
	int					w_win;
	int					h_win_tmp;
	int					w_win_tmp;
	int					minimap;
	int					minimap_style;
	int					reloading;
	int					ammo1;
	int					ammo2;
	int					text;
	int					aff;
	int					tmp_time;
	int					act_time;
	int					mx;
	int					my;
	int					secu;
	double				pos_x;
	double				pos_y;
	double				move_speed;
	double				vertical_mouse;
	double				sensibility_hor;
	double				sensibility_ver;
	double				sensibility_move;
	double				dir_player;
};

#endif
