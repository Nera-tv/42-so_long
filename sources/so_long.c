/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:03:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 18:50:40 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include <stdio.h>

int	check_path_map(char *str)
{
	int	fd;

	if (str[ft_strlen(str) - 4] != '.' || str[ft_strlen(str) - 3] != 'b'
		|| str[ft_strlen(str) - 2] != 'e' || str[ft_strlen(str) - 1] != 'r')
		return (1);
	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (1);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc != 2 || check_path_map(argv[1]) == 1)
	{
		ft_putstr_fd(ERRUSAGE, 1);
		return (0);
	}
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
