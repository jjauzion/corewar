/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:06:00 by smortier          #+#    #+#             */
/*   Updated: 2018/06/07 17:12:14 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "op.h"

typedef struct		s_label
{
	int					pos; // means the line in the file
	int					value;
	char				*name;
	struct s_label		*next;
}					t_label;

typedef	struct		s_instr
{
	int					id; // supposed to his place in the memory
	char				*name;
	int					nb_arg; // number of arg
	char				**arg; //just the args withouts parsings
	int					arg_type[3]; //type of the arg like : 1 for label, 2 for direct etc
	int					arg_value[3]; //final parsing to get the value of each arg
	int					ocp; //the ocp finded thx to arg_type
	struct s_instr		*next;
}					t_instr;

typedef struct		s_lexer //actually just the file cleared from labels
{
	char			*line;
	struct s_lexer	*next;
}					t_lexer;

typedef struct		s_params // The main struct, the one we put in each functions of main
{
	char		**file;
	t_lexer		*lexer;
	t_label		*label;
	t_instr		*instr;
}					t_params;

void	lexer(t_params *params);

void	get_label(t_params *params);

int		str_is_empty(char *str);

void	get_instr(t_params *params);

#endif
