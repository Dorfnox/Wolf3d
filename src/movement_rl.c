/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_rl.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:05:06 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 18:28:14 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_right(t_wolf *w)
{
	double	planex;
	double	planey;

	planex = ft_percentof(WOLF->plane.x, WOLF->rla);
	planey = ft_percentof(WOLF->plane.y, WOLF->rla);
	if ((int)(WOLF->pos.x + WOLF->plane.x) > 0 && (RT_X == ' ' || RT_X == 'P'))
		WOLF->pos.x += planex * (WOLF->move_speed / 10);
	else
		WOLF->rla = (WOLF->rla > 25) ? 25 : WOLF->rla;
	if ((int)(WOLF->pos.y + WOLF->plane.y) > 0 && (RT_Y == ' ' || RT_Y == 'P'))
		WOLF->pos.y += planey * (WOLF->move_speed / 10);
	else
		WOLF->rla = (WOLF->rla > 25) ? 25 : WOLF->rla;
}

void		move_left(t_wolf *w)
{
	double	planex;
	double	planey;

	planex = ft_percentof(WOLF->plane.x, AB(WOLF->rla));
	planey = ft_percentof(WOLF->plane.y, AB(WOLF->rla));
	if ((int)(WOLF->pos.x - WOLF->plane.x) > 0 && (LT_X == ' ' || LT_X == 'P'))
		WOLF->pos.x -= planex * (WOLF->move_speed / 10);
	else
		WOLF->rla = (WOLF->rla < -25) ? -25 : WOLF->rla;
	if ((int)(WOLF->pos.y - WOLF->plane.y) > 0 && (LT_Y == ' ' || LT_Y == 'P'))
		WOLF->pos.y -= planey * (WOLF->move_speed / 10);
	else
		WOLF->rla = (WOLF->rla < -25) ? -25 : WOLF->rla;
}

void		strafe_acceleratively(t_wolf *w)
{
	if ((TRIG->r || TRIG->l) && !(TRIG->r && TRIG->l))
	{
		if (TRIG->r)
			WOLF->rla += (WOLF->rla < 100) ? WOLF->acc : 0;
		else if (TRIG->l)
			WOLF->rla -= (WOLF->rla > -100) ? WOLF->acc : 0;
		if (WOLF->rla != 0)
			(WOLF->rla > 0) ? move_right(w) : move_left(w);
	}
	else
	{
		if (WOLF->rla != 0)
			WOLF->rla += (WOLF->rla < 0) ? WOLF->acc : -WOLF->acc;
		if (WOLF->rla != 0)
			(WOLF->rla > 0) ? move_right(w) : move_left(w);
	}
}
