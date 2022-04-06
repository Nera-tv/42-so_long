/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 14:31:04 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/03 15:32:08 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_random(int min, int max)
{
	int	nbr;

	nbr = 0;
	srand(time(NULL));
	nbr = (rand() % (max + 1 - min)) + min;
	return (nbr);
}
