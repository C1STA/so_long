NAME := so_long.a
SOFT_NAME := so_long

CC := gcc
FLAGS := -g3 -Wall -Wextra -I includes/
SRC_DIR := src/
OBJ_DIR := obj/
AR := ar rc
RM := rm
VAL := valgrind --leak-check=full --track-origins=yes
MLXFLAGS := -L libs/minilibx-linux/ -lmlx -lXext -lX11 -lz -lm

BLACK = \033[1;30m
REDBG = \033[30;41m
RED = \033[0;31m
GREEN = \033[0;32m
ORANGE = \033[0;33m
BLUE = \033[0;34m
MAGENTA = \033[0;35m
CYAN = \033[0;36m
NC = \033[0m

SRCS = getmap_and_extension_check.c	\
	is_valid.c	\
	is_valid_functions.c \
	is_playable.c	\
	display_map.c \
	get_sprites.c \
	init_moves.c \
	free.c \
	so_long.c	\
	errors.c \

LIBFT := libs/libft/libft.a
MLX := libs/minilibx-linux/libmlx_Linux.a
FCLIB := ${MAKE} fclean -C libs/libft
CMLX := ${MAKE} clean -C libs/minilibx-linux

OBJS = $(SRCS:%.c=%.o)
NORM = $(wildcard *.c) $(wildcard *.h)

OBJ = $(addprefix $(OBJ_DIR),$(OBJS))

OBJF := .cache_exists

all : ${LIBFT} ${NAME} ${SOFT_NAME}

${LIBFT} :
	${MAKE} all -C libs/minilibx-linux
	${MAKE} all -C libs/libft
	cp ${LIBFT} ${NAME}

${NAME} : ${OBJ}
	@echo "${BLUE}###${NC}Update de l'archive ${NAME}${BLUE}###${MAGENTA}"
	${AR} ${NAME} ${MLX} ${OBJ}
	@echo "${NC}"

${OBJ_DIR}%.o : %.c | $(OBJF)
	@echo "${BLUE}###${NC}Creation du fichier ${@:%.c=%.o}${BLUE}###${ORANGE}"
	${CC} ${FLAGS} ${MLXFLAGS} -c $< -o $@
	@echo "${NC}"

${SOFT_NAME} :
	@echo "${BLUE}###${NC}Creation du fichier ${SOFT_NAME}${BLUE}###${ORANGE}"
	${CC} ${NAME} ${FLAGS} ${MLXFLAGS} -o ${SOFT_NAME}
	@echo "${NC}"

$(OBJF) :
	@mkdir -p ${OBJ_DIR}

test : all
	${VAL} ./${SOFT_NAME} "map.ber"

lldb :
	${CC} -g3 ${SRCS} ${LIBFT} ${MLXFLAGS} -o ${SOFT_NAME}
	lldb ./${SOFT_NAME} "map.ber"

clean : 
	${FCLIB}
	${CMLX}
	@echo "${RED}###${NC}Nettoyage des fichiers .o${RED}###"
	${RM} -rf ${OBJ_DIR}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

fclean : clean
	@echo "${RED}###${NC}Nettoyage d'archives et de Softs${RED}###"
	${RM} -f ${NAME} ${SOFT_NAME}
	@echo "${GREEN}###${NC}Nettoyage OK${GREEN}###${NC}\n"

re : fclean all