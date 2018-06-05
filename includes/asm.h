/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:06:00 by smortier          #+#    #+#             */
/*   Updated: 2018/06/05 15:03:17 by smortier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H

# define ASM_H

#include "libft.h"

#include "op.h"

typedef struct		s_label
{
	int					pos;
	int					value;
	char				*name;
	struct s_label		*next;
}					t_label;

typedef	struct		s_instr
{
	int					id;
	char				*name;
	int					nb_arg;
	char				**arg;//les arg en valeur brut
	int					arg_type[3];//type de l'arg = 1:label(2oct), 2:direct(4), 3:indirect(2), 4:registre(1)
	int					arg_value[3];//valeur de l'arg en fonction de son type.
	int					ocp; //trouve la velur de l'ocp si yen a un, en fct des args
	struct s_instr		*next;
}					t_instr;

typedef struct		s_lexer
{
	char			*line;
	struct s_lexer	*next;
}					t_lexer;

typedef struct		s_params
{
	char		**file;
	t_lexer		*lexer;
	t_label		*label;
}					t_params;

void	lexer(t_params *params);

void	get_label(t_params *params);

int		str_is_empty(char *str);

void	get_instr(t_params *params);

#endif

