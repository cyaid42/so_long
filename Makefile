# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/09 23:21:05 by cyaid             #+#    #+#              #
#    Updated: 2024/01/24 05:47:22 by cyaid            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = utils/get_next_line/get_next_line.c\
       utils/get_next_line/get_next_line_utils.c\
	   utils/Printf/ft_printf.c\
	   utils/Printf/ft_printf_fonction.c\
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
	free_and_exit/free_imagev2.c\
	check/extension.c\

OBJS = ${SRCS:.c=.o}

CC = cc

CFLAGS = -g3 -Wall -Wextra #-Werror

LFLAGS = -L./mlx_linux -lmlx -Ilmlx -lXext -lX11

MLX = mlx_linux/libmlx.a

# MLXL = 	@make -C ./mlx_linux


IFLAGS = -I./

RM = rm -f

all: ${NAME}

$(NAME): ${OBJS}
	$(MAKE) -C ./mlx_linux
	${CC} ${OBJS} ${MLXL} ${LFLAGS} -o $(NAME)

%.o:%.c
	${CC} ${IFLAGS} ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
	${RM} ${OBJS}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY:  all clean fclean re
