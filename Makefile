# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ojessi <ojessi@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/10 20:38:26 by ojessi            #+#    #+#              #
#    Updated: 2019/06/16 10:14:39 by ojessi           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, obj, red, grn, off, vis

NAME = ojessi.filler

#src / obj files
SRC =   main.c \
        read.c \
        algor.c \
        heapmap.c

OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

# compiler
CC = gcc
CFLAGS = -Wextra -Wall -Werror -g

#ft library
FT = ./libft
FT_LIB = $(addprefix $(FT), libft.a)
FT_INC = -I ./libft
FT_LNK = -L ./libft -l ft

#printf library
PR = ./ft_printf
PR_LIB = $(addprefix $(PR), libftprintf.a)
PR_INC = -I ./ft_printf
PR_LNK = ./ft_printf/libftprintf.a

# visual
VI = ./visual

#directories
SRCDIR = ./src/
INCDIR = ./includes/
OBJDIR = ./obj/

all: obj $(FT_LIB) $(PR_LIB) vis grn $(NAME) off

red:
	@echo "\x1B[31m"
	
grn:
	@echo "\x1B[32m"

off:
	@echo "\x1b[0m"

obj:
	@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(PR_INC) $(FT_INC) -I $(INCDIR) -o $@ -c $<

$(FT_LIB):
	@make -C $(FT)
	
$(PR_LIB):
	@make -C $(PR)

vis:
	@make -C $(VI)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(PR_LNK) $(FT_LNK) -lm -o $(NAME)

clean: red
	/bin/rm -rf $(OBJDIR)
	make -C $(FT) clean
	make -C $(PR) clean
	make -C $(VI) clean

fclean: clean
	/bin/rm -rf $(NAME)
	make -C $(FT) fclean
	make -C $(PR) fclean
	make -C $(VI) fclean

re: fclean all