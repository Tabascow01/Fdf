# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mchemakh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/10 04:47:56 by mchemakh          #+#    #+#              #
#    Updated: 2017/05/10 05:06:00 by mchemakh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS_NAME = main.c

SRCS_PATH = srcs/

OBJ_NAME = $(SRCS_NAME:.c=.o)
OBJ_PATH = objs/

LIB = libft/
LIB_NAME = -lft
LIB_PATH = -L./libft/

INC_PATH = -I includes/

SRC = $(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIB)
	@$(CC) $(CFLAGS) $(INC_PATH) $(OBJ) -o $(NAME) $(LIB_PATH) $(LIB_NAME)


$(OBJ_PATH)%.o: $(SRCS_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC_PATH) -g -o $@ -c $<

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIB)

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C $(LIB)

re: fclean all

.PHONY: all, clean, fclean, re
