/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:32:41 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 15:30:01 by bpierce          ###   ########.fr       */
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
	free(w->kp);
	free(w->kr);
	free(WOLF);
	free(TRIG);
	free_map(MAP);
	free(w);
	return (1);
}