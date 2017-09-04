/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_fb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 14:35:05 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 18:40:10 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		move_forward(t_wolf *w)
{
	double	dirx;
	double	diry;

	dirx = ft_percentof(WOLF->dir.x, WOLF->fba);
	diry = ft_percentof(WOLF->dir.y, WOLF->fba);
	if ((int)(WOLF->pos.x + WOLF->dir.x) > 0 && (NXT_X == ' ' || NXT_X == 'P'))
		WOLF->pos.x += dirx * (WOLF->move_speed / 10);
	else
		WOLF->fba = (WOLF->fba > 25) ? 25 : WOLF->fba;
	if ((int)(WOLF->pos.y + WOLF->dir.y) > 0 && (NXT_Y == ' ' || NXT_Y == 'P'))
		WOLF->pos.y += diry * (WOLF->move_speed / 10);
	else
		WOLF->fba = (WOLF->fba > 25) ? 25 : WOLF->fba;
}

void		move_backward(t_wolf *w)
{
	double	dirx;
	double	diry;

	dirx = ft_percentof(WOLF->dir.x, AB(WOLF->fba));
	diry = ft_percentof(WOLF->dir.y, AB(WOLF->fba));
	if ((int)(WOLF->pos.x - WOLF->dir.x) > 0 && (PRV_X == ' ' || PRV_X == 'P'))
		WOLF->pos.x -= dirx * (WOLF->move_speed / 10);
	else
		WOLF->fba = (WOLF->fba < -25) ? -25 : WOLF->fba;
	if ((int)(WOLF->pos.y - WOLF->dir.y) > 0 && (PRV_Y == ' ' || PRV_Y == 'P'))
		WOLF->pos.y -= diry * (WOLF->move_speed / 10);
	else
		WOLF->fba = (WOLF->fba < -25) ? -25 : WOLF->fba;
}

void		move_acceleratively(t_wolf *w)
{
	if ((TRIG->f || TRIG->b) && !(TRIG->f && TRIG->b))
	{
		if (TRIG->f)
			WOLF->fba += (WOLF->fba < 100) ? WOLF->acc : 0;
		else if (TRIG->b)
			WOLF->fba -= (WOLF->fba > -100) ? WOLF->acc : 0;
		if (WOLF->fba != 0)
			(WOLF->fba > 0) ? move_forward(w) : move_backward(w);
	}
	else
	{
		if (WOLF->fba != 0)
			WOLF->fba += (WOLF->fba < 0) ? WOLF->acc : -WOLF->acc;
		if (WOLF->fba != 0)
			(WOLF->fba > 0) ? move_forward(w) : move_backward(w);
	}
}
