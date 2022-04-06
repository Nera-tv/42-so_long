/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mob.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 14:24:29 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/22 11:39:38 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_mob_on_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->mob.img_mob[2], data->mob.mob_pos.x * SIZE_SPRITE,
		data->mob.mob_pos.y * SIZE_SPRITE);
}

void	get_mob_pos(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != data->map.n_of_l)
	{
		x = 0;
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == 'O')
			{
				data->mob.mob_pres = 1;
				data->mob.mob_pos.x = x;
				data->mob.mob_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

void	test_p_pos_z_pos(t_data *data)
{
	if (data->p.p_pos.y - data->mob.mob_pos.y < 0)
		mob_movement_up(data);
	else if (data->p.p_pos.y - data->mob.mob_pos.y > 0)
		mob_movement_down(data);
	else if (data->p.p_pos.x - data->mob.mob_pos.x < 0)
		mob_movement_left(data);
	else if (data->p.p_pos.x - data->mob.mob_pos.x > 0)
		mob_movement_right(data);
	data->mob.mob_mov = 0;
}
