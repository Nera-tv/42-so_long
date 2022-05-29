/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lava.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 15:49:34 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:25:44 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	put_lava_on_map(t_data *data)
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
			if (data->map.map[y][x] == 'L')
			{
				mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
					data->map.img_map_strongold[3], x * SIZE_SPRITE,
					y * SIZE_SPRITE);
			}
			i++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	test_p_on_lava(t_data *data)
{
	if (data->map.map[data->p.p_pos.y][data->p.p_pos.x] == 'L')
	{
		data->game_ev.game_ev = 1;
		ft_game_over(data);
	}
}
