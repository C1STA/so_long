NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBFT = -L libs/libft -lft
LIBX = -L libs/minilibx-linux -lmlx_Linux
LIBXFLAGS = -lmlx -lXext -lX11

SRCPATH = src/
SRC = display.c \
		errors.c \
		free.c \
		get_map_and_extension_check.c \
		get_sprites.c \
		init_moves.c \
		is_playable.c \
		is_valid_functions.c \
		is_valid.c \
		main.c

OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME): $(OBJ)
	$(MAKE) --no-print-directory -C libs/libft
	$(MAKE) --no-print-directory -C libs/minilibx-linux
	echo "\033[36mMaking So Long\033[0m"
	$(CC) $(OBJ) $(LIBFT) $(LIBX) $(LIBXFLAGS) -o $(NAME) -g
	echo "\033[32mDone\033[0m"

%.o : $(SRCPATH)%.c
	$(CC) -c $^  -g

bonus : all

clean :
	$(MAKE) --no-print-directory fclean -C libs/libft
	echo "\033[35mCleaning Mlx's objects...\033[0m"
	$(MAKE) --no-print-directory clean -C libs/minilibx-linux
	echo "\033[32mDone\033[0m"
	echo "\033[35mCleaning So Long's objects...\033[0m"
	rm -f $(OBJ)
	echo "\033[32mDone\033[0m"

fclean :
	make clean
	echo "\033[35mCleaning So_Long...\033[0m"
	rm -f $(NAME)
	echo "\033[32mDone\033[0m"

re : fclean
	make all

.PHONY : all clean fclean re bonus
.SILENT :