/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 11:51:06 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:29:16 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	get_collectible(t_data *data)
{
	data->col.col = data->col.col + 1;
}

void	put_ore_on_map(t_data *data, size_t x, size_t y)
{
	if (data->nl.lvl < 2)
		print_on_map(data, data->col.img_col[0], x, y);
	else if (data->nl.lvl < 4 && data->nl.lvl >= 2)
		print_on_map(data, data->col.img_col[1], x, y);
	else if (data->nl.lvl < 6 && data->nl.lvl >= 4)
		print_on_map(data, data->col.img_col[2], x, y);
	else if (data->nl.lvl < 8 && data->nl.lvl >= 6)
		print_on_map(data, data->col.img_col[3], x, y);
	else if (data->nl.lvl < 9 && data->nl.lvl >= 8)
		print_on_map(data, data->col.img_col[4], x, y);
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
		print_on_map(data, data->col.img_col[5], x, y);
}

void	put_collectible_on_map(t_data *data)
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
			if (data->map.map[y][x] == 'C')
				put_ore_on_map(data, x, y);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}
