/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/24 14:43:35 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/08 13:46:21 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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
