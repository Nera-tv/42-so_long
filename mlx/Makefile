.SILENT:


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3

HEADER = mlx.h

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

#///////////////////////////////////////////////////////////////////////////////

# Colors
BLACK=\033[30m
RED=\033[31m
GREEN=\033[32m
YELLOW=\033[33m
BLUE=\033[34m
PURPLE=\033[35m
CYAN=\033[36m
WHITE=\033[37m

# Text
ERASE=\033[2K\r
RESET=\033[0m
BOLD=\033[1m
FAINT=\033[2m
ITALIC=\033[3m
UNDERLINE=\033[4m

#///////////////////////////////////////////////////////////////////////////////

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ) $(HEADER)
	@swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz
	@printf "$(FAINT)$ $(CC) $(CFLAGS) -c -o $(RESET)$(PURPLE)$(BOLD)mlx_xpm.o$(RESET) $(FAINT)$(PURPLE)mlx_xpm.c$(RESET)\n"
	@printf "$(FAINT)$ $(CC) $(CFLAGS) -c -o $(RESET)$(PURPLE)$(BOLD)mlx_png.o$(RESET) $(FAINT)$(PURPLE)mlx_png.c$(RESET)\n"
	@printf "$(FAINT)$ $(CC) $(CFLAGS) -c -o $(RESET)$(PURPLE)$(BOLD)mlx_string_put.o$(RESET) $(FAINT)$(PURPLE)mlx_string_put.c$(RESET)\n"
	@printf "$(PURPLE)$(BOLD)Library $(NAME) created$(RESET)\n"

%.o: %.swift $(HEADER)
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@
	@printf "$(FAINT)$ swiftc $(OPTI) $(INC) -parse-as-library -c -o $(RESET)$(PURPLE)$(BOLD)$@$(RESET) $(FAINT)$(PURPLE)$<$(RESET)\n"

%.swiftmodule: %.swift
	@swiftc $(OPTI) $(INC) -parse-as-library -c $< -o $@ -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<)

clean:
	@rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

