/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_esc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 16:07:57 by bpierce           #+#    #+#             */
/*   Updated: 2017/08/23 10:36:59 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** Clicking the red 'X' hooks to exit_window function below
*/

int			exit_window(t_wolf *w)
{
	if (!(free_stuff(w)))
		return (ft_puterror("Error occurred when freeing", -1));
	exit(0);
	return (1);
}
