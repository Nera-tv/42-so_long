/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:42:45 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:25:05 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_p_on_map(t_data *data)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->p.img_p[0], data->p.p_pos.x * SIZE_SPRITE,
		data->p.p_pos.y * SIZE_SPRITE);
}

void	get_p_pos(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != data->map.n_of_l)
	{
		x = 0;
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == 'P')
			{
				data->p.p_pos.x = x;
				data->p.p_pos.y = y;
			}
			x++;
		}
		y++;
	}
}
