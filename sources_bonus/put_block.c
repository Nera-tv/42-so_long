/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_block.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 12:13:19 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:24:57 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	delete_block(t_data *data, int lr, int ud)
{
	if (data->nl.lvl < 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map[0], (data->p.p_pos.x + lr) * SIZE_SPRITE,
			(data->p.p_pos.y + ud) * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 9 && data->nl.lvl >= 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_bis[0], (data->p.p_pos.x + lr) * SIZE_SPRITE,
			(data->p.p_pos.y + ud) * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_strongold[0], (data->p.p_pos.x + lr)
			* SIZE_SPRITE, (data->p.p_pos.y + ud) * SIZE_SPRITE);
	}
}

void	put_block_up(t_data *data)
{
	if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] == '2')
	{
		data->map.map[data->p.p_pos.y - 1][data->p.p_pos.x] = '0';
		delete_block(data, 0, -1);
	}
	else if (data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] != '1'
		&& data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] != 'E'
		&& data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] != 'C'
		&& data->map.map[(data->p.p_pos.y - 1)][data->p.p_pos.x] != '6')
	{
		data->map.map[data->p.p_pos.y - 1][data->p.p_pos.x] = '2';
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_block[0], data->p.p_pos.x * SIZE_SPRITE,
			(data->p.p_pos.y - 1) * SIZE_SPRITE);
	}
}

void	put_block_left(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] == '2')
	{
		data->map.map[data->p.p_pos.y][data->p.p_pos.x - 1] = '0';
		delete_block(data, -1, 0);
	}
	else if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] != '1'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] != 'E'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] != 'C'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x - 1)] != '6')
	{
		data->map.map[data->p.p_pos.y][data->p.p_pos.x - 1] = '2';
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_block[0], (data->p.p_pos.x - 1) * SIZE_SPRITE,
			data->p.p_pos.y * SIZE_SPRITE);
	}
}

void	put_block_down(t_data *data)
{
	if (data->map.map[data->p.p_pos.y + 1][data->p.p_pos.x] == '2')
	{
		data->map.map[data->p.p_pos.y + 1][data->p.p_pos.x] = '0';
		delete_block(data, 0, 1);
	}
	else if (data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] != '1'
		&& data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] != 'E'
		&& data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] != 'C'
		&& data->map.map[(data->p.p_pos.y + 1)][data->p.p_pos.x] != '6')
	{
		data->map.map[data->p.p_pos.y + 1][data->p.p_pos.x] = '2';
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_block[0], data->p.p_pos.x * SIZE_SPRITE,
			(data->p.p_pos.y + 1) * SIZE_SPRITE);
	}
}

void	put_block_right(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][data->p.p_pos.x + 1] == '2')
	{
		data->map.map[data->p.p_pos.y][data->p.p_pos.x + 1] = '0';
		delete_block(data, 1, 0);
	}
	else if (data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] != '1'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] != 'E'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] != 'C'
		&& data->map.map[data->p.p_pos.y][(data->p.p_pos.x + 1)] != '6')
	{
		data->map.map[data->p.p_pos.y][data->p.p_pos.x + 1] = '2';
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_block[0], (data->p.p_pos.x + 1) * SIZE_SPRITE,
			data->p.p_pos.y * SIZE_SPRITE);
	}
}
