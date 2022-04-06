/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 17:34:14 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/23 11:48:05 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	ft_load_p_images(t_data *data)
{
	int			xy[2];

	data->p.img_p[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_left.xpm", &xy[0], &xy[1]);
	data->p.img_p[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_up.xpm", &xy[0], &xy[1]);
	data->p.img_p[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_left_anim_1.xpm", &xy[0], &xy[1]);
	data->p.img_p[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_left_anim_2.xpm", &xy[0], &xy[1]);
	data->p.img_p[4] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_up_anim_1.xpm", &xy[0], &xy[1]);
	data->p.img_p[5] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/player/xpm/player_up_anim_2.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->p.img_p, 6, ERRLOADPLAIMGS);
}

void	ft_load_col_images(t_data *data)
{
	int			xy[2];

	data->col.img_col[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/apple.xpm", &xy[0], &xy[1]);
	data->col.img_col[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/diamond_ore.xpm", &xy[0], &xy[1]);
	data->col.img_col[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/gold_ore.xpm", &xy[0], &xy[1]);
	data->col.img_col[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/iron_ore.xpm", &xy[0], &xy[1]);
	data->col.img_col[4] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/ender_pearl.xpm", &xy[0], &xy[1]);
	data->col.img_col[5] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/collectible/xpm/eye_of_ender.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->col.img_col, 6, ERRLOADCOLIMGS);
}

void	ft_load_game_ev_images(t_data *data)
{
	int			xy[2];

	data->game_ev.img_game_ev[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/game_event/xpm/victory.xpm", &xy[0], &xy[1]);
	data->game_ev.img_game_ev[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/game_event/xpm/game_over.xpm", &xy[0], &xy[1]);
	data->game_ev.img_game_ev[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/game_event/xpm/game_end.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->game_ev.img_game_ev, 3, ERRLOADGEIMGS);
}

void	ft_load_map_images(t_data *data)
{
	int			xy[2];

	data->map.img_map[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/ground.xpm", &xy[0], &xy[1]);
	data->map.img_map[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/wall.xpm", &xy[0], &xy[1]);
	data->map.img_map[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/door.xpm", &xy[0], &xy[1]);
	data->map.img_map[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/map/xpm/open_door.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->map.img_map, 4, ERRLOADMAPIMGS);
}

void	ft_load_mob_images(t_data *data)
{
	int			xy[2];

	data->mob.img_mob[0] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/mob/xpm/mob_up.xpm", &xy[0], &xy[1]);
	data->mob.img_mob[1] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/mob/xpm/mob_down.xpm", &xy[0], &xy[1]);
	data->mob.img_mob[2] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/mob/xpm/mob_left.xpm", &xy[0], &xy[1]);
	data->mob.img_mob[3] = mlx_xpm_file_to_image(data->mlx.mlx,
			"./imgs/mob/xpm/mob_right.xpm", &xy[0], &xy[1]);
	ft_check_images(data, data->mob.img_mob, 4, ERRLOADMOBIMGS);
}
