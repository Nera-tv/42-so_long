.PHONY :	re fclean clean all
#.SILENT:


NAME				= 	so_long
NAME_B				= 	so_long_bonus

P_LFT		:=	libft/
P_MLX		:=	mlx/
P_INC		:=	include/
P_SRCS		:=	sources/
P_SRCS_B	:=	sources_bonus/
P_OBJS		:=	.objects/
P_OBJS_B	:=	.objects_bonus/
P_TRA		:=	trace/

HEADER				=	${P_INC}so_long.h							\
						${P_LFT}libft.h								\
						${P_MLX}mlx.h
HEADER_B			=	${P_INC}so_long_bonus.h						\
						${P_INC}error_msg.h							\
						${P_INC}key.h								\
						${P_INC}struct.h							\
						${P_LFT}libft.h								\
						${P_MLX}mlx.h

# Sources
LST_SRCS			=	destroy_game.c								\
						echap.c										\
						ft_check_images.c							\
						ft_parsing_bis.c							\
						ft_parsing.c								\
						get_data.c									\
						input.c										\
						load_images.c								\
						map_gen.c									\
						player_movement_bis.c						\
						player_movement.c							\
						so_long.c									\
						win_init.c			


LST_OBJS			=	${LST_SRCS:.c=.o}
SRCS				=	$(addprefix ${P_SRCS}${LST_SRCS})
OBJS				=	$(addprefix ${P_OBJS},${LST_OBJS})

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
SRCS_B				=	$(addprefix ${P_SRCS_B},${LST_SRCS_B})
OBJS_B				=	$(addprefix ${P_OBJS_B},${LST_OBJS_B})

CC					=	gcc
CFLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf
LFTA				=	${P_LFT}libft.a
LMLX				=	${P_MLX}libmlx.dylib
USAGE		=	$(BLUE)$(BOLD)Usage : ./${NAME} maps/<map>.ber $(RESET)\n
USAGE_B		=	$(BLUE)$(BOLD)Usage Bonus Part : ./${NAME} maps/<map>.ber $(RESET)\n


#///////////////////////////////////////////////////////////////////////////////

# Colors
BLACK		=	\033[30m
RED			=	\033[31m
GREEN		=	\033[32m
YELLOW		=	\033[33m
BLUE		=	\033[34m
PURPLE		=	\033[35m
CYAN		=	\033[36m
WHITE		=	\033[37m

# Text
ERASE		=	\033[2K\r
RESET		=	\033[0m
BOLD		=	\033[1m
FAINT		=	\033[2m
ITALIC		=	\033[3m
UNDERLINE	=	\033[4m

BBLU 		=	\033[1;34m
BGREEN		=	\033[1;32m
BRED		=	\033[1;31m
BLU 		=	\033[0;34m
MGT			=	\033[0;35m
LMGT		=	\033[0;95m
LBLU 		=	\033[0;96m
GRN 		=	\033[0;32m
RED 		=	\033[0;31m
GRY 		=	\033[0;90m

#///////////////////////////////////////////////////////////////////////////////

all : print_header makelft makelmx norm bonus usage print_bottom

# Rules

norm : ${NAME}

${NAME} : ${P_OBJS} ${OBJS} ${HEADER} ${LFTA}
	@${CC} ${CFLAGS} ${OBJS} ${LFTA} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME}
	@cp mlx/libmlx.dylib .
	@printf "\n$(GREEN)$(BOLD)Copy libmlx.dylib done$(RESET)	✅"
	@printf "\n$(GREEN)$(BOLD)Binary $(NAME) created$(RESET)	✅\n\n"

${P_OBJS}%.o:${P_SRCS}%.c ${HEADER} ${LFTA} Makefile | ${P_OBJS}
	@${CC} ${CFLAGS} -Imlx -c $< -o $@
	@printf "$(FAINT)$(CC) $(CFLAGS) -c -o $(RESET)$(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

# Rules For Bonus

bonus :	${NAME_B}

${NAME_B} :	${P_OBJS_B} ${OBJS_B} ${HEADER_B} ${LFTA}
	@${CC} ${CFLAGS} ${OBJS_B} ${LFTA} -Lmlx -lmlx -framework OpenGL -framework AppKit -o ${NAME_B}
	@cp mlx/libmlx.dylib .
	@${RM} ${P_TRA}
	@mkdir ${P_TRA}
	@touch ${P_TRA}trace.txt
	@printf "\n$(GREEN)$(BOLD)Copy libmlx.dylib done$(RESET)	✅"
	@printf "\n$(GREEN)$(BOLD)Trace folder created$(RESET)	✅"
	@printf "\n$(GREEN)$(BOLD)Binary $(NAME_B) created$(RESET)	✅\n"


${P_OBJS_B}%.o: ${P_SRCS_B}%.c ${HEADER_B} ${LFTA} Makefile | ${P_OBJS_B}
	@${CC} ${CFLAGS} -Imlx -c $< -o $@
	@printf "$(FAINT)$(CC) $(CFLAGS) -c -o $(RESET)$(CYAN)$(BOLD)$@$(RESET) $(FAINT)$(BLUE)$<$(RESET)\n"

# Rules For Objects Folder

$(P_OBJS):
	@mkdir -p $(P_OBJS)
	@printf "$(GREEN)$(BOLD)${NAME} objects directories created$(RESET)	✅\n\n"

$(P_OBJS_B): 
	@mkdir -p $(P_OBJS_B)
	@printf "$(GREEN)$(BOLD)${NAME_B} objects directories created$(RESET)	✅\n\n"

print_header:
	@echo "${GRY}====================================================${RESET}\n"
	@echo " ▄▄▄▄▄▄▄ ▄▄▄▄▄▄▄    ▄▄▄     ▄▄▄▄▄▄▄ ▄▄    ▄ ▄▄▄▄▄▄▄ "
	@echo "█       █       █  █   █   █       █  █  █ █       █"
	@echo "█  ▄▄▄▄▄█   ▄   █  █   █   █   ▄   █   █▄█ █   ▄▄▄▄█"
	@echo "█ █▄▄▄▄▄█  █ █  █  █   █   █  █ █  █       █  █  ▄▄ "
	@echo "█▄▄▄▄▄  █  █▄█  █  █   █▄▄▄█  █▄█  █  ▄    █  █ █  █"
	@echo " ▄▄▄▄▄█ █       █  █       █       █ █ █   █  █▄▄█ █"
	@echo "█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█  █▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█▄█  █▄▄█▄▄▄▄▄▄▄█"
	@echo "\n${GRY}====================================================${RESET}\n"

usage:
	@printf "$(USAGE)"
	@printf "$(USAGE_B)"

print_bottom:
	@echo "\n${GRY}=================================================${RESET}\n"
	@echo " ▄   ▄▄▄ ▄▄▄▄▄▄▄ ▄▄▄     ▄▄   ▄▄ ▄▄▄▄▄▄▄ ▄▄    ▄ "
	@echo "█ █ █   █       █   █   █  █ █  █       █  █  █ █"
	@echo "█ █▄█   █▄▄▄▄   █   █   █  █▄█  █   ▄   █   █▄█ █"
	@echo "█       █▄▄▄▄█  █   █   █       █  █ █  █       █"
	@echo "█▄▄▄    █ ▄▄▄▄▄▄█   █▄▄▄█▄     ▄█  █▄█  █  ▄    █"
	@echo "    █   █ █▄▄▄▄▄█       █ █   █ █       █ █ █   █"
	@echo "    █▄▄▄█▄▄▄▄▄▄▄█▄▄▄▄▄▄▄█ █▄▄▄█ █▄▄▄▄▄▄▄█▄█  █▄▄█"
	@echo "\n${GRY}==================>${RESET} By ${LMGT}dvilard${RESET} ${GRY}<=================${RESET}\n"

$(LFTA): makelft

makelft:
	@${MAKE} -C libft

$(LMLX): makelmx

makelmx:
	@${MAKE} -C ./mlx
	@cp mlx/libmlx.dylib .

# Clean Rules
clean :
	@${RM} ${OBJS}
	@${RM} ${P_OBJS}
	@printf "$(YELLOW)$(BOLD)All ${NAME} object files removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)${NAME} object folders removed$(RESET)\n"
	@${RM} ${OBJS_B}
	@${RM} ${P_OBJS_B}
	@${RM} ${P_TRA}
	@printf "$(YELLOW)$(BOLD)All ${NAME_B} object files removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)${NAME_B} object folders removed$(RESET)\n"
	@printf "$(YELLOW)$(BOLD)Trace files removed$(RESET)\n"

fclean :	
	@${MAKE}	clean
	@${RM} ${NAME} 
	@${RM} ${NAME_B}
	@$(MAKE) fclean -C ${P_LFT}
	@$(MAKE) clean -C ${P_MLX}
	@${RM} libmlx.dylib	
	@printf "$(RED)$(BOLD)Binary $(NAME) removed $(RESET)\n"
	@printf "$(RED)$(BOLD)Binary $(NAME_B) removed $(RESET)\n"

# Re Rule

re :		
	@${MAKE} fclean
	@${MAKE} all