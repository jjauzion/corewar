# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/08 11:25:23 by jjauzion          #+#    #+#              #
#    Updated: 2018/06/11 19:07:29 by spliesei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB, asm

SRC_NAME1 =	main.c \
		lexer.c \
		get_label.c \
		str_is_empty.c \
		get_instr.c \
		analyze_line.c \
		utility.c \
		utils.c \
		save.c \
		error.c \
		check_live.c \
		check_ld.c \
		check_fork.c \
		check_lld.c \
	 	check_lldi.c \
		check_lfork.c \
		check_aff.c \
		check_st.c \
		check_add.c \
		check_sub.c \
		check_and.c \
		check_or.c \
		check_xor.c \
		check_zjmp.c \
		check_ldi.c \
		check_sti.c \
		save_add.c \
		save_tools.c \
		save_and.c \
		save_sub.c \
		save_or.c \
		save_xor.c \
		save_zjmp.c \
		save_ldi.c \
		save_sti.c \
		save_fork.c \
		save_lldi.c \
		save_lld.c \
		save_lfork.c \
		save_aff.c \
		save_live.c \
		save_ld.c \
		save_st.c





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

INC_NAME2 = vm.h

NAME = ../asm

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

all: LIB $(NAME)

$(NAME): $(LDFLAGS) $(OBJ1) $(OBJ2)
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ1) $(OBJ2) -o $(NAME)

LIB:
	@make -C $(LIB_PATH)

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
