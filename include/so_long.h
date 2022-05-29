/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:19:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/05/25 17:30:36 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define ERRUSAGE "so_long: no map to parse !\
	\nUsage : ./so_long maps/<map>.ber\n"
# define ERRARGLESS "so_long: no map to parse !\n"
# define ERRCHARLESS "so_long: map parsing error ! \
	One of the characteres \"0, 1, P, C, E\" is missing !\n"
# define ERRMEMFAIL "so_long: memory allocation failure !\n"
# define ERRLOADIMGS "so_long: Unable to load frames !\n"

typedef struct s_pos {
	int	x;
	int	y;
}				t_pos;

typedef struct s_map {
	char	*map_w_nl;
	char	*__map;
	char	**map;
	size_t	l_len;
	size_t	n_of_l;
}				t_map;

typedef struct s_collectible
{
	int	col;
	int	col_on_map;
}				t_collectible;

typedef struct s_mlx
{
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_player
{
	t_pos			p_pos;
	int				player_mov;
}				t_player;

typedef struct s_data {
	void			*img[6];
	char			*addr;
	t_mlx			mlx;
	t_map			map;
	t_collectible	col;
	t_player		p;
	int				sprite_size;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}				t_data;

char	*ft_parsing(char *src);
int		push_file_into_tab(char *src, char **str);
int		ft_check_map_char(char *str);
int		ft_check_wall_up_down_left_right(char *str);
int		get_map_w_nl(t_data *data);
int		fill_map(t_data *data);
int		ft_new_win(t_data *data);
int		input(int key, t_data *data);
int		echap(t_data *data);
int		map_to_index(char asset);
int		echap(t_data *data);
int		map_to_index(char asset);
size_t	ft_linelen(char *str);
size_t	ft_nbr_of_line(char *str);
void	get_player_pos(t_data *data);
void	col_on_map(t_data *data);
void	ft_load_images(t_data *data);
void	ft_map_gen(t_data *data);
void	player_movement_up(t_data *data);
void	player_movement_left(t_data *data);
void	player_movement_down(t_data *data);
void	player_movement_right(t_data *data);
void	player_mov(t_data *data);
void	ft_destroy_images(t_data *data);
void	map_ac(t_data *data, int lr, int ud);
void	ft_check_images(t_data *data, void **img, int nbr_of_images, char *msg);

#endif