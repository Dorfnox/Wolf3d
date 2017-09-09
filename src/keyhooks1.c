/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhooks1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/02 13:53:25 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/08 16:54:23 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	exit_window_kp(t_wolf *w)
{
	if (!(free_stuff(w)))
		ft_putstr("Error occurred when freeing");
	exit(0);
}

void	change_wall_colour(t_wolf *w)
{
	MAP->ns_wall_colour = fmod(rand(), 16777216);
	MAP->sn_wall_colour = fmod(rand(), 16777216);
	MAP->ew_wall_colour = fmod(rand(), 16777216);
	MAP->we_wall_colour = fmod(rand(), 16777216);
	MAP->exit_colour = fmod(rand(), 16777216);
	draw_stuff(w);
}

void	ice_mode(t_wolf *w)
{
	TRIG->snow = (TRIG->snow == 0) ? 1 : 0;
	if (TRIG->snow == 1)
		system("afplay audio/snow.mp3 &");
	WOLF->fba = 0;
	WOLF->rla = 0;
	WOLF->acc = (WOLF->acc != 1) ? 1 : 5;
	WOLF->move_speed = (WOLF->move_speed != 4) ? 4 : 3;
	if (MAP->ns_wall_colour != 0x74BBFB)
	{
		MAP->ns_wall_colour = 0x74BBFB;
		MAP->sn_wall_colour = 0x71A6D2;
		MAP->ew_wall_colour = 0xACE5EE;
		MAP->we_wall_colour = 0x82CFFD;
		MAP->exit_colour = 0xAF96D1;
		MAP->floor_colour = 0xFFFFFF;
		MAP->ceiling_colour = 0xD4F0FF;
	}
	else
	{
		MAP->floor_colour = 0x939393;
		MAP->ceiling_colour = 0x393939;
		change_wall_colour(w);
	}
	draw_stuff(w);
}

void	trig_help_menu(t_wolf *w)
{
	TRIG->help = (TRIG->help == 0) ? 1 : 0;
	draw_stuff(w);
	if (TRIG->help == 1)
		help_screen(w);
}

void	protect_array(t_wolf *w)
{
	if (w)
		return ;
}
