# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbrandt <bbrandt@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/28 15:51:08 by bbrandt           #+#    #+#              #
#    Updated: 2017/09/11 16:34:59 by bbrandt          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC = 	srcs/main.c \
		srcs/tools.c \
		srcs/julia.c \
		srcs/mandelbrot.c \
		srcs/burningship.c \
		srcs/hooks.c \
		srcs/more_options.c

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C lib/libft
	gcc -o $(NAME) $(FLAGS) $(OBJ) lib/libft/libft.a -lmlx -framework OpenGL -framework AppKit
	@echo "fractol done"

clean:
	make clean -C lib/libft
	rm -f $(OBJ)

fclean: clean
	make fclean -C lib/libft
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
