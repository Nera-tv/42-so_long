/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_images_bis.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:48:10 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/06 13:13:05 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_load_block_images(t_data *data)
{
	int			xy[2];

	data->map.img_block[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/cobblestone.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->map.img_block, 1, ERRLOADBLOIMGS);
}

void	ft_load_map_bis_images(t_data *data)
{
	int			xy[2];

	data->map.img_map_bis[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/stone.xpm", &xy[0], &xy[1]);
	data->map.img_map_bis[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/deepslate.xpm", &xy[0], &xy[1]);
	data->map.img_map_bis[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/door.xpm", &xy[0], &xy[1]);
	data->map.img_map_bis[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/broken_stone.xpm", &xy[0], &xy[1]);
	data->map.img_map_bis[4] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/open_door.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->map.img_map_bis, 5, ERRLOADMAPIMGS);
}

void	ft_load_map_strongold_images(t_data *data)
{
	int			xy[2];

	data->map.img_map_strongold[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/stonebrick.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/deepslate.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/door.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/lava.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[4] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/open_door.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[5] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/end_portal.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[6] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/end_portal_block.xpm", &xy[0], &xy[1]);
	data->map.img_map_strongold[7] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/portal_eye.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->map.img_map_strongold, 8, ERRLOADMAPIMGS);
}

void	ft_load_images(t_data *data)
{
	ft_load_map_images(data);
	ft_load_p_images(data);
	ft_load_col_images(data);
	ft_load_game_ev_images(data);
	ft_load_mob_images(data);
	ft_load_block_images(data);
	ft_load_map_bis_images(data);
	ft_load_map_strongold_images(data);
}
