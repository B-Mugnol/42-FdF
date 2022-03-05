# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/26 20:05:24 by bmugnol-          #+#    #+#              #
#    Updated: 2022/03/05 19:36:31 by bmugnol-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	:=	fdf

CC		:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror


# FDF
SRC_DIR		:=	./src
SRC_FILE	:=	error.c fdf.c hook.c line_draw.c map.c render.c setup.c
SRC_FILE	+=	transformation.c verifier.c
SRC			:=	$(addprefix $(SRC_DIR)/, $(SRC_FILE))

HEADER_FILE	:=	fdf.h define.h struct.h
HEADER_DIR	:=	./inc
HEADER		:=	$(addprefix $(HEADER_DIR)/, $(HEADER_FILE))
H_INCLUDE	:=	$(foreach directory, $(HEADER_DIR), -I$(directory))


# LIBFT
LIBFT_DIR		:=	../libft

LIBFT_H_FILE	:=	libft.h ft_printf.h
LIBFT_H_DIR		:=	$(LIBFT_DIR)/inc
LIBFT_HEADER	:=	$(addprefix $(LIBFT_H_DIR)/, $(LIBFT_H_FILE))
LIBFT_H_INC		:=	-I$(LIBFT_H_DIR)

LIBFT_LIB		:=	$(LIBFT_DIR)/libftprintf.a
LIBFT_LIB_INC	:=	-L $(LIBFT_DIR) -lftprintf


# MINILIBX
MLX_LIB_INC		:=	-lmlx -lXext -lX11

# <math.h> library
MATH_LIB_INC	:= -lm


# All headers inclusion:
INCLUDE	:=	$(H_INCLUDE) $(LIBFT_H_INC)
# All libraries inclusion:
LIB_INCLUDE	:=	$(LIBFT_LIB_INC) $(MLX_LIB_INC) $(MATH_LIB_INC)


.PHONY: all norm clean fclean re

all: $(NAME)

$(NAME): $(LIBFT_LIB) $(SRC) $(HEADER)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(INCLUDE) $(LIB_INCLUDE)

$(LIBFT_LIB):
	$(MAKE) -C $(LIBFT_DIR) printf

norm:
	@$(MAKE) -C $(LIBFT_DIR) norm
	@norminette $(SRC) $(HEADER) | grep "Error" | cat

clean:
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean:
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all
