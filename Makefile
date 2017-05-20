# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 04:47:56 by mchemakh          #+#    #+#              #
#    Updated: 2017/05/20 00:57:06 by mchemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_NAME = main.c init.c parser.c clear.c ft_get_file.c window.c event.c error.c display.c storage.c

SRCS_PATH = srcs/

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = objs/

LIB = libft/
LIB_NAME = -lft
LIB_PATH = -L./libft/

LIB_MLX = ressources/minilibx_macos_sierra_20161017/
LIB_MLX_NAME = -lmlx -framework OpenGL -framework AppKit
LIB_MLX_PATH = -L./ressources/minilibx_macos_sierra_20161017/

INC_PATH = -I includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
#	@make -C $(LIB)
#	@make -C $(LIB_MLX)
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) -g -o $(NAME) $(LIB_PATH) $(LIB_NAME) $(LIB_MLX_PATH) $(LIB_MLX_NAME)


$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_PATH) -g -o $@ -c $?

clean:
	@rm -rf $(OBJ_PATH)
#	@make clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
#	@make clean -C $(LIB_MLX)
#	@make fclean -C $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re
