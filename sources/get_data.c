/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 16:35:03 by dvilard           #+#    #+#             */
/*   Updated: 2022/03/21 16:48:36 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	get_player_pos(t_data *data)
{
	size_t	x;
	size_t	y;

	y = 0;
	while (y != data->map.n_of_l)
	{
		x = 0;
		while (x != data->map.l_len)
		{
			if (data->map.map[y][x] == 'P')
			{
				data->p.p_pos.x = x;
				data->p.p_pos.y = y;
			}
			x++;
		}
		y++;
	}
}

int	get_map_w_nl(t_data *data)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	data->map.l_len = ft_linelen(data->map.map_w_nl);
	data->map.n_of_l = ft_nbr_of_line(data->map.map_w_nl);
	data->map.__map = malloc(sizeof(char *)
			* (ft_strlen(data->map.map_w_nl)
				- ft_nbr_of_line(data->map.map_w_nl)));
	if (!data->map.__map)
		return (1);
	while (data->map.map_w_nl[y] != '\0')
	{
		if (data->map.map_w_nl[y] != '\n')
		{
			data->map.__map[i] = data->map.map_w_nl[y];
			i++;
		}
		y++;
	}
	return (0);
}

int	fill_map(t_data *data)
{
	size_t	x;
	size_t	y;
	size_t	i;

	x = 0;
	y = 0;
	i = 0;
	data->map.map = malloc(sizeof(char *) * (data->map.n_of_l + 1));
	if (!data->map.map)
		return (1);
	while (i != ((data->map.n_of_l * data->map.l_len) + data->map.l_len))
	{
		data->map.map[y] = malloc(sizeof(char) * (data->map.l_len + 1));
		if (!data->map.map[y])
			return (1);
		while (x != data->map.l_len)
		{
			data->map.map[y][x] = data->map.__map[i];
			i++;
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

void	col_on_map(t_data *data)
{
	int	i;

	i = 0;
	data->col.col = 0;
	data->col.col_on_map = 0;
	while (data->map.map_w_nl[i] != '\0')
	{
		if (data->map.map_w_nl[i] == 'C')
			data->col.col_on_map++;
		i++;
	}
}
