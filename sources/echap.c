/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echap.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:46:13 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/06 13:17:46 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	echap(t_data *data)
{
	size_t	i;

	ft_destroy_images(data);
	ft_putstr_fd("You made ", 1);
	ft_putnbr_fd((data->p.player_mov), 1);
	ft_putstr_fd(" moves !", 1);
	ft_putchar_fd('\n', 1);
	i = 0;
	while (i != (data->map.n_of_l + 1))
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map);
	free(data->map.__map);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	exit(0);
	return (1);
}
