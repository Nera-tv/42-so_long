/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 13:42:46 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:27:21 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	input(int key, t_data *data)
{
	if (key == 13)
	{
		player_movement_up(data);
	}
	else if (key == 0)
	{
		player_movement_left(data);
	}
	else if (key == 1)
	{
		player_movement_down(data);
	}
	else if (key == 2)
	{
		player_movement_right(data);
	}
	else if (key == 53)
		echap(data);
	return (1);
}
