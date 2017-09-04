/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/28 13:05:20 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 18:58:37 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	do_rotate_i_guess(t_wolf *w)
{
	double	tmp_rot;

	tmp_rot = WOLF->rot_speed;
	WOLF->rot_speed *= (TRIG->mm.x < 0) ? (-TRIG->mm.x / 100) :
		(TRIG->mm.x / 100);
	if (TRIG->mm.x > 0)
		rotate_right(w);
	else if (TRIG->mm.x < 0)
		rotate_left(w);
	WOLF->rot_speed = tmp_rot;
	TRIG->mm.x = 0;
	TRIG->mm.y = 0;
}

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
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i - 300) % W, (i * 2 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i % W), (i * 3 - 100) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 50) % W, (i * 2 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 150) % W, (i * 3 - 600) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 250) % W, (i * 2) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 400) % W, (i * 3 - 400) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 550) % W, (i - 250) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 750) % W, (i * 3 - 50) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 900) % W, (i - 500) % H);
	mlx_put_image_to_window(w->mlx, w->win, w->snow_screen,
			(i + 1000) % W, (i * 3 - 500) % H);
	if (i > 1000000000)
		i = 0;
}

void		draw_stuff(t_wolf *w)
{
	raycast(w);
	mlx_put_image_to_window(w->mlx, w->win, w->screen->img, 0, 0);
	if (AB(WOLF->pos.x - WOLF->dst.x) < 1 && AB(WOLF->pos.y - WOLF->dst.y) < 1)
		mlx_put_image_to_window(w->mlx, w->win, w->win_screen, 200, 0);
	if (TRIG->help == 1)
		help_screen(w);
}

int			forever_loop(t_wolf *w)
{
	if (TRIG->ims == 1 || TRIG->dms == 1 || TRIG->irs == 1 || TRIG->drs == 1)
	{
		speed_up_or_down_player(w);
		draw_stuff(w);
	}
	if (TRIG->mm.x != 0 ||
			TRIG->f == 1 || TRIG->b == 1 ||
			TRIG->l == 1 || TRIG->r == 1 ||
			TRIG->rr == 1 || TRIG->rl == 1 ||
			WOLF->fba != 0 || WOLF->rla != 0 || WOLF->rrrla != 0)
	{
		if (TRIG->mm.x != 0)
			do_rotate_i_guess(w);
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
