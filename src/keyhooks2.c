/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:41:08 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 19:54:50 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		trig_move_forward(t_wolf *w)
{
	TRIG->f = 1;
}

void		untrig_move_forward(t_wolf *w)
{
	TRIG->f = 0;
}

void		trig_move_backward(t_wolf *w)
{
	TRIG->b = 1;
}

void		untrig_move_backward(t_wolf *w)
{
	TRIG->b = 0;
}
