# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 11:25:23 by jjauzion          #+#    #+#              #
#    Updated: 2018/06/03 15:40:09 by jjauzion         ###   ########.fr        #
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

$(NAME1):
	make -C vm

$(NAME2): 
	make -C asm

clean:
	@make -C vm clean
#	@make -C asm clean

fclean: clean
	@make -C vm fclean
#	@make -C asm fclean

re: fclean all