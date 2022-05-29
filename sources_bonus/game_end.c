/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:38:38 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:29:56 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	victory_img(t_data *data)
{
	data->clock.end = time(NULL);
	data->game_ev.victory = 1;
	data->game_ev.game_ev = 1;
	mlx_do_key_autorepeatoff(data->mlx.mlx);
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->game_ev.img_game_ev[0], (data->map.l_len * SIZE_SPRITE)
		/ 2 - 512 / 2, (data->map.n_of_l * SIZE_SPRITE) / 2 - 288 / 2);
}

void	ft_game_over(t_data *data)
{
	data->clock.end = time(NULL);
	data->game_ev.game_over = 1;
	data->game_ev.game_ev = 1;
	mlx_do_key_autorepeatoff(data->mlx.mlx);
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->game_ev.img_game_ev[1], (data->map.l_len * SIZE_SPRITE)
		/ 2 - 512 / 2, (data->map.n_of_l * SIZE_SPRITE) / 2 - 288 / 2);
}

void	ft_game_end(t_data *data)
{
	data->clock.end = time(NULL);
	data->game_ev.game_end = 1;
	data->game_ev.game_ev = 1;
	ft_putstr_fd("You done ", 1);
	ft_putnbr_fd(data->p.p_mov, 1);
	ft_putstr_fd(" move on final level !\n", 1);
	mlx_do_key_autorepeatoff(data->mlx.mlx);
	mlx_clear_window(data->mlx.mlx, data->mlx.mlx_win);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->game_ev.img_game_ev[2], (data->map.l_len * SIZE_SPRITE)
		/ 2 - 512 / 2, (data->map.n_of_l * SIZE_SPRITE) / 2 - 288 / 2);
}

void	next_level(t_data *data)
{
	data->game_ev.victory = 0;
	data->game_ev.game_ev = 0;
	ft_putstr_fd("You done ", 1);
	ft_putnbr_fd(data->p.p_mov, 1);
	ft_putstr_fd(" move on level ", 1);
	ft_putnbr_fd(data->nl.lvl, 1);
	ft_putstr_fd(" !\n", 1);
	close_game(data);
	free(data->map.map_path);
	if (data->nl.lvl < 9)
	{
		if (start_game(data, data->nl.levels[data->nl.lvl++]) == 1)
			exit(0);
	}
}

void	retry_game(t_data *data)
{
	data->game_ev.game_over = 0;
	data->game_ev.game_ev = 0;
	close_game(data);
	if (start_game(data, data->map.map_path) == 1)
		exit(0);
}
