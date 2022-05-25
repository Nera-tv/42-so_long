/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:38:49 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 14:54:30 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_door_on_map_bis(t_data *data, size_t x, size_t y)
{
	if (data->nl.lvl < 2)
		print_on_map(data, data->map.img_map[2], x, y);
	else if ((data->nl.lvl < 9 && data->nl.lvl >= 2))
		print_on_map(data, data->map.img_map_bis[2], x, y);
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
		print_on_map(data, data->map.img_map_strongold[3], x, y);
}

void	put_open_door_on_map_bis(t_data *data, size_t x, size_t y)
{
	if (data->nl.lvl < 2)
		print_on_map(data, data->map.img_map[3], x, y);
	else if ((data->nl.lvl < 8 && data->nl.lvl >= 2))
		print_on_map(data, data->map.img_map_bis[4], x, y);
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
		print_on_map(data, data->map.img_map_strongold[5], x, y);
}

void	portal_eye(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	while (i != ((data->map.n_of_l * data->map.l_len) + data->map.l_len))
	{
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == '6')
				print_on_map(data, data->map.img_map_strongold[7], x, y);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	open_door(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	if (data->col.opened)
		return ;
	while (i != ((data->map.n_of_l * data->map.l_len) + data->map.l_len))
	{
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == 'E')
				put_open_door_on_map_bis(data, x, y);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	data->col.opened = 1;
	portal_eye(data);
}

void	put_door_on_map(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	while (i != ((data->map.n_of_l * data->map.l_len) + data->map.l_len))
	{
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == 'E')
				put_door_on_map_bis(data, x, y);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}
