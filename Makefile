# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 11:25:23 by jjauzion          #+#    #+#              #
#    Updated: 2018/06/28 15:36:40 by smortier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB, vm

NAME1 = vm

NAME2 = asm

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
	CFLAGS =
	DBFLAGS =
endif
ifeq ($(FLAG), debug)
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS = -g3 -fsanitize=address
endif
else
	CFLAGS = -Wall -Wextra -Werror
	DBFLAGS =
endif

all: $(NAME1) $(NAME2)

$(NAME1): virtual_machine
	make -C virtual_machine

$(NAME2): assembleur 
	make -C assembleur

clean:
	@make -C virtual_machine clean
	@make -C assembleur clean

fclean: clean
	@make -C virtual_machine fclean
	@make -C assembleur fclean

re: fclean all
