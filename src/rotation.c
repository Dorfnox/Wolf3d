/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 14:23:35 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 19:38:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	rotate_right(t_wolf *w)
{
	double		old_dirx;
	double		old_planex;
	double		new_rot_speed;

	new_rot_speed = ft_percentof(WOLF->rot_speed, WOLF->rrrla) / 100;
	old_dirx = WOLF->dir.x;
	WOLF->dir.x = (old_dirx * cos(new_rot_speed)) -
		(WOLF->dir.y * sin(new_rot_speed));
	WOLF->dir.y = (old_dirx * sin(new_rot_speed)) +
		(WOLF->dir.y * cos(new_rot_speed));
	old_planex = WOLF->plane.x;
	WOLF->plane.x = (old_planex * cos(new_rot_speed)) -
		(WOLF->plane.y * sin(new_rot_speed));
	WOLF->plane.y = (old_planex * sin(new_rot_speed)) +
		(WOLF->plane.y * cos(new_rot_speed));
}

void	rotate_left(t_wolf *w)
{
	double		old_dirx;
	double		old_planex;
	double		new_rot_speed;

	new_rot_speed = ft_percentof(WOLF->rot_speed, AB(WOLF->rrrla)) / 100;
	old_dirx = WOLF->dir.x;
	WOLF->dir.x = (old_dirx * cos(-new_rot_speed)) -
		(WOLF->dir.y * sin(-new_rot_speed));
	WOLF->dir.y = (old_dirx * sin(-new_rot_speed)) +
		(WOLF->dir.y * cos(-new_rot_speed));
	old_planex = WOLF->plane.x;
	WOLF->plane.x = (old_planex * cos(-new_rot_speed)) -
		(WOLF->plane.y * sin(-new_rot_speed));
	WOLF->plane.y = (old_planex * sin(-new_rot_speed)) +
		(WOLF->plane.y * cos(-new_rot_speed));
}

void	rotate_acceleratively(t_wolf *w)
{
	if ((TRIG->rr || TRIG->rl) && !(TRIG->rr && TRIG->rl))
	{
		if (TRIG->rr)
			WOLF->rrrla += (WOLF->rrrla < 100) ? 20 : 0;
		else if (TRIG->rl)
			WOLF->rrrla -= (WOLF->rrrla > -100) ? 20 : 0;
		if (WOLF->rrrla != 0)
			(WOLF->rrrla > 0) ? rotate_right(w) : rotate_left(w);
	}
	else
	{
		if (WOLF->rrrla != 0)
			WOLF->rrrla += (WOLF->rrrla < 0) ? 20 : -20;
		if (WOLF->rrrla != 0)
			(WOLF->rrrla > 0) ? rotate_right(w) : rotate_left(w);
	}
}
