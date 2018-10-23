# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 13:56:16 by lterrail          #+#    #+#              #
#    Updated: 2018/10/23 18:13:12 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC	=	main.c			\
		parse.c			\
		draw.c			\
		key.c			\
		new_image.c		\
		clear_img.c		\
		draw_line.c		\
		rotation.c		\
		color.c			\
		lib_color.c		\
		lib_color2.c	\
		exit.c			\

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
# CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft/includes
LIBLINK	= -L./libft -lft

MLXA = ./miniLibX/mlx.a
MLXINCL = -I./miniLibX
MLXLINK = -L./miniLibX -l mlx -framework OpenGL -framework AppKit

all: obj $(LIBFTA) $(MLXA) $(NAME)

obj:
	mkdir -p ./obj/

./obj/%.o:./src/%.c
	$(CC) $(CFLAGS) $(LIBINCL) $(MLXINCL) -Iincludes -o $@ -c $<

$(LIBFTA):
	make -C ./libft

$(MLXA):
	make -C ./miniLibX

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK) $(MLXLINK)

clean:
	rm -rf ./obj/
	make -C ./libft clean
	make -C ./miniLibX clean

fclean: clean
	rm -rf $(NAME)
	make -C ./libft fclean

re: fclean all
