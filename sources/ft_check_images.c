/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_images.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/04 18:38:45 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:27:05 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

void	ft_check_images(t_data *data, void **img, int nbr_of_images, char *msg)
{
	int	i;

	i = 0;
	while (i < nbr_of_images)
	{
		if (!img[i])
		{
			ft_putstr_fd(msg, 1);
			data->error = 1;
		}
		i++;
	}
}
