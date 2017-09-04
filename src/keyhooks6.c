/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:41:08 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/02 15:43:54 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		trig_rotate_left(t_wolf *w)
{
	TRIG->rl = 1;
}

void		untrig_rotate_left(t_wolf *w)
{
	TRIG->rl = 0;
}

void		trig_rotate_right(t_wolf *w)
{
	TRIG->rr = 1;
}

void		untrig_rotate_right(t_wolf *w)
{
	TRIG->rr = 0;
}
