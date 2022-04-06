/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:58:36 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/21 17:53:14 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	map_ac(t_data *data, int lr, int ud)
{
	if (data->map.map[data->p.p_pos.y][data->p.p_pos.x] != 'E')
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->img[0],
			(data->p.p_pos.x + lr) * 64, (data->p.p_pos.y + ud) * 64);
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->img[4],
			data->p.p_pos.x * 64, data->p.p_pos.y * 64);
	}
}

void	player_mov(t_data *data)
{
	data->p.player_mov++;
	ft_putnbr_fd(data->p.player_mov, 1);
	ft_putchar_fd('\n', 1);
}
