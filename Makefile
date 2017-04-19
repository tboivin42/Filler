# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tboivin <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/02/22 20:14:00 by tboivin           #+#    #+#              #
#    Updated: 2017/04/08 01:22:49 by tboivin          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= tboivin.filler

SRC		= srcs/filler.c srcs/get.c srcs/start.c srcs/direction.c srcs/clean.c srcs/recup.c srcs/plus.c srcs/plus_.c

OBJ		= $(SRC:.c=.o)

CFLAGS	= -Wall -Wextra -Werror -g -I includes/

$(NAME): $(OBJ)
	@make -C libft
	@gcc $(OBJ) -o $(NAME) -L libft/ -lft -I libft/includes/

all: $(NAME)

clean:
	@make -C libft/ clean
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME) $(OBJ)
	@make -C libft/ fclean

re: fclean $(NAME)
