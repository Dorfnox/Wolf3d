/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:43:07 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 14:54:39 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	trig_increase_move_speed(t_wolf *w)
{
	TRIG->ims = 1;
}

void	untrig_increase_move_speed(t_wolf *w)
{
	TRIG->ims = 0;
}

void	trig_decrease_move_speed(t_wolf *w)
{
	TRIG->dms = 1;
}

void	untrig_decrease_move_speed(t_wolf *w)
{
	TRIG->dms = 0;
}
