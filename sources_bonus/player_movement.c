/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 14:30:36 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/01 12:40:59 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	check_char_player_map(t_data *data, int lr, int ud)
{
	if (data->map.map[(data->p.p_pos.y + ud)][(data->p.p_pos.x + lr)] != '1'
	&& data->map.map[(data->p.p_pos.y + ud)][(data->p.p_pos.x + lr)] != 'E'
	&& data->map.map[(data->p.p_pos.y + ud)][(data->p.p_pos.x + lr)] != '2'
	&& data->map.map[(data->p.p_pos.y + ud)][(data->p.p_pos.x + lr)] != '6')
		return (1);
	else
		return (0);
}

void	p_movement_up(t_data *data)
{	
	if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		ft_putstr_fd(" W", data->fd);
		data->p.p_mov++;
		end(data);
	}
	if (check_char_player_map(data, 0, -1) == 1)
	{
		if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x]
		== 'C')
		{
			data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x]
				= '0';
			get_collectible(data);
		}
		ft_putstr_fd(" W", data->fd);
		data->p.p_pos.y = data->p.p_pos.y - 1;
		map_ac(data, 0, 1);
		data->p.p_mov++;
	}
	data->p.orient = 0;
	test_p_on_lava(data);
}

void	p_movement_left(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		ft_putstr_fd(" A", data->fd);
		data->p.p_mov++;
		end(data);
	}
	if (check_char_player_map(data, -1, 0) == 1)
	{
		if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)]
		== 'C')
		{
			data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)]
				= '0';
			get_collectible(data);
		}
		ft_putstr_fd(" A", data->fd);
		data->p.p_pos.x = data->p.p_pos.x - 1;
		map_ac(data, 1, 0);
		data->p.p_mov++;
	}
	data->p.orient = 1;
	test_p_on_lava(data);
}

void	p_movement_down(t_data *data)
{
	if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		ft_putstr_fd(" S", data->fd);
		data->p.p_mov++;
		end(data);
	}
	if (check_char_player_map(data, 0, 1) == 1)
	{
		if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x]
		== 'C')
		{
			data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x]
				= '0';
			get_collectible(data);
		}
		ft_putstr_fd(" S", data->fd);
		data->p.p_pos.y = data->p.p_pos.y + 1;
		map_ac(data, 0, -1);
		data->p.p_mov++;
	}
	data->p.orient = 0;
	test_p_on_lava(data);
}

void	p_movement_right(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)]
		== 'E' && data->col.col == data->col.col_on_map)
	{
		ft_putstr_fd(" D", data->fd);
		data->p.p_mov++;
		end(data);
	}
	if (check_char_player_map(data, 1, 0) == 1)
	{
		if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)]
		== 'C')
		{
			data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)]
				= '0';
			get_collectible(data);
		}
		ft_putstr_fd(" D", data->fd);
		data->p.p_pos.x = data->p.p_pos.x + 1;
		map_ac(data, -1, 0);
		data->p.p_mov++;
	}
	data->p.orient = 1;
	test_p_on_lava(data);
}
