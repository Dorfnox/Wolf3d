/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 15:30:14 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 19:22:38 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		initialize_hooks(t_wolf *w)
{
	mlx_do_key_autorepeatoff(w->mlx);
	mlx_hook(w->win, 2, 0, key_press, w);
	mlx_hook(w->win, 3, 0, key_release, w);
	mlx_hook(w->win, 4, 0, mouse_press, w);
	mlx_hook(w->win, 5, 0, mouse_release, w);
	mlx_hook(w->win, 6, 0, mouse_move, w);
	mlx_hook(w->win, 12, 0, expose_i_guess, w);
	mlx_hook(w->win, 17, 0, exit_window, w);
	mlx_loop_hook(w->mlx, forever_loop, w);
}

static t_map	*new_t_map(char *map_name)
{
	t_map	*map;

	if (!(map = (t_map *)ft_memalloc(sizeof(t_map))))
		return (ft_putnull("Failed to malloc space for t_map *... "));
	if (!(map->map = load_map(map, map_name, 0, 0)))
		return (ft_putnull("Failed to load map... "));
	map->ns_wall_colour = 0xCAAF3E;
	map->ew_wall_colour = 0xF3E77E;
	map->sn_wall_colour = 0x37B177;
	map->we_wall_colour = 0xA3F71E;
	map->floor_colour = 0x939393;
	map->ceiling_colour = 0x393939;
	map->exit_colour = 0xFF0000;
	return (map);
}

static t_player	*new_t_player(t_map *m, int x, int y, int line_len)
{
	t_player	*mrwolf;

	if (!(mrwolf = (t_player *)ft_memalloc(sizeof(t_player))))
		return (ft_putnull("Failed to malloc space for t_player *... "));
	while (++y < (int)m->max_h)
	{
		x = -1;
		line_len = (int)ft_strlen(m->map[y]);
		while (++x < line_len)
		{
			if (m->map[y][x] == 'P')
				mrwolf->pos.x = x;
			if (m->map[y][x] == 'P')
				mrwolf->pos.y = y;
			if (m->map[y][x] == 'E')
				mrwolf->dst.x = x;
			if (m->map[y][x] == 'E')
				mrwolf->dst.y = y;
		}
	}
	mrwolf->dir.x = 1;
	mrwolf->plane.y = 0.66;
	mrwolf->move_speed = 1;
	mrwolf->rot_speed = 3;
	return (mrwolf);
}

t_wolf			*initialize_wolf(void *mlx, char *map_name)
{
	t_wolf	*new;

	if (!(new = (t_wolf *)ft_memalloc(sizeof(t_wolf))))
		return (ft_putnull("Failed to malloc space for t_wolf *... "));
	if (!(new->t = (t_trig *)ft_memalloc(sizeof(t_trig))))
		return (ft_putnull("Failed to malloc space for t_trig *... "));
	if (!(new->map = new_t_map(map_name)))
		return (ft_putnull("new_t_map failed to return properly... "));
	if (!(new->p = new_t_player(new->map, -1, -1, -1)))
		return (ft_putnull("new_t_player failed to return properly... "));
	new->mlx = mlx;
	new->win = mlx_new_window(new->mlx, W, H, "Fun Times at Wolf3d High");
	new->screen = new_image(new, W, H);
	set_arrays(new);
	new->win_screen = win_screen(new);
	new->snow_screen = snow_screen(new);
	initialize_hooks(new);
	rotate_left(new);
	new->p->acc = 5;
	return (new);
}
