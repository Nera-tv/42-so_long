/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:43:35 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:26:57 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_destroy_images(t_data *data)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		if (data->img[i])
			mlx_destroy_image(data->mlx.mlx, data->img[i]);
		i++;
	}
}
