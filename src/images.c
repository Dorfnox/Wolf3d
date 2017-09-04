/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/23 10:28:14 by bpierce           #+#    #+#             */
/*   Updated: 2017/08/25 22:21:56 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

t_image		*new_image(t_wolf *w, int width, int height)
{
	t_image		*image;

	image = (t_image *)malloc(sizeof(t_image));
	image->img = mlx_new_image(w->mlx, width, height);
	image->pix = (int *)mlx_get_data_addr(image->img,
			&image->bpp, &image->w, &image->endian);
	image->w /= 4;
	image->h = height;
	return (image);
}

void		fill_image_with_colour(t_image *i, int c)
{
	int		x;
	int		y;

	y = -1;
	while (++y < i->h)
	{
		x = -1;
		while (++x < i->w)
			i->pix[(y * i->w) + x] = c;
	}
}
