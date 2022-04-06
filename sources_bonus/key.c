/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:40:56 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/23 13:15:53 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	key_w(t_data *data)
{
	test_p_pos_z_pos(data);
	if (data->p.p_pos.y == data->mob.mob_pos.y && data->p.p_pos.x
		== data->mob.mob_pos.x)
	{
		data->game_ev.game_ev = 1;
		ft_game_over(data);
	}
	if (data->game_ev.game_over != 1 && data->game_ev.victory != 1)
	{
		p_movement_up(data);
	}
}

void	key_a(t_data *data)
{
	test_p_pos_z_pos(data);
	if (data->p.p_pos.y == data->mob.mob_pos.y && data->p.p_pos.x
		== data->mob.mob_pos.x)
	{
		data->game_ev.game_ev = 1;
		ft_game_over(data);
	}
	if (data->game_ev.game_over != 1 && data->game_ev.victory != 1)
	{
		p_movement_left(data);
	}
}

void	key_s(t_data *data)
{
	test_p_pos_z_pos(data);
	if (data->p.p_pos.y == data->mob.mob_pos.y && data->p.p_pos.x
		== data->mob.mob_pos.x)
	{
		data->game_ev.game_ev = 1;
		ft_game_over(data);
	}
	if (data->game_ev.game_over != 1 && data->game_ev.victory != 1)
	{
		p_movement_down(data);
	}
}

void	key_d(t_data *data)
{
	test_p_pos_z_pos(data);
	if (data->p.p_pos.y == data->mob.mob_pos.y && data->p.p_pos.x
		== data->mob.mob_pos.x)
	{
		data->game_ev.game_ev = 1;
		ft_game_over(data);
	}
	if (data->game_ev.game_over != 1 && data->game_ev.victory != 1)
	{
		p_movement_right(data);
	}
}
