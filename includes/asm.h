/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:06:00 by smortier          #+#    #+#             */
/*   Updated: 2018/06/07 19:10:05 by spliesei         ###   ########.fr       */
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

/*
**	save functions
**/

void	save_live(t_params *params, char *line);
void	save_ld(t_params *params, char *line);
void	save_st(t_params *params, char *line);
void	save_add(t_params *params, char *line);
void	save_sub(t_params *params, char *line);
void	save_and(t_params *params, char *line);
void	save_or(t_params *params, char *line);
void	save_xor(t_params *params, char *line);
void	save_zjmp(t_params *params, char *line);
void	save_ldi(t_params *params, char *line);
void	save_sti(t_params *params, char *line);
void	save_fork(t_params *params, char *line);
void	save_lld(t_params *params, char *line);
void	save_lldi(t_params *params, char *line);
void	save_lfork(t_params *params, char *line);
void	save_aff(t_params *params, char *line);

/*
**	check parameters
**/

int		check_live_par(char *line);
int		check_ld_par(char *line);
int		check_st_par(char *line);
int		check_add_par(char *line);
int		check_sub_par(char *line);
int		check_and_par(char *line);
int		check_or_par(char *line);
int		check_xor_par(char *line);
int		check_zjmp_par(char *line);
int		check_ldi_par(char *line);
int		check_sti_par(char *line);
int		check_fork_par(char *line);
int		check_lld_par(char *line);
int		check_lldi_par(char *line);
int		check_lfork_par(char *line);
int		check_aff_par(char *line);

/*
**	utility functions
**/

char	*skip_whitespace(char *line);

void	ft_error(char *line);

#endif
