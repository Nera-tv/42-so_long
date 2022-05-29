/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:17:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:27:28 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	map_to_index(char asset)
{
	if (asset == '0')
		return (0);
	else if (asset == '1')
		return (1);
	else if (asset == 'C')
		return (0);
	else if (asset == 'E')
		return (3);
	else if (asset == 'P')
		return (0);
	return (0);
}

void	put_player_on_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->img[4], data->p.p_pos.x * data->sprite_size, data->p.p_pos.y
		* data->sprite_size);
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
			{
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->img[2], x * data->sprite_size, y * data->sprite_size);
			}
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_map_gen(t_data *data)
{
	size_t	i;
	size_t	x;
	size_t	y;

	i = 0;
	x = 0;
	y = 0;
	while (i != ((data->map.n_of_l * data->map.l_len)
			+ data->map.l_len))
	{
		while (x != data->map.l_len)
		{
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->img[map_to_index(data->map.map[y][x])],
				x * 64, y * 64);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	put_player_on_map(data);
	put_collectible_on_map(data);
}
