/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:43:07 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 14:56:23 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	trig_increase_rot_speed(t_wolf *w)
{
	TRIG->irs = 1;
}

void	untrig_increase_rot_speed(t_wolf *w)
{
	TRIG->irs = 0;
}

void	trig_decrease_rot_speed(t_wolf *w)
{
	TRIG->drs = 1;
}

void	untrig_decrease_rot_speed(t_wolf *w)
{
	TRIG->drs = 0;
}
