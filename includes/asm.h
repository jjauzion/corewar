/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:06:00 by smortier          #+#    #+#             */
/*   Updated: 2018/06/03 13:47:16 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define ASM_H

#include "libft.h"

typedef struct		s_label
{
	int					Adress;
	int					value;
	char				*name;
	struct s_label		*next;
}					t_label;

typedef union		u_test
{
	int			val;
	char		*value;
}					t_test;

typedef struct		s_lexer
{
	char			*name;
	int				instruction_id;
	int				instruction_number;
	int				instruction_octal;
	int				arg_type[3]; // 1: reg, 2:label, 3:direct, 4:indirect
	char			**arg; // "valeur brut"
	int				value_arg[3]; // valeur de chaque arg (Dans un deuxieme temps)
	struct s_lexer	*next;
}					t_lexer;

#endif
