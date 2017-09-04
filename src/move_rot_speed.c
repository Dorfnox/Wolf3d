/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_rot_speed.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 14:50:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 17:37:46 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	increase_move_speed(t_wolf *w)
{
	WOLF->move_speed += (WOLF->move_speed < 8) ? 0.05 : 0;
}

void	decrease_move_speed(t_wolf *w)
{
	WOLF->move_speed -= (WOLF->move_speed > 0) ? 0.05 : 0;
}

void	increase_rot_speed(t_wolf *w)
{
	WOLF->rot_speed += (WOLF->rot_speed < 43) ? 0.05 : 0;
}

void	decrease_rot_speed(t_wolf *w)
{
	WOLF->rot_speed -= (WOLF->rot_speed > 0.05) ? 0.05 : 0;
}
