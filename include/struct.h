/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:08:11 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/01 13:00:53 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

# include "../libft/libft.h"

typedef struct s_pos {
	int			x;
	int			y;
}				t_pos;

typedef struct s_next_l {
	char		*levels[9];
	int			lvl;
}				t_next_l;


typedef struct s_map {
	void		*img_map[4];
	void		*img_map_bis[5];
	void		*img_map_nether[5];
	void		*img_map_strongold[8];
	void		*img_map_end[6];
	void		*img_block[1];
	char		*map_path;
	char		*map_w_nl;
	char		*__map;
	char		**map;
	size_t		l_len;
	size_t		n_of_l;
}				t_map;

typedef struct s_collectible
{
	void		*img_col[10];
	int			col;
	int			col_on_map;
}				t_collectible;

typedef struct s_clock {
	unsigned long long	start;
	unsigned long long	end;
}				t_clock;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
}				t_mlx;

typedef struct s_mob
{
	void		*img_mob[4];
	t_pos		mob_pos;
	int			mob_mov;
	int			mob_pres;
}				t_mob;

typedef struct s_p
{
	void		*img_p[6];
	t_pos		p_pos;
	int			p_mov;
	int			orient;
}				t_p;

typedef struct s_game_ev
{
	void		*img_game_ev[3];
	int			game_over;
	int			victory;
	int			game_end;
	int			esc_game_over;
	int			game_ev;
}				t_game_ev;

typedef struct s_bar
{
	t_pos		pos_item;
}				t_bar;

typedef struct s_data {
	t_mlx			mlx;
	t_map			map;
	t_collectible	col;
	t_p				p;
	t_mob			mob;
	t_clock			clock;
	t_game_ev		game_ev;
	t_next_l		nl;
	struct timeval	delay;
	int				fd;
	int				error;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

#endif