/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:06:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 16:01:22 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	help_screen(t_wolf *w)
{
	mlx_string_put(w->mlx, w->win, 10, H - 30, MAP->exit_colour,
			"EXIT COLOUR");
	mlx_string_put(w->mlx, w->win, 150, H - 30, 0xAA55FF,
			"Movement Speed (numpad -, numpad +): ");
	mlx_string_put(w->mlx, w->win, 515, H - 30, 0xAA55FF,
			ft_itoa(WOLF->move_speed));
	mlx_string_put(w->mlx, w->win, 550, H - 30, 0x00A820,
			"Rotation Speed (numpad /, numpad *): ");
	mlx_string_put(w->mlx, w->win, 915, H - 30, 0x00A820,
			ft_itoa(WOLF->rot_speed));
}

void	*win_screen(t_wolf *w)
{
	void	*xpm;
	int		wi[1];
	int		he[1];

	xpm = mlx_xpm_file_to_image(w->mlx, "img/calvin-and-hobbes.xpm", wi, he);
	return (xpm);
}

void	*snow_screen(t_wolf *w)
{
	void	*xpm;
	int		wi[1];
	int		he[1];

	xpm = mlx_xpm_file_to_image(w->mlx, "img/snowflake.xpm", wi, he);
	return (xpm);
}
