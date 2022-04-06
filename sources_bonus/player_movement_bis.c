/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 15:34:29 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/06 11:22:36 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_count_on_map_bis(t_data *data, void **tab)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		tab, 0, 0);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		tab, SIZE_SPRITE, 0);
}

void	print_count_on_map(t_data *data)
{
	char	*num;

	ft_putnbr_fd(data->p.p_mov, 1);
	ft_putchar_fd('\n', 1);
	if (data->nl.lvl < 2)
		print_count_on_map_bis(data, data->map.img_map[1]);
	else if (data->nl.lvl < 9 && data->nl.lvl >= 2)
		print_count_on_map_bis(data, data->map.img_map_bis[1]);
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
		print_count_on_map_bis(data, data->map.img_map_strongold[1]);
	num = ft_itoa(data->p.p_mov);
	mlx_string_put(data->mlx.mlx, data->mlx.mlx_win, 20, 36, 0xFFFFFF, num, 2);
	free(num);
}

void	put_ground_behind(t_data *data, int lr, int ud)
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

void	put_ground(t_data *data)
{
	if (data->nl.lvl < 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map[0], data->p.p_pos.x * SIZE_SPRITE,
			data->p.p_pos.y * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 9 && data->nl.lvl >= 2)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_bis[0], data->p.p_pos.x * SIZE_SPRITE,
			data->p.p_pos.y * SIZE_SPRITE);
	}
	else if (data->nl.lvl < 10 && data->nl.lvl >= 9)
	{
		mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
			data->map.img_map_strongold[0], data->p.p_pos.x
			* SIZE_SPRITE, data->p.p_pos.y * SIZE_SPRITE);
	}
}

void	map_ac(t_data *data, int lr, int ud)
{
	if (data->map.map[data->p.p_pos.y][data->p.p_pos.x] != 'E')
	{
		if (lr != 0 && ud == 0)
		{
			put_ground_behind(data, lr, ud);
			put_ground(data);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->p.img_p[0], data->p.p_pos.x * SIZE_SPRITE,
				data->p.p_pos.y * SIZE_SPRITE);
		}
		if (ud != 0 && lr == 0)
		{
			put_ground_behind(data, lr, ud);
			put_ground(data);
			mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
				data->p.img_p[1], data->p.p_pos.x * SIZE_SPRITE,
				data->p.p_pos.y * SIZE_SPRITE);
		}
		print_count_on_map(data);
	}
}
