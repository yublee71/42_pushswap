# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yublee <yublee@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:30:54 by yublee            #+#    #+#              #
#    Updated: 2024/05/14 23:45:11 by yublee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRS := src/action

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm

RMFLAGS = -fv

AR = ar

ARFLAGS = rcs

INCLUDE = -I include/

NAME = push_swap

#needs editing later
SRC = src/input_process.c \
	src/main.c \
	src/action/rotate.c \
	src/action/reverse_rotate.c \
	src/action/swap.c \
	src/action/push.c \
	src/stack_process.c \
	src/small_numbers.c \
	src/big_numbers.c \
	src/utils.c \

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)

LIBFT_DIR = ./libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a

BUILD_DIR = build

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(BUILD_DIR) $(OBJ)
	$(CC) -L$(LIBFT_DIR) $(OBJ) -g -o $@ -lft

$(LIBFT_LIB):
	make -C $(LIBFT_DIR)

$(BUILD_DIR):
	mkdir -pv $(BUILD_DIR) $(patsubst %,$(BUILD_DIR)/%,$(DIRS))

$(BUILD_DIR)/%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $^ -o $@

clean:
	$(RM) -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(LIBFT_LIB)

re: fclean all

.PHONY: all clean fclean re
