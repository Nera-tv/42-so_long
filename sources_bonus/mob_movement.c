/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movement.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:24:39 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:25:21 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

int	check_char_map(t_data *data, int lr, int ud)
{
	if (data->map.map[(data->mob.mob_pos.y + ud)][(data->mob.mob_pos.x + lr)]
		!= '1'
		&& data->map.map[(data->mob.mob_pos.y + ud)][(data->mob.mob_pos.x + lr)]
		!= 'E'
		&& data->map.map[(data->mob.mob_pos.y + ud)][(data->mob.mob_pos.x + lr)]
		!= 'C'
		&& data->map.map[(data->mob.mob_pos.y + ud)][(data->mob.mob_pos.x + lr)]
		!= '2'
		&& data->map.map[(data->mob.mob_pos.y + ud)][(data->mob.mob_pos.x + lr)]
		!= 'L')
		return (1);
	else
		return (0);
}

void	mob_movement_up(t_data *data)
{
	int	nbr;

	nbr = ft_random(1, 6);
	if (nbr <= 5)
	{
		if (check_char_map(data, 0, -1) == 1)
		{
			data->mob.mob_pos.y = data->mob.mob_pos.y - 1;
			map_ac_z_up_down(data, 1, 0);
		}
	}
	else if (nbr > 5)
	{
		if (check_char_map(data, 0, 1) == 1)
		{
			data->mob.mob_pos.y = data->mob.mob_pos.y + 1;
			map_ac_z_up_down(data, -1, 1);
		}
	}
}

void	mob_movement_down(t_data *data)
{
	int	nbr;

	nbr = ft_random(1, 6);
	if (nbr <= 5)
	{
		if (check_char_map(data, 0, 1) == 1)
		{
			data->mob.mob_pos.y = data->mob.mob_pos.y + 1;
			map_ac_z_up_down(data, -1, 1);
		}
	}
	else if (nbr > 5)
	{
		if (check_char_map(data, 0, -1) == 1)
		{
			data->mob.mob_pos.y = data->mob.mob_pos.y - 1;
			map_ac_z_up_down(data, 1, 0);
		}
	}
}

void	mob_movement_left(t_data *data)
{
	int	nbr;

	nbr = ft_random(1, 6);
	if (nbr <= 5)
	{
		if (check_char_map(data, -1, 0) == 1)
		{
			data->mob.mob_pos.x = data->mob.mob_pos.x - 1;
			map_ac_z_left_right(data, 1, 2);
		}
	}
	else if (nbr > 5)
	{
		if (check_char_map(data, 1, 0) == 1)
		{
			data->mob.mob_pos.x = data->mob.mob_pos.x + 1;
			map_ac_z_left_right(data, -1, 3);
		}
	}
}

void	mob_movement_right(t_data *data)
{
	int	nbr;

	nbr = ft_random(1, 6);
	if (nbr <= 5)
	{
		if (check_char_map(data, 1, 0) == 1)
		{
			data->mob.mob_pos.x = data->mob.mob_pos.x + 1;
			map_ac_z_left_right(data, -1, 3);
		}
	}
	else if (nbr > 5)
	{
		if (check_char_map(data, -1, 0) == 1)
		{
			data->mob.mob_pos.x = data->mob.mob_pos.x - 1;
			map_ac_z_left_right(data, 1, 2);
		}
	}
}
