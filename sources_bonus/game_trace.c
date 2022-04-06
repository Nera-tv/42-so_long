/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_trace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 16:52:35 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/22 17:28:09 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	p_movement_trace_header(t_data *data)
{
	time_t	t;

	t = time(NULL);
	ft_putstr_fd("-- Game :  ", data->fd);
	ft_putstr_fd(ctime(&t), data->fd);
	ft_putchar_fd('\n', data->fd);
}

void	p_movement_trace_footer(t_data *data)
{
	unsigned long long	elapsed;

	elapsed = data->clock.end - data->clock.start;
	if (data->game_ev.game_over == 1)
		ft_putstr_fd("\n\nGame result : Game Over ", data->fd);
	else if (data->game_ev.victory == 1)
		ft_putstr_fd("\n\nGame result : Victory ", data->fd);
	else
		ft_putstr_fd("\n\nGame result : Echap ", data->fd);
	ft_putstr_fd("\n\np Movement = ", data->fd);
	ft_putnbr_fd(data->p.p_mov, data->fd);
	ft_putstr_fd("\n\nMap : \n", data->fd);
	ft_putstr_fd(data->map.map_w_nl, data->fd);
	ft_putstr_fd("\n\nGame time : ", data->fd);
	ft_putnbr_fd(elapsed, data->fd);
	ft_putstr_fd("s\n\n----------\n\n", data->fd);
}
