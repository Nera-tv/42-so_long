/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob_movement_bis.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:24:51 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:25:23 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_ground_behind_mob(t_data *data, int lr, int ud)
{
	if (data->nl.lvl < 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map[0], (data->mob.mob_pos.x + lr) * SIZE_SPRITE,
			(data->mob.mob_pos.y + ud) * SIZE_SPRITE);
	}
	else
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_bis[0], (data->mob.mob_pos.x + lr)
			* SIZE_SPRITE, (data->mob.mob_pos.y + ud) * SIZE_SPRITE);
	}
}

void	map_ac_z_up_down(t_data *data, int y, int mov)
{
	if (data->map.map[data->mob.mob_pos.y][data->mob.mob_pos.x] != 'E')
	{
		if (y == 0)
		{
			put_ground_behind_mob(data, 0, y);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->mob.img_mob[mov], data->mob.mob_pos.x * SIZE_SPRITE,
				data->mob.mob_pos.y * SIZE_SPRITE);
		}
		if (y != 0)
		{
			put_ground_behind_mob(data, 0, y);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->mob.img_mob[mov], data->mob.mob_pos.x * SIZE_SPRITE,
				data->mob.mob_pos.y * SIZE_SPRITE);
		}
	}
}

void	map_ac_z_left_right(t_data *data, int x, int mov)
{
	if (data->map.map[data->mob.mob_pos.y][data->mob.mob_pos.x] != 'E')
	{
		if (x != 0)
		{
			put_ground_behind_mob(data, x, 0);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->mob.img_mob[mov], data->mob.mob_pos.x * SIZE_SPRITE,
				data->mob.mob_pos.y * SIZE_SPRITE);
		}
		if (x == 0)
		{
			put_ground_behind_mob(data, x, 0);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->mob.img_mob[mov], data->mob.mob_pos.x * SIZE_SPRITE,
				data->mob.mob_pos.y * SIZE_SPRITE);
		}
	}
}
