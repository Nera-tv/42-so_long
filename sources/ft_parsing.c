/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:52:05 by dvilard           #+#    #+#             */
/*   Updated: 2022/02/08 13:53:39 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	*push_file_into_tab(char *src)
{
	int			fd;
	char		*gnl;
	char		*str;
	size_t		length;

	fd = open(src, O_RDONLY);
	str = NULL;
	gnl = get_next_line(fd);
	length = ft_linelen(gnl);
	while (gnl)
	{
		str = ft_strjoin_gnl(str, gnl);
		free(gnl);
		gnl = get_next_line(fd);
		if (ft_linelen(gnl) != length && ft_linelen(gnl) != 0)
			return (NULL);
	}
	free(gnl);
	close(fd);
	return (str);
}

int	ft_check_map_char(char *str)
{
	int	i;
	int	val_c;
	int	val_e;
	int	val_p;

	i = 0;
	val_c = 0;
	val_e = 0;
	val_p = 0;
	while (str[i])
	{
		if (str[i] != '0' && str[i] != '1' && str[i] != 'C' && str[i] != 'E'
			&& str[i] != 'P' && str[i] != '\n' && str[i] != '\0')
			return (1);
		if (str[i] == 'C')
			val_c++;
		if (str[i] == 'E')
			val_e++;
		if (str[i] == 'P')
			val_p++;
		i++;
	}
	if (val_c < 1 || val_e < 1 || val_p < 1)
		return (1);
	return (0);
}

int	ft_check_wall_up_down_left_right(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\n')
	{
		if (str[i] != '1')
			return (1);
		i++;
	}
	i = ft_strlen(str);
	while (str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != '\0')
			return (1);
		i--;
	}
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' && (str[i - 1] != '1' || str[i + 1] != '1'))
			return (1);
		i++;
	}
	return (0);
}

char	*ft_parsing(char *src)
{
	char	*str;
	int		val;

	val = 0;
	str = push_file_into_tab(src);
	if (str == NULL)
		return (NULL);
	val += ft_check_map_char(str);
	val += ft_check_wall_up_down_left_right(str);
	if (val != 0)
	{
		ft_putstr_fd(ERRCHARLESS, 1);
		return (NULL);
	}
	return (str);
}
