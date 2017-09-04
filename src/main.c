/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 14:14:26 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/01 14:10:49 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int argc, char **argv)
{
	void	*mlx;
	t_wolf	*wolf;

	if (argc < 2)
		return (ft_puterror("Usage: ./wolf3d [maps/mapname.map]", -1));
	else if (argc > 2)
	{
		ft_putstr("Usage: ./wolf3d [maps/mapname.map]\n");
		return (ft_puterror("Enter one map name only.", -1));
	}
	if (!(preliminary_char_check(argv[1])))
		return (ft_puterror("Incorrect map file...", -1));
	mlx = mlx_init();
	if (!(wolf = initialize_wolf(mlx, (argc != 1) ? argv[1] : NULL)))
		return (ft_puterror("\nFailed to initialize. Terminating.", -1));
	mlx_loop(mlx);
	return (1);
}
