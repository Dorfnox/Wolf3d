/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_mm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:10:05 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 21:48:02 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		mouse_move(int x, int y, t_wolf *w)
{
	static int	oldx;
	static int	oldy;

	if (!(oldx == 0 && oldy == 0))
	{
		if (oldx != x)
			TRIG->mm.x = (x - oldx) * 10;
		if (oldy != y)
			TRIG->mm.y = (y - oldy) * 10;
	}
	oldx = x;
	oldy = y;
	return (1);
}
