/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:03:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/21 16:48:49 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.map.map_w_nl = ft_parsing(argv[1]);
	if (data.map.map_w_nl == NULL || argc != 2)
		return (0);
	get_map_w_nl(&data);
	if (fill_map(&data) != 0)
	{
		ft_putstr_fd(ERRMEMFAIL, 1);
		return (0);
	}	
	get_player_pos(&data);
	col_on_map(&data);
	data.p.player_mov = 0;
	ft_new_win(&data);
}
