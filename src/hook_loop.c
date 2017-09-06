/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:05:20 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/05 16:13:43 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	speed_up_or_down_player(t_wolf *w)
{
	if (TRIG->ims)
		increase_move_speed(w);
	if (TRIG->dms)
		decrease_move_speed(w);
	if (TRIG->irs)
		increase_rot_speed(w);
	if (TRIG->drs)
		decrease_rot_speed(w);
}

static void	draw_snow(t_wolf *w)
{
	static int	i;

	i += 1;
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i - 300) % W, (i * 2 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i % W), (i * 3 - 100) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 50) % W, (i * 2 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 150) % W, (i * 3 - 600) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 250) % W, (i * 2) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 400) % W, (i * 3 - 400) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 550) % W, (i - 250) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 750) % W, (i * 3 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 900) % W, (i - 500) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen->img,
			(i + 1000) % W, (i * 3 - 500) % H);
	if (i > 1000000000)
		i = 0;
}

void		draw_stuff(t_wolf *w)
{
	raycast(w);
	mlx_put_image_to_window(w->mlx, w->win, w->screen->img, 0, 0);
	if (AB(WOLF->pos.x - WOLF->dst.x) < 2 && AB(WOLF->pos.y - WOLF->dst.y) < 2)
		mlx_put_image_to_window(w->mlx, w->win, w->win_screen->img, 200, 0);
	if (TRIG->help == 1)
	{
		help_screen(w);
		mlx_put_image_to_window(w->mlx, w->win, w->crosshair_x->img,
				(W / 2) - 10, H / 2);
		mlx_put_image_to_window(w->mlx, w->win, w->crosshair_y->img,
				W / 2, (H / 2) - 10);
	}
}

int			forever_loop(t_wolf *w)
{
	if (TRIG->ims == 1 || TRIG->dms == 1 || TRIG->irs == 1 || TRIG->drs == 1)
	{
		speed_up_or_down_player(w);
		draw_stuff(w);
	}
	if (TRIG->f == 1 || TRIG->b == 1 ||
			TRIG->l == 1 || TRIG->r == 1 ||
			TRIG->rr == 1 || TRIG->rl == 1 ||
			WOLF->fba != 0 || WOLF->rla != 0 || WOLF->rrrla != 0)
	{
		rotate_acceleratively(w);
		strafe_acceleratively(w);
		move_acceleratively(w);
		draw_stuff(w);
	}
	if (TRIG->snow == 1)
	{
		draw_stuff(w);
		draw_snow(w);
	}
	return (1);
}
