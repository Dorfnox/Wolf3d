/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:32:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/08 16:56:25 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	free_map(t_map *map)
{
	unsigned int	i;

	i = 0;
	while (i < map->max_h + 1)
		free(map->map[i++]);
	free(map->map);
	free(map);
}

int			free_stuff(t_wolf *w)
{
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_image(w->mlx, w->win_screen->img);
	mlx_destroy_image(w->mlx, w->snow_screen->img);
	mlx_destroy_image(w->mlx, w->crosshair_x->img);
	mlx_destroy_image(w->mlx, w->crosshair_y->img);
	free(w->win_screen);
	free(w->snow_screen);
	free(w->crosshair_x);
	free(w->crosshair_y);
	free(w->kp);
	free(w->kr);
	free(WOLF);
	free(TRIG);
	free_map(MAP);
	free(w);
	system("killall afplay");
	return (1);
}
