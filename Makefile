# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lterrail <lterrail@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/06/16 13:56:16 by lterrail          #+#    #+#              #
#    Updated: 2018/06/16 14:51:00 by lterrail         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fdf

SRC	=	main.c			\
		drawer.c		\
		functions.c		\
		reader.c		\
		get_next_line.c

OBJ		= $(addprefix ./obj/,$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFTA	= ./libft/libft.a
LIBINCL = -I./libft
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