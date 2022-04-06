/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_bis.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 11:32:34 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/02 13:53:16 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

size_t	ft_linelen(char *str)
{
	size_t	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\n' && str[i])
		i++;
	return (i);
}

size_t	ft_nbr_of_line(char *str)
{
	size_t	i;
	size_t	line;

	if (!str)
		return (0);
	i = 0;
	line = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			line++;
		i++;
	}
	return (line);
}
