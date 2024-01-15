# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yublee <yublee@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:30:54 by yublee            #+#    #+#              #
#    Updated: 2024/01/11 19:10:59 by yublee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Wextra -Werror -I

RM = rm

RMFLAGS = -fv

AR = ar

ARFLAGS = rcs

INCLUDE = include

NAME = push_swap

#needs editing later
SRC = src/input_process.c \
	src/main.c \
	src/stack_list.c \
	printf/ft_print_int.c \
	printf/ft_print_str.c \
	printf/ft_print_unsigned.c \
	printf/ft_printf.c \

OBJ = $(SRC:.c=.o)

LIBFT_DIR = ./libft

LIBFT_LIB = $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(OBJ) $()
	$(CC) -L$(LIBFT_DIR) $(OBJ) -o $@ -lft

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

%.o: %.c
	$(CC) -c $(CFLAGS) $(INCLUDE) $< -o $@

clean:
	$(RM) $(RMFLAGS) $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
