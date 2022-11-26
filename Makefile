NAME = so_long

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = so_long.c\

OBJS = $(SRCS:%.c=build/%.o)

build/%.o: %.c
	@mkdir -p build
	${CC} ${CFLAGS} -c $< -o $@

%.o: %.c
	$(CC) -Wall -Wextra -Werror -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

clean:
	@rm -rf  build
	@echo "Build folder erased, cya .."

fclean: clean
	@rm -f $(NAME)
	@rm -f $(NAME_BONUS)
	@echo "Mr Propre ;)"

re: fclean all