/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:30:36 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:29:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	player_movement_up(t_data *data)
{	
	if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		player_mov(data);
		echap(data);
	}
	if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x]
		!= '1' && data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] != 'E')
	{
		if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] == 'C')
		{
			data->col.col = data->col.col + 1;
			data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] = '0';
		}
		data->p.p_pos.y = data->p.p_pos.y - 1;
		map_ac(data, 0, 1);
		player_mov(data);
	}
}

void	player_movement_left(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		player_mov(data);
		echap(data);
	}
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)]
		!= '1' && data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] != 'E')
	{
		if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] == 'C')
		{
			data->col.col = data->col.col + 1;
			data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] = '0';
		}
		data->p.p_pos.x = data->p.p_pos.x - 1;
		map_ac(data, 1, 0);
		player_mov(data);
	}
}

void	player_movement_down(t_data *data)
{
	if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		player_mov(data);
		echap(data);
	}
	if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x]
		!= '1' && data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] != 'E')
	{
		if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] == 'C')
		{
			data->col.col = data->col.col + 1;
			data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] = '0';
		}
		data->p.p_pos.y = data->p.p_pos.y + 1;
		map_ac(data, 0, -1);
		player_mov(data);
	}
}

void	player_movement_right(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		player_mov(data);
		echap(data);
	}
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)]
		!= '1' && data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] != 'E')
	{
		if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] == 'C')
		{
			data->col.col = data->col.col + 1;
			data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] = '0';
		}
		data->p.p_pos.x = data->p.p_pos.x + 1;
		map_ac(data, -1, 0);
		player_mov(data);
	}
}
