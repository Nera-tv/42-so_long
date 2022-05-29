/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_images.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:39:04 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:27:24 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_load_images(t_data *data)
{
	int			xy[2];

	data->img[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/ground.xpm", &data->sprite_size,
			&data->sprite_size);
	data->img[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/wall.xpm", &xy[0], &xy[1]);
	data->img[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/apple.xpm", &xy[0], &xy[1]);
	data->img[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/door.xpm", &xy[0], &xy[1]);
	data->img[4] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_left.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->img, 5, ERRLOADIMGS);
}
