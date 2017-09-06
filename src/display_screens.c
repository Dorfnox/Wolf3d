/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_screens.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/30 11:06:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/05 16:41:57 by bpierce          ###   ########.fr       */
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

t_image	*win_screen(t_wolf *w)
{
	t_image	*image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	image->img = mlx_xpm_file_to_image(w->mlx,
			"img/calvin-and-hobbes.xpm", &image->w, &image->h);
	return (image);
}

t_image	*snow_screen(t_wolf *w)
{
	t_image	*image;

	image = (t_image *)ft_memalloc(sizeof(t_image));
	image->img = mlx_xpm_file_to_image(w->mlx,
			"img/snowflake.xpm", &image->w, &image->h);
	return (image);
}

t_image	*crosshair_x(t_wolf *w)
{
	t_image	*image;

	image = new_image(w, 20, 1);
	fill_image_with_colour(image, 0x00FF00);
	return (image);
}

t_image	*crosshair_y(t_wolf *w)
{
	t_image *image;

	image = new_image(w, 1, 20);
	fill_image_with_colour(image, 0x00FF00);
	return (image);
}
