# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alejogogi <alejogogi@student.42.fr>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/01 17:42:24 by alejogogi         #+#    #+#              #
#    Updated: 2025/01/06 21:32:26 by alejogogi        ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC =	ft_printf.c ft_putchar.c\
		ft_puthex.c ft_putnbr.c\
		ft_putpointer.c ft_putstr.c\
		ft_putunbr.c\

OBJ = $(SRC:.c=.o)

INCLUDE = ft_printf.h

AR = ar rcs
RM = rm -f

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
 
%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all