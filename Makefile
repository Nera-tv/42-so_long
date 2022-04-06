# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dvilard <dvilard@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/03 17:19:25 by dvilard           #+#    #+#              #
#    Updated: 2022/04/06 13:33:06 by dvilard          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Sources
LST_SRCS			=	destroy_game.c			\
						echap.c					\
						ft_check_images.c		\
						ft_parsing_bis.c		\
						ft_parsing.c			\
						get_data.c				\
						input.c					\
						load_images.c			\
						map_gen.c				\
						player_movement_bis.c	\
						player_movement.c		\
						so_long.c				\
						win_init.c			


LST_OBJS			=	${LST_SRCS:.c=.o}
SRCS				=	$(addprefix sources/,${LST_SRCS})
OBJS				=	$(addprefix .objects/,${LST_OBJS})

# Bonus Part Sources
LST_SRCS_B			=	collectible.c								\
						destroy_game.c								\
						door.c										\
						ft_check_images.c							\
						ft_load_images_bis.c						\
						ft_load_images.c							\
						ft_parsing_bis.c							\
						ft_parsing.c								\
						ft_random.c									\
						game_end.c									\
						game_start.c								\
						game_trace.c								\
						input.c										\
						key.c										\
						lava.c										\
						map_gen.c									\
						map_init.c 									\
						mob_movement_bis.c							\
						mob_movement.c								\
						mob.c										\
						player_movement_bis.c						\
						player_movement.c							\
						player.c									\
						print_on_map.c								\
						put_block.c									\
						put_end_portal_block.c						\
						so_long.c									\
						win_init.c									


LST_OBJS_B			=	${LST_SRCS_B:.c=.o}
SRCS_B				=	$(addprefix sources_bonus/,${LST_SRCS_B})
OBJS_B				=	$(addprefix .objects_bonus/,${LST_OBJS_B})

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
NAME				= 	so_long
NAME_B				= 	so_long_bonus
HEADER				=	so_long.h
HEADER_B			=	so_long_bonus.h
RM					=	rm -rf
LFT					=	libft/libft.a
LMLX				=	mlx/libmlx.a

all : norm bonus

# Rules
.objects/%.o: sources/%.c $(HEADER)
	mkdir -p .objects
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME} :	$(OBJS)
	${CC} ${CFLAGS} ${OBJS} ${LFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
	cp mlx/libmlx.dylib .

norm : $(LFT) $(LMLX) ${NAME}

# Rules For Bonus

.objects_bonus/%.o: sources_bonus/%.c $(HEADER_B)
	mkdir -p .objects_bonus
	${CC} ${CFLAGS} -Imlx -c $< -o $@

${NAME_B} :	$(OBJS_B)
	${CC} ${CFLAGS} ${OBJS_B} ${LFT} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}
	cp mlx/libmlx.dylib .

bonus :	$(LFT) $(LMLX) ${NAME_B}



# Clean Rules

clean :
	${RM} .objects
	${RM} .objects_bonus

fclean :	clean
	${RM} ${NAME}
	${RM} ${NAME_B}
	${RM} libmlx.dylib

# Re Rule

re :		fclean all



$(LFT):
	make -C ./libft

$(LMLX):
	make -C ./mlx
	cp mlx/libmlx.dylib .

.PHONY :	re fclean clean all