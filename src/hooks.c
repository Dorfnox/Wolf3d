/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:18:33 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 14:16:34 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		expose_i_guess(t_wolf *w)
{
	draw_stuff(w);
	return (1);
}

int		key_press(int keycode, t_wolf *w)
{
	w->kp[keycode](w);
	return (1);
}

int		key_release(int keycode, t_wolf *w)
{
	w->kr[keycode](w);
	return (1);
}

int		mouse_press(int button, int x, int y, t_wolf *w)
{
	if (w)
		button = x + y;
	return (1);
}

int		mouse_release(int button, int x, int y, t_wolf *w)
{
	if (w)
		button = x + y;
	return (1);
}
