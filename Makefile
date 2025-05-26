# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejagom <alejagom@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 17:21:35 by alejagom          #+#    #+#              #
#    Updated: 2025/04/24 19:56:31 by alejagom         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3
SRC_DIR = ./src
SRC = $(wildcard $(SRC_DIR)/*.c) 
OBJ = $(SRC:.c=.o)

LIB_DIR = ./libft
LIBFT =	$(LIB_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

INCLUDE = include/push_swap.h
LIBFT_INCLUDE = libft
FT_PRINTF_INCLUDE = ft_printf

RM = rm -f

.PHONY: all clean fclean re

all: $(LIBFT) $(FT_PRINTF) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIB_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(OBJ) $(LIBFT) $(FT_PRINTF)
	$(CC) -o $(NAME) $(OBJ) $(LIBFT) $(FT_PRINTF)
	
	@clear
%.o: %.c 
	$(CC) $(CFLAGS) -c $< -o $@ 
	
clean: 
	$(RM) $(OBJ)
	$(MAKE) -C $(LIB_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean:
	$(RM) $(OBJ) $(NAME)
	$(MAKE) -C $(LIB_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all
