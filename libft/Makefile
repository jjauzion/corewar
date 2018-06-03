# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjauzion <jjauzion@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/01/17 14:43:00 by jjauzion          #+#    #+#              #
#    Updated: 2018/05/28 12:05:56 by jjauzion         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re, LIB

SRC_NAME1 = ft_memset.c \
			ft_bzero.c \
			ft_memcpy.c \
			ft_memccpy.c \
			ft_strlen.c \
			ft_strdup.c \
			ft_strcpy.c \
			ft_strncpy.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_atoi.c \
			ft_atoim.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_striteri.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_strext.c \
			ft_itoa.c \
			ft_strrev.c \
			ft_putstr.c \
			ft_putendl.c \
			ft_putchar_fd.c \
			ft_putstr_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_islower.c \
			ft_isupper.c \
			ft_strcapitalize.c \
			ft_strcnew.c \
			ft_sqrt.c \
			ft_uitoa.c \
			ft_realloc.c \
			ft_power.c \
			ft_uitoa_base.c \
			ft_strremap.c \
			ft_strremapi.c \
			ft_count_cinstr.c \
			ft_str_del_char.c \
			ft_putwchar.c \
			ft_putwstr.c \
			ft_strnchr.c \
			ft_ishexa.c \
			ft_wstrcnew.c \
			ft_wstrlen.c \
			ft_wstrsub.c \
			ft_wstrdup.c \
			ft_getnbofutf8byte.c \
			ft_wstr2str.c \
			ft_uni2utf8.c \
			ft_imtoa.c \
			ft_str_itercheck.c \
			ft_isnumber.c \
			ft_max.c \
			ft_min.c \
			ft_tab_mean.c \
			ft_tab_min.c \
			ft_tab_max.c \
			get_next_line.c \
			ft_print_mem.c

SRC_NAME2 =	ft_printf.c \
			ft_parse.c \
			ft_count_specifier.c \
			ft_get_param.c \
			ft_generate_field.c \
			ft_parse_fct.c \
			ft_apply_hashtag.c \
			ft_add_precision.c \
			ft_field_fct.c \
			ft_get_arg.c \
			ft_padding.c \
			ft_int_arg.c \
			ft_uint_arg.c \
			ft_generate_wfield.c \
			ft_clean_utf8str.c \
			char_arg_fct.c \
			ptr_arg.c \
			ft_print_current.c \
			ft_color.c

INC_NAME1 = ft_printf.h \
			libft.h

INC_NAME2 =	specifier.h \
			color_code.h

SRC_PATH1 = 

SRC_PATH2 = ft_printf/

OBJ_PATH1 = .obj/

OBJ_PATH2 = .obj/ft_printf_obj/

LIB_PATH = 

INC_PATH1 = .

INC_PATH2 = ft_printf/

LDLIBS = 

NAME = libftprintf.a

CC = gcc

ifdef FLAG
	ifeq ($(FLAG), no)
	CFLAGS =
endif
ifeq ($(FLAG), debug)
	CFLAGS = -Wall -Wextra -Werror
endif
else
	CFLAGS = -Wall -Wextra -Werror
endif

SRC = $(addprefix $(SRC_PATH1),$(SRC_NAME1)) \
	  $(addprefix $(SRC_PATH2),$(SRC_NAME2))

OBJ = $(addprefix $(OBJ_PATH1),$(SRC_NAME1:.c=.o)) \
	  $(addprefix $(OBJ_PATH2),$(SRC_NAME2:.c=.o))

INC =  $(addprefix $(INC_PATH2),$(INC_NAME2)) \
	   $(INC_NAME1)

LDFLAGS = $(addprefix -L,$(LIB_PATH))

CPPFLAGS = $(addprefix -I,$(INC_PATH1)) \
		   $(addprefix -I,$(INC_PATH2))

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $@ $^
	ranlib $(NAME)

$(OBJ_PATH1)%.o: $(SRC_PATH1)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH1) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

$(OBJ_PATH2)%.o: $(SRC_PATH2)%.c $(INC) Makefile
	@mkdir $(OBJ_PATH2) 2> /dev/null || true
	$(CC) $(CFLAGS) -c $< $(CPPFLAGS) -o $@

clean:
	rm -f $(OBJ)
	@rmdir $(OBJ_PATH2) 2> /dev/null || true
	@rmdir $(OBJ_PATH1) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette $(INC)
