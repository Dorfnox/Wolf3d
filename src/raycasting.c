/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/25 22:22:26 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 18:59:04 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	draw_vline_to_image(t_wolf *w, t_ray *r, int x, int y)
{
	int	colour;

	if (r->side == NS_WALL && r->wall_hit != EX_WALL)
	{
		colour = ft_shade_colour(r->step.x > 0 ? MAP->ns_wall_colour
				: MAP->sn_wall_colour, r->perp_wall_dist, 0.2);
	}
	else if (r->side == EW_WALL && r->wall_hit != EX_WALL)
	{
		colour = ft_shade_colour(r->step.y > 0 ? MAP->ew_wall_colour
				: MAP->we_wall_colour, r->perp_wall_dist, 0.2);
	}
	else
		colour = ft_shade_colour(MAP->exit_colour, r->perp_wall_dist, 0.2);
	while (++y < H)
	{
		if (y < r->draw_start)
			PIXEL = MAP->floor_colour;
		else if (y > r->draw_end)
			PIXEL = MAP->ceiling_colour;
		else
			PIXEL = colour;
	}
}

static void	starting_stuff(t_wolf *w, t_ray *r, int *mapx, int *mapy)
{
	r->pos.x = WOLF->pos.x;
	r->pos.y = WOLF->pos.y;
	r->dir.x = WOLF->dir.x + WOLF->plane.x * r->camera.x;
	r->dir.y = WOLF->dir.y + WOLF->plane.y * r->camera.x;
	*mapx = (int)r->pos.x;
	*mapy = (int)r->pos.y;
	r->delta_dist.x = sqrt(1 + (r->dir.y * r->dir.y) / (r->dir.x * r->dir.x));
	r->delta_dist.y = sqrt(1 + (r->dir.x * r->dir.x) / (r->dir.y * r->dir.y));
	r->wall_hit = 0;
	r->step.x = (r->dir.x < 0) ? -1 : 1;
	r->side_dist.x = ((r->dir.x < 0) ? (r->pos.x - *mapx) :
			(*mapx + 1 - r->pos.x)) * r->delta_dist.x;
	r->step.y = (r->dir.y < 0) ? -1 : 1;
	r->side_dist.y = ((r->dir.y < 0) ? (r->pos.y - *mapy) :
			(*mapy + 1 - r->pos.y)) * r->delta_dist.y;
}

static void	digital_differential_analysis(t_wolf *w, t_ray *r,
		int *mapx, int *mapy)
{
	while (r->wall_hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			*mapx += r->step.x;
			r->side = NS_WALL;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			*mapy += r->step.y;
			r->side = EW_WALL;
		}
		if (w->map->map[*mapy][*mapx] == '1')
			r->wall_hit = 1;
		else if (w->map->map[*mapy][*mapx] == 'E')
			r->wall_hit = EX_WALL;
	}
}

void		raycast(t_wolf *w)
{
	t_ray	r;
	int		mapx;
	int		mapy;
	int		x;

	x = -1;
	while (++x < W)
	{
		r.camera.x = 2 * x / (double)W - 1;
		starting_stuff(w, &r, &mapx, &mapy);
		digital_differential_analysis(w, &r, &mapx, &mapy);
		if (r.side == NS_WALL)
			r.perp_wall_dist = (mapx - r.pos.x + (1 - r.step.x) / 2) / r.dir.x;
		else
			r.perp_wall_dist = (mapy - r.pos.y + (1 - r.step.y) / 2) / r.dir.y;
		r.vline_height = (int)(H * 2 / r.perp_wall_dist);
		if ((r.draw_start = (-r.vline_height / 2) + (H / 2)) < 0)
			r.draw_start = 0;
		if ((r.draw_end = r.vline_height / 2 + H / 2) >= H)
			r.draw_end = H - 1;
		draw_vline_to_image(w, &r, x, -1);
	}
}
