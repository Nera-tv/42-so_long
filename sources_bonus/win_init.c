/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:41:56 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/01 12:20:26 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	p_anim_bis(t_data *data, int img)
{
	put_ground(data);
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		data->p.img_p[img], data->p.p_pos.x * 64,
		data->p.p_pos.y * 64);
}

void	p_anim(t_data *data)
{
	static int	i = 0;

	if (data->p.orient == 1 && data->game_ev.game_ev != 1)
	{
		if ((i > 0 && i <= 25) || (i > 50 && i <= 75))
			p_anim_bis(data, 0);
		else if (i > 25 && i <= 50)
			p_anim_bis(data, 2);
		else if (i > 75 && i <= 100)
			p_anim_bis(data, 3);
	}
	else if (data->p.orient == 0 && data->game_ev.game_ev != 1)
	{
		if ((i > 0 && i <= 25) || (i > 50 && i <= 75))
			p_anim_bis(data, 1);
		else if (i > 25 && i <= 50)
			p_anim_bis(data, 4);
		else if (i > 75 && i <= 100)
			p_anim_bis(data, 5);
	}
	i++;
	if (i == 101)
		i = 0;
}

int	animation(t_data *data)
{
	p_anim(data);
	usleep(18000);
	return (0);
}

int	ft_new_win(t_data *data)
{
	int		x;
	int		y;

	x = SIZE_SPRITE * data->map.l_len;
	y = SIZE_SPRITE * (data->map.n_of_l + 1);
	data->fd = open("trace/trace.txt", O_RDWR | O_APPEND);
	if (data->fd == -1)
		return (1);
	p_movement_trace_header(data);
	data->mlx.mlx_win = mlx_new_window(data->mlx.mlx, x, y, "So_long");
	ft_map_gen(data);
	print_count_on_map(data);
	data->p.p_mov++;
	mlx_hook(data->mlx.mlx_win, 2, 1L << 0, input, data);
	mlx_hook(data->mlx.mlx_win, 17, 0, echap, data);
	mlx_do_key_autorepeaton(data->mlx.mlx);
	mlx_loop_hook(data->mlx.mlx, animation, data);
	mlx_loop(data->mlx.mlx);
	return (0);
}
