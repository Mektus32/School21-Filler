# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/24 17:22:17 by ojessi            #+#    #+#              #
#    Updated: 2019/06/29 19:42:28 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, obj, clean, fclean, red, re, off, grn

NAME = visualizator

# src / ob files
SRC =	visu.c \
		list_fun.c \
		read.c \
		parse_fig.c \
		draw.c \
		keyhook.c \
		draw2.c \
		draw3.c


OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wextra -Werror -Wall -g

# mlx library
MLX = ./minilibx/
MLX_LIB = $(addprefix $(MLX), mlx.a)
MLX_INC = -I ./minilibx
MLX_LNK = -L ./minilibx -l mlx -framework OpenGL -framework AppKit

# ft library
FT = ../libft
FT_INC = -I ../libft
FT_LNK = -L ../libft -l ft

#printf library
PR = ../ft_printf
PR_INC = -I ../ft_printf
PR_LNK = ../ft_printf/libftprintf.a

# directories
SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj grn $(MLX_LIB) $(NAME) off

red:
	@echo "\x1B[31m"

grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(MLX_INC) $(FT_INC) $(PR_INC) -I $(INCDIR) -o $@ -c $<

$(MLX_LIB):
	@make -C $(MLX)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_LNK) $(FT_LNK) $(PR_LNK) -lm -o $(NAME)
	@echo "\x1b[0m"

clean: red
	rm -rf $(OBJDIR)

fclean: clean
	rm -rf $(NAME)

re: fclean all
