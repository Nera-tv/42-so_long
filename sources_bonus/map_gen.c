/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 15:17:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/01 12:10:17 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	map_to_index(char asset)
{
	if (asset == '0')
		return (0);
	else if (asset == '1')
		return (1);
	else if (asset == 'C')
		return (0);
	else if (asset == 'E')
		return (0);
	else if (asset == 'P')
		return (0);
	else if (asset == 'O')
		return (0);
	else if (asset == '2')
		return (0);
	else if (asset == '6')
		return (0);
	else if (asset == 'L')
		return (0);
	return (-1);
}

void	put_block_on_map(t_data *data)
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
			if (data->map.map[y][x] == '2')
			{
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->map.img_map_bis[3], x * SIZE_SPRITE, y * SIZE_SPRITE);
			}
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	ft_map_gen_bis(t_data *data, size_t x, size_t y)
{
	if (data->nl.lvl < 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map[map_to_index(data->map.map[y][x])],
			x * SIZE_SPRITE, y * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 9 && data->nl.lvl >= 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_bis[map_to_index(data->map.map[y][x])],
			x * SIZE_SPRITE, y * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_strongold[map_to_index(data->map.map[y][x])],
			x * SIZE_SPRITE, y * SIZE_SPRITE);
	}
}

void	put_image(t_data *data)
{
	put_p_on_map(data);
	put_collectible_on_map(data);
	put_block_on_map(data);
	put_lava_on_map(data);
	put_door_on_map(data);
	put_portal_block_on_map(data);
	if (data->mob.mob_pres == 1)
		put_mob_on_map(data);
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
			ft_map_gen_bis(data, x, y);
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	put_image(data);
}
