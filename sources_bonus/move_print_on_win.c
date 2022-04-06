/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_print_on_win.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 12:57:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/22 17:04:30 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	move_print_on_win(t_data *data)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
		delay(data, 100);
		printf("hello\n");
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->game_ev.img_game_ev[1], (data->map.l_len * SIZE_SPRITE)
			/ 2 - 512 / 2, 0);
		delay(data, 100);
		printf("hello\n");
		i++;
	}
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
}
