/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 11:49:55 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/06 11:14:37 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_destroy_images_more(t_data *data, void **img, int nbr_of_images)
{
	int	i;

	i = 0;
	while (i < nbr_of_images)
	{
		if (img[i])
			mlx_destroy_image(data->mlx.mlx, img[i]);
		i++;
	}
}

void	ft_destroy_images(t_data *data)
{
	ft_destroy_images_more(data, data->map.img_map, 4);
	ft_destroy_images_more(data, data->col.img_col, 6);
	ft_destroy_images_more(data, data->mob.img_mob, 4);
	ft_destroy_images_more(data, data->p.img_p, 6);
	ft_destroy_images_more(data, data->game_ev.img_game_ev, 3);
	ft_destroy_images_more(data, data->map.img_block, 1);
	ft_destroy_images_more(data, data->map.img_map_bis, 5);
	ft_destroy_images_more(data, data->map.img_map_strongold, 7);
}

void	close_game(t_data *data)
{
	size_t	i;

	p_movement_trace_footer(data);
	i = 0;
	while (i < data->map.n_of_l + 1)
	{
		free(data->map.map[i]);
		i++;
	}
	free(data->map.map_w_nl);
	data->mob.mob_pres = 0;
	free(data->map.map);
	free(data->map.__map);
	mlx_destroy_window(data->mlx.mlx, data->mlx.mlx_win);
	close(data->fd);
}

int	echap(t_data *data)
{
	close_game(data);
	free(data->map.map_path);
	ft_destroy_images(data);
	exit(0);
	return (1);
}
