# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yublee <yublee@student.42london.com>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/11 15:30:54 by yublee            #+#    #+#              #
#    Updated: 2024/05/16 16:54:14 by yublee           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

DIRS := src/push_swap/action src/checker/action

CC = cc

CFLAGS = -Wall -Wextra -Werror -g

RM = rm

RMFLAGS = -fv

AR = ar

ARFLAGS = rcs

INCLUDE = -I include/

NAME = push_swap

BONUS_NAME = checker

SRC = src/push_swap/main.c \
	src/push_swap/input_process.c \
	src/push_swap/stack_create.c \
	src/push_swap/stack_utils.c \
	src/push_swap/small_numbers.c \
	src/push_swap/big_numbers.c \
	src/push_swap/big_numbers_utils.c \
	src/push_swap/action/rotate.c \
	src/push_swap/action/reverse_rotate.c \
	src/push_swap/action/swap.c \
	src/push_swap/action/push.c \
	src/push_swap/utils.c \

BONUS_SRC = src/checker/main_bonus.c \
	src/checker/action/rotate_bonus.c \
	src/checker/action/reverse_rotate_bonus.c \
	src/checker/action/swap_bonus.c \
	src/checker/action/push_bonus.c \
	src/push_swap/input_process.c \
	src/push_swap/stack_create.c \
	src/push_swap/stack_utils.c \
	src/push_swap/utils.c \

OBJ = $(SRC:%.c=$(BUILD_DIR)/%.o)
BONUS_OBJ = $(BONUS_SRC:%.c=$(BUILD_DIR)/%.o)

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

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(LIBFT_LIB) $(BUILD_DIR) $(BONUS_OBJ)
	$(CC) -L$(LIBFT_DIR) $(BONUS_OBJ) -g -o $@ -lft

clean:
	$(RM) -rf $(BUILD_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	$(RM) $(RMFLAGS) $(LIBFT_LIB)
	$(RM) $(RMFLAGS) $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
