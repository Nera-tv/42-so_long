/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 12:19:02 by dvilard           #+#    #+#             */
/*   Updated: 2022/04/11 12:18:32 by dvilard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "mlx/mlx.h"
# include "include/struct.h"
# include "include/error_msg.h"
# include "include/key.h"
# include <time.h> 
# include <sys/time.h>
# include <stdlib.h>

# define SIZE_SPRITE 64

int		start_game(t_data *data, char *str);
void	get_p_pos(t_data *data);
int		get_map_w_nl(t_data *data);
int		fill_map(t_data *data);
void	col_on_map(t_data *data);
void	next_level(t_data *data);
void	retry_game(t_data *data);
void	close_game(t_data *data);
void	key_w(t_data *data);
void	key_a(t_data *data);
void	key_s(t_data *data);
void	key_d(t_data *data);
void	delay(t_data *data, int milli_sec);
void	ft_load_images(t_data *data);
void	ft_load_p_images(t_data *data);
void	ft_load_col_images(t_data *data);
void	ft_load_game_ev_images(t_data *data);
void	ft_load_map_images(t_data *data);
void	ft_load_mob_images(t_data *data);
void	ft_load_bar_images(t_data *data);
void	ft_check_images(t_data *data, void **img, int nbr_of_images, char *msg);
void	ft_destroy_images_more(t_data *data, void **img, int nbr_of_images);
void	put_block_up(t_data *data);
void	put_block_left(t_data *data);
void	put_block_down(t_data *data);
void	put_block_right(t_data *data);
void	put_p_on_map(t_data *data);
void	put_mob_on_map(t_data *data);
void	put_collectible_on_map(t_data *data);
void	put_lava_on_map(t_data *data);
void	put_door_on_map(t_data *data);
void	put_portal_block_on_map(t_data *data);
void	put_bar_on_map(t_data *data);
void	print_on_map(t_data *data, void *img, size_t x, size_t y);
void	open_door(t_data *data);
void	test_p_on_lava(t_data *data);
void	ft_destroy_images(t_data *data);
void	ft_map_gen(t_data *data);
void	p_movement_up(t_data *data);
void	p_movement_left(t_data *data);
void	p_movement_down(t_data *data);
void	p_movement_right(t_data *data);
void	map_ac(t_data *data, int lr, int ud);
void	victory_img(t_data *data);
void	p_movement_trace_header(t_data *data);
void	p_movement_trace_footer(t_data *data);
void	get_mob_pos(t_data *data);
void	test_p_pos_z_pos(t_data *data);
void	ft_game_over(t_data *data);
void	ft_game_end(t_data *data);
void	mob_movement_up(t_data *data);
void	mob_movement_down(t_data *data);
void	mob_movement_left(t_data *data);
void	mob_movement_right(t_data *data);
void	map_ac_z_up_down(t_data *data, int y, int mov);
void	map_ac_z_left_right(t_data *data, int x, int mov);
void	put_ground(t_data *data);
void	print_count_on_map(t_data *data);
void	end(t_data *data);
void	get_collectible(t_data *data);
char	*ft_parsing(char *src);
char	*push_file_into_tab(char *src);
int		ft_check_map_char(char *str);
int		ft_check_wall_up_down_left_right(char *str);
int		ft_new_win(t_data *data);
int		input(int key, t_data *data);
int		echap(t_data *data);
int		map_to_index(char asset);
int		ft_random(int min, int max);
size_t	ft_linelen(char *str);
size_t	ft_nbr_of_line(char *str);

#endif