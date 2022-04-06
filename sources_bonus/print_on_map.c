/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_on_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 14:41:38 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/22 17:22:44 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	print_on_map(t_data *data, void *img, size_t x, size_t y)
{
	mlx_put_image_to_window(data->mlx.mlx, data->mlx.mlx_win,
		img, x * SIZE_SPRITE, y * SIZE_SPRITE);
}
