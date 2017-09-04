/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:11:51 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 18:59:32 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H

# include "wolf3d_macros.h"
# include "libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <math.h>
# include <pthread.h>

# define W 1200
# define H 650

typedef struct		s_image
{
	void			*img;
	int				*pix;
	int				bpp;
	int				endian;
	int				w;
	int				h;
}					t_image;

typedef struct		s_mapcontains
{
	int				space;
	int				newline;
	int				wall;
	int				player;
	int				exit;
	int				eof;
}					t_mapcontains;

typedef struct		s_xy
{
	double			x;
	double			y;
}					t_xy;

typedef struct		s_xyz
{
	double			x;
	double			y;
	double			z;
}					t_xyz;

typedef struct		s_ray
{
	t_xyz			camera;
	t_xyz			pos;
	t_xyz			dir;
	t_xyz			side_dist;
	t_xyz			delta_dist;
	t_xyz			step;
	double			perp_wall_dist;
	unsigned int	wall_hit:4;
	unsigned int	side:4;
	int				vline_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct		s_map
{
	char			**map;
	unsigned int	max_h;
	unsigned int	ns_wall_colour;
	unsigned int	sn_wall_colour;
	unsigned int	ew_wall_colour;
	unsigned int	we_wall_colour;
	unsigned int	floor_colour;
	unsigned int	ceiling_colour;
	unsigned int	exit_colour;
}					t_map;

typedef struct		s_trig
{
	int				x;
	int				y;
	unsigned int	f:1;
	unsigned int	b:1;
	unsigned int	r:1;
	unsigned int	l:1;
	unsigned int	rr:1;
	unsigned int	rl:1;
	unsigned int	ims:1;
	unsigned int	dms:1;
	unsigned int	irs:1;
	unsigned int	drs:1;
	unsigned int	help:1;
	unsigned int	snow:1;
	t_xyz			mm;
}					t_trig;

typedef struct		s_player
{
	t_xyz			pos;
	t_xyz			dir;
	t_xyz			plane;
	t_xyz			dst;
	int				fba;
	int				rla;
	int				rrrla;
	int				acc;
	double			move_speed;
	double			rot_speed;
}					t_player;

typedef struct		s_wolf
{
	void			*mlx;
	void			*win;
	void			(**kp)(struct s_wolf *);
	void			(**kr)(struct s_wolf *);
	void			*win_screen;
	void			*snow_screen;
	struct s_trig	*t;
	struct s_player	*p;
	struct s_map	*map;
	struct s_image	*screen;
}					t_wolf;

/*
** On initialization functions -------------------------------------------------
*/

int					preliminary_char_check(char *map_name);
t_wolf				*initialize_wolf(void *mlx, char *map_name);
t_image				*new_image(t_wolf *w, int width, int height);
void				fill_image_with_colour(t_image *i, int c);
char				**load_map(t_map *m, char *map_name, int fd, int i);
void				set_arrays(t_wolf *w);
void				protect_array(t_wolf *w);
int					forever_loop(t_wolf *w);
int					expose_i_guess(t_wolf *w);

/*
** Program Runtime Environment -------------------------------------------------
*/
void				raycast(t_wolf *w);
void				draw_stuff(t_wolf *w);
void				help_screen(t_wolf *w);
void				*win_screen(t_wolf *w);
void				*snow_screen(t_wolf *w);
void				move_forward(t_wolf *w);
void				move_backward(t_wolf *w);
void				move_acceleratively(t_wolf *w);
void				move_left(t_wolf *w);
void				move_right(t_wolf *w);
void				strafe_acceleratively(t_wolf *w);
void				rotate_right(t_wolf *w);
void				rotate_left(t_wolf *w);
void				rotate_acceleratively(t_wolf *w);
void				increase_move_speed(t_wolf *w);
void				decrease_move_speed(t_wolf *w);
void				increase_rot_speed(t_wolf *w);
void				decrease_rot_speed(t_wolf *w);

/*
** On exit functions -----------------------------------------------------------
*/
int					free_stuff(t_wolf *w);
int					exit_window(t_wolf *w);

/*
** Hook functions --------------------------------------------------------------
**
** Key Press
*/
void				set_kp_array(void (**kp)(t_wolf *));
int					key_press(int keycode, t_wolf *w);

void				exit_window_kp(t_wolf *w);
void				change_wall_colour(t_wolf *w);
void				ice_mode(t_wolf *w);
void				trig_help_menu(t_wolf *w);
void				trig_move_forward(t_wolf *w);
void				trig_move_backward(t_wolf *w);
void				trig_move_left(t_wolf *w);
void				trig_move_right(t_wolf *w);
void				trig_rotate_right(t_wolf *w);
void				trig_rotate_left(t_wolf *w);
void				trig_increase_move_speed(t_wolf *w);
void				trig_decrease_move_speed(t_wolf *w);
void				trig_increase_rot_speed(t_wolf *w);
void				trig_decrease_rot_speed(t_wolf *w);

/*
** Key Release
*/
void				set_kr_array(void (**kp)(t_wolf *));
int					key_release(int keycode, t_wolf *w);

void				untrig_move_forward(t_wolf *w);
void				untrig_move_backward(t_wolf *w);
void				untrig_move_left(t_wolf *w);
void				untrig_move_right(t_wolf *w);
void				untrig_rotate_right(t_wolf *w);
void				untrig_rotate_left(t_wolf *w);
void				untrig_increase_move_speed(t_wolf *w);
void				untrig_decrease_move_speed(t_wolf *w);
void				untrig_increase_rot_speed(t_wolf *w);
void				untrig_decrease_rot_speed(t_wolf *w);

/*
** Mouse Press
*/
int					mouse_press(int button, int x, int y, t_wolf *w);

void				mouse_thingy(t_wolf *w, int x, int y);

/*
** Mouse Release
*/
int					mouse_release(int button, int x, int y, t_wolf *w);

void				mouse_release_thingy(t_wolf *w, int x, int y);

/*
** Mouse Move
*/
int					mouse_move(int x, int y, t_wolf *w);

void				trig_rotate_right(t_wolf *w);
void				trig_rotate_left(t_wolf *w);

#endif
