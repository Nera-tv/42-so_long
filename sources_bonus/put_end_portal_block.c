/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_end_portal_block.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 14:14:51 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/16 11:36:25 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	put_portal_block_on_map(t_data *data)
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
			{
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->map.img_map_strongold[6], x * SIZE_SPRITE,
					y * SIZE_SPRITE);
			}
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}
