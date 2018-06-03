# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 14:43:00 by jjauzion          #+#    #+#              #
#    Updated: 2018/06/03 13:16:07 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB

SRC_ASM = 

SRC_VM = 

SRC_G = 

SRC_PATH_VM = vm

SRC_PATH_ASM = asm

SRC_PATH_G = global

OBJ_PATH_ASM = .obj/

OBJ_PATH_VM = .obj/

OBJ_PATH_G = .obj/

LIB_PATH = libft/

LDLIBS = libftprintf.a

EXT_LIB = 

INC_PATH1 = libft/

INC_PATH2 = includes/

INC_NAME1 = ft_printf.h

INC_ASM = asm.h 

INC_VM = vm.h 

INC_G = op.h 

NAME1 = asm

NAME2 = corewar

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

SRC_ASM = $(addprefix $(SRC_PATH_ASM),$(SRC_ASM))

SRC_VM = $(addprefix $(SRC_PATH_VM),$(SRC_VM))

SRC_G = $(addprefix $(SRC_PATH_G),$(SRC_G))

OBJ_ASM = $(addprefix $(OBJ_PATH_ASM),$(SRC_NAME_ASM:.c=.o))

OBJ_VM = $(addprefix $(OBJ_PATH_VM),$(SRC_NAME_VM:.c=.o))

OBJ_G = $(addprefix $(OBJ_PATH_G),$(SRC_G:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_ASM)) \
	   $(addprefix $(INC_PATH2),$(INC_VM)) \
	   $(addprefix $(INC_PATH1),$(INC_NAME1)) \
	   $(addprefix $(INC_PATH2),$(INC_G))

LDFLAGS = $(addprefix $(LIB_PATH),$(LDLIBS))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: $(NAME1) $(NAME2)

$(NAME1): $(LDFLAGS) $(OBJ_ASM) $(OBJ_G) LIB
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ_ASM) -o $(NAME1)

$(NAME2): $(LDFLAGS) $(OBJ_VM) $(OBJ_G) LIB
	$(CC) $(DBFLAGS) $(LDFLAGS) $(EXT_LIB) $(OBJ_VM) -o $(NAME2)

LIB:
	make -C libft

$(OBJ_PATH_ASM)%.o: $(SRC_PATH_ASM)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH_ASM) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

$(OBJ_PATH_VM)%.o: $(SRC_PATH_VM)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH_VM) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

$(OBJ_PATH_G)%.o: $(SRC_PATH_G)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH_G) 2> /dev/null || true
	$(CC) $(CFLAGS) $(DBFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	make -C libft clean
	rm -f $(OBJ1) $(OBJ2)
	@rmdir $(OBJ_PATH_VM) 2> /dev/null || true
	@rmdir $(OBJ_PATH_ASM) 2> /dev/null || true
	@rmdir $(OBJ_PATH_G) 2> /dev/null || true

fclean: clean
	make -C libft fclean
	rm -fv $(NAME1)
	rm -fv $(NAME2)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)
	norminette $(LIB_PATH)
