/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:03:41 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 18:44:43 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	init_levels(t_data *data)
{
	data->nl.levels[0] = "maps/map01.ber";
	data->nl.levels[1] = "maps/map02.ber";
	data->nl.levels[2] = "maps/map03.ber";
	data->nl.levels[3] = "maps/map04.ber";
	data->nl.levels[4] = "maps/map05.ber";
	data->nl.levels[5] = "maps/map06.ber";
	data->nl.levels[6] = "maps/map07.ber";
	data->nl.levels[7] = "maps/map08.ber";
	data->nl.levels[8] = "maps/map09.ber";
}

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

	ft_memset(&data, 0, sizeof(t_data));
	data.error = 0;
	if (argc != 2 || check_path_map(argv[1]) == 1)
	{
		ft_putstr_fd(ERRUSAGE, 1);
		return (0);
	}
	data.mlx.mlx = mlx_init();
	data.game_ev.game_ev = 0;
	ft_load_images(&data);
	if (data.error == 1)
		return (0);
	init_levels(&data);
	if (start_game(&data, argv[1]) == 1)
		return (0);
	return (0);
}
