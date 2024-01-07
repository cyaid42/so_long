NAME = so_long

SRCS = get_next_line/get_next_line.c\
	   get_next_line/get_next_line_utils.c\
	   main.c \
		utils/split.c\
		utils/utils.c\
		map_verif/ft_contenu.c\
		map_verif/ft_les_contours.c\
	    map_verif/ft_path_finding.c\
	    map_verif/ft_map_test.c\
		map/ft_direction.c\
		map/ft_direction2.c\
		map/ft_map_running.c\
		game/launch.c\
		game/move.c\
		game/fill_map.c\
		game/move_util.c\
		game/move_util2.c\
		game/location.c\
		free_and_exit/fin.c\
		free_and_exit/free_map.c\
		check/extension.c\

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g

MLX_FLAGS		=	-lm -lXext -lX11

RM = rm -f

all: ${NAME}

.c.o:
			${CC} -c $< -o ${<:.c=.o}

$(NAME): ${SRCS}
			${CC} ${CFLAGS} ${SRCS} ${MLX_FLAGS} mlx_linux/libmlx.a mlx_linux/libmlx_Linux.a -L. -lXext -L. -lX11 -o $(NAME)

clean:
			${RM} ${OBJS}

fclean: clean
			${RM} ${NAME}

re: fclean all


.PHONY:  all clean fclean re
