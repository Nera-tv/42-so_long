/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_start.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 11:32:25 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 14:53:06 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

void	end(t_data *data)
{
	if (data->nl.lvl < 9)
		victory_img(data);
	if (data->nl.lvl == 9)
		ft_game_end(data);
}

int	start_game(t_data *data, char *str)
{
	data->map.map_path = ft_strdup(str);
	data->map.map_w_nl = ft_parsing(str);
	if (data->map.map_w_nl == NULL)
	{
		free(data->map.map_path);
		return (1);
	}
	get_map_w_nl(data);
	if (fill_map(data) != 0)
	{
		ft_putstr_fd(ERRMEMFAIL, 1);
		return (1);
	}
	data->col.opened = 0;
	get_p_pos(data);
	get_mob_pos(data);
	col_on_map(data);
	data->p.p_mov = 0;
	data->clock.start = time(NULL);
	data->p.orient = 6;
	if (ft_new_win(data) != 0)
	{
		ft_putstr_fd(ERRTRACEFILE, 1);
		return (1);
	}
	return (0);
}
