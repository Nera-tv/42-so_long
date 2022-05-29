/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:45:05 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:29:14 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_new_win(t_data *data)
{
	int		x;
	int		y;

	x = 64 * data->map.l_len;
	y = 64 * (data->map.n_of_l + 1);
	data->mlx.mlx = mlx_init();
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, x, y, "So_long");
	ft_load_images(data);
	ft_map_gen(data);
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, input, data);
	mlx_hook(data->mlx.mlx_win, 17, 0, echap, data);
	mlx_do_key_autorepeaton(data->mlx.mlx);
	mlx_loop(data->mlx.mlx);
	return (0);
}
