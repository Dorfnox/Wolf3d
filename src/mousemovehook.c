/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mousemovehook.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:10:05 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/05 18:53:03 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_move(int x, int y, t_wolf *w)
{
	static int	oldx;
	static int	oldy;

	if (!(oldx == 0 && oldy == 0))
	{
		if (oldx < x && WOLF->rrrla < 200)
			WOLF->rrrla += ((x - oldx) * 2) + 15;
		else if (oldx > x && WOLF->rrrla > -200)
			WOLF->rrrla += ((x - oldx) * 2) - 15;
	}
	oldx = x;
	oldy = y;
	return (1);
}
