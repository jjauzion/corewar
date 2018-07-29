# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 11:25:23 by jjauzion          #+#    #+#              #
#    Updated: 2018/07/29 20:22:34 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB

SRC_NAME1 = main.c \
			op.c \
			fct_op.c \
			error.c \
			read_champ.c \
			option.c \
			check_input.c \
			init_arena.c \
			create_process.c \
			run_arena.c \
			libcorewar1.c \
			libcorewar2.c \
			read_op.c \
			exec_op.c \
			print_arena.c \
			op_fct_1.c \
			op_fct_2.c \
			op_fct_3.c \
			op_fct_4.c \
			op_fct_5.c \
			verbose.c \
			display.c \
			read_op_code.c

SRC_NAME2 = 

SRC_PATH1 = 

SRC_PATH2 =

OBJ_PATH1 = .obj/

LIB_PATH = ../libft/

LDLIBS = libftprintf.a

EXT_LIB =

INC_PATH1 = ../libft/

INC_PATH2 = ../includes/

INC_NAME1 = libft.h

INC_NAME2 = vm.h \
			op.h

NAME = ../corewar

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

OBJ1 = $(addprefix $(OBJ_PATH1),$(SRC_NAME1:.c=.o))

OBJ2 = $(addprefix $(OBJ_PATH1),$(SRC_NAME2:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_NAME2)) \
	   $(addprefix $(INC_PATH1),$(INC_NAME1))

LDFLAGS = $(addprefix $(LIB_PATH),$(LDLIBS))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: LIB $(NAME) $(INC) Makefile

$(NAME): $(LDFLAGS) $(OBJ1) $(OBJ2)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ1) $(OBJ2) -o $(NAME)

LIB:
	make -C $(LIB_PATH)

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	@make -C $(LIB_PATH) clean
	rm -f $(OBJ1) $(OBJ2)
	@rmdir $(OBJ_PATH1) 2> /dev/null || true

fclean: clean
	@make -C $(LIB_PATH) fclean
	rm -fv $(NAME)

re: fclean all
