/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookarrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bpierce <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/22 23:15:28 by bpierce           #+#    #+#             */
/*   Updated: 2017/09/03 19:41:27 by bpierce          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void		set_kp_array(void (**kp)(t_wolf *))
{
	kp[ESC__] = &exit_window_kp;
	kp[W__] = &trig_move_forward;
	kp[S__] = &trig_move_backward;
	kp[A__] = &trig_move_left;
	kp[D__] = &trig_move_right;
	kp[Q__] = &trig_rotate_right;
	kp[E__] = &trig_rotate_left;
	kp[UP__] = &trig_move_forward;
	kp[DOWN__] = &trig_move_backward;
	kp[LEFT__] = &trig_rotate_left;
	kp[RIGHT__] = &trig_rotate_right;
	kp[DIVIDE__] = &trig_decrease_rot_speed;
	kp[MULTIPLY__] = &trig_increase_rot_speed;
	kp[MINUS__] = &trig_decrease_move_speed;
	kp[PLUS__] = &trig_increase_move_speed;
	kp[C__] = &change_wall_colour;
	kp[I__] = &ice_mode;
	kp[H__] = &trig_help_menu;
}

void		set_kr_array(void (**kr)(t_wolf *))
{
	kr[W__] = &untrig_move_forward;
	kr[S__] = &untrig_move_backward;
	kr[A__] = &untrig_move_left;
	kr[D__] = &untrig_move_right;
	kr[Q__] = &untrig_rotate_right;
	kr[E__] = &untrig_rotate_left;
	kr[UP__] = &untrig_move_forward;
	kr[DOWN__] = &untrig_move_backward;
	kr[LEFT__] = &untrig_rotate_left;
	kr[RIGHT__] = &untrig_rotate_right;
	kr[DIVIDE__] = &untrig_decrease_rot_speed;
	kr[MULTIPLY__] = &untrig_increase_rot_speed;
	kr[MINUS__] = &untrig_decrease_move_speed;
	kr[PLUS__] = &untrig_increase_move_speed;
}

static void	(**get_kp_array(void))(t_wolf *)
{
	int		i;
	int		num;
	void	(**kp)(t_wolf *);

	i = 0;
	num = 300;
	kp = (void (**)(t_wolf *))ft_memalloc(sizeof(void (*)(t_wolf *)) * num);
	while (i < num)
		kp[i++] = &protect_array;
	set_kp_array(kp);
	return (kp);
}

static void	(**get_kr_array(void))(t_wolf *)
{
	int		i;
	int		num;
	void	(**kr)(t_wolf *);

	i = 0;
	num = 300;
	kr = (void (**)(t_wolf *))ft_memalloc(sizeof(void (*)(t_wolf *)) * num);
	while (i < num)
		kr[i++] = &protect_array;
	set_kr_array(kr);
	return (kr);
}

void		set_arrays(t_wolf *w)
{
	w->kp = get_kp_array();
	w->kr = get_kr_array();
}
