/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:39:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 14:57:41 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	input_mov_mob(int key, t_data *data)
{
	if (key == KEY_W)
		key_w(data);
	else if (key == KEY_A)
		key_a(data);
	else if (key == KEY_S)
		key_s(data);
	else if (key == KEY_D)
		key_d(data);
	else if (key == KEY_UP)
		put_block_up(data);
	else if (key == KEY_LEFT)
		put_block_left(data);
	else if (key == KEY_DOWN)
		put_block_down(data);
	else if (key == KEY_RIGHT)
		put_block_right(data);
}

void	input_mov(int key, t_data *data)
{
	if (key == KEY_W)
		p_movement_up(data);
	else if (key == KEY_A)
		p_movement_left(data);
	else if (key == KEY_S)
		p_movement_down(data);
	else if (key == KEY_D)
		p_movement_right(data);
	else if (key == KEY_UP)
		put_block_up(data);
	else if (key == KEY_LEFT)
		put_block_left(data);
	else if (key == KEY_DOWN)
		put_block_down(data);
	else if (key == KEY_RIGHT)
		put_block_right(data);
}

int	input(int key, t_data *data)
{
	if (key == KEY_ESC)
		echap(data);
	else if (key == 36 && data->game_ev.victory == 1
		&& data->game_ev.game_over != 1 && data->game_ev.game_end != 1)
		next_level(data);
	else if (key == 36 && data->game_ev.victory != 1
		&& data->game_ev.game_over == 1 && data->game_ev.game_end != 1)
		retry_game(data);
	else if (data->game_ev.game_over != 1 && data->game_ev.victory != 1
		&& data->mob.mob_pres == 1 && data->game_ev.game_end != 1)
		input_mov_mob(key, data);
	else if (data->mob.mob_pres != 1 && data->game_ev.victory != 1
		&& data->game_ev.game_end != 1)
		input_mov(key, data);
	if (data->col.col_on_map == data->col.col && data->game_ev.game_over
		!= 1 && data->game_ev.victory != 1 && data->game_ev.game_end != 1)
		open_door(data);
	return (1);
}
