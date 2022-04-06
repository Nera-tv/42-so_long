/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_msg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:10:10 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/06 13:12:59 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_MSG_H
# define ERROR_MSG_H

# define ERRARGLESS "so_long: no map to parse !\n"
# define ERRMAPPARS "so_long: map parsing error !\n"
# define ERRCHARLESS "so_long: One of the \
	characteres \"0, 1, P, C, E\" is missing !\n"
# define ERRMEMFAIL "so_long: memory allocation failure !\n"
# define ERRTRACEFILE "so_long: Unable to create trace file !\n"
# define ERRLOADMAPIMGS "so_long: Unable to load map's frames !\n"
# define ERRLOADMOBIMGS "so_long: Unable to load mob's frames !\n"
# define ERRLOADPLAIMGS "so_long: Unable to load player's frames !\n"
# define ERRLOADCOLIMGS "so_long: Unable to load collectible's frames !\n"
# define ERRLOADBLOIMGS "so_long: Unable to load block's frames !\n"
# define ERRLOADGEIMGS "so_long: Unable to load game event's frames !\n"

#endif