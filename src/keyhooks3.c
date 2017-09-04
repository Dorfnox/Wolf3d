/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/29 11:58:55 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 13:55:19 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	trig_move_left(t_wolf *w)
{
	TRIG->l = 1;
}

void	untrig_move_left(t_wolf *w)
{
	TRIG->l = 0;
}

void	trig_move_right(t_wolf *w)
{
	TRIG->r = 1;
}

void	untrig_move_right(t_wolf *w)
{
	TRIG->r = 0;
}
