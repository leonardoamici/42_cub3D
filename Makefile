CC = gcc

NAME = cub3D

LIBFT = Libft/libft.a

MLX = minilibx-linux/libmlx.a

SRC =	main.c

PTH = source/

FLAGS = -Wall -Werror -Wextra

FLAGS_2 = -lm -lX11 -lXext -o

SRC := $(addprefix $(PTH),$(SRC))

OBJ_S = $(SRC:.c=.o)

all: $(NAME)

libcomp:
		@make -C Libft

$(NAME): libcomp $(OBJ_S) $(OBJ_C) $(OBJ_E)
	$(CC) $(FLAGS) $(OBJ_S) $(LIBFT) $(MLX) $(FLAGS_2) $(NAME)
	@echo "\033[94m$(NAME) ready\033[0m"

libclean:
		@make clean -C Libft

clean:		libclean
		rm -rf $(OBJ_S)
libfclean:
		@make fclean -C Libft

fclean:   	libfclean clean
		rm -rf $(NAME)
		@echo "\033[95m$(NAME) removed\033[0m"
		
re: clean all

.PHONY: all re clean fclean bonus

.SILENT:
