# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 20:05:24 by bmugnol-          #+#    #+#              #
#    Updated: 2022/02/28 23:29:50 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

CC		:=	gcc
CFLAGS	:=	#-Wall -Wextra -Werror


# FDF
SRC_DIR		:=	./src
SRC_FILE	:=	fdf.c	setup.c	render.c line_draw.c	maps.c	transformations.c hooks.c	error.c	verifiers.c
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

HEADER_FILE	:=	fdf.h defines.h
HEADER_DIR	:=	./inc
HEADER		:=	$(addprefix $(HEADER_DIR)/, $(HEADER_FILE))
H_INCLUDE	:=	$(foreach directory, $(HEADER_DIR), -I$(directory))


# LIBFT
LIBFT_DIR		:=	../libft

LIBFT_H_DIR		:=	$(LIBFT_DIR)/inc
LIBFT_HEADER	:=	$(LIBFT_H_DIR)/libft.h
LIBFT_H_INC		:=	-I$(LIBFT_H_DIR)

LIBFT_LIB		:=	$(LIBFT_DIR)/libft.a
LIBFT_LIB_INC	:=	-L $(LIBFT_DIR) -lft


# All headers inclusion:
INCLUDE	:=	$(H_INCLUDE) $(LIBFT_H_INC)


# MINILIBX
MLX_LIB_INC	:=	-lmlx -lXext -lX11

# <math.h>
MATH_LIB_INC	:= -lm

.PHONY: all norm clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(INCLUDE) $(LIBFT_LIB_INC) $(MLX_LIB_INC) $(MATH_LIB_INC)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) basic

norm:
	$(MAKE) -C $(LIBFT_DIR) norm
	norminette $(SRC) $(HEADER)

clean:
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
