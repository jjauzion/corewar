/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smortier <smortier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 13:06:00 by smortier          #+#    #+#             */
/*   Updated: 2018/06/18 16:59:06 by spliesei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

#include "libft.h"
#include "op.h"
#include <limits.h>

# define REG_BYTES				1
# define IND_BYTES				2
# define DIR_BYTES				4

typedef struct		s_label
{
	int					pos; // means the line in the file
	int					instr;
	int					value;
	char				*name;
	struct s_label		*next;
}					t_label;

typedef	struct		s_instr
{
	int					id; // supposed to his place in the memory
	int					d2;
	int					opcode;
	int 				address;
	int					nbr_arg;
	char				**arg; //just the args withouts parsings
	int					*arg_type; //type of the arg like : 1 for label, 2 for direct etc
	int					*arg_value; //final parsing to get the value of each arg
	int					ocp; //the ocp finded thx to arg_type
	int 				nbr_bytes;
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
	int			file_len;
	char		*file_name;
	header_t	header;
	t_lexer		*lexer;
	t_label		*label;
	t_instr		*instr;
}					t_params;

void	lexer(t_params *params);

void	get_label(t_params *params);

int		str_is_empty(char *str);

void	get_instr(t_params *params);
void	analyze_line(t_params *params, char *line, int index_line);
void	init_instr(t_params *params);
void 	get_label_instr(t_params *params);
void	fill_arg_values(t_params *params);
void	write_bytecode(t_params *params);
int		get_program_size(t_params *params);


/*
**	check label
**/


void 	check_label_name(t_params *params, char *name);



/*
**	save functions
**/

void	get_params(t_instr *tmp, char *line);
void 	calc_ocp(t_instr *tmp);
void	fill_arg_types(t_params *params, t_instr *tmp);
void	calc_bytes(t_instr *tmp);
void	print_header(int file, t_params *params);
void	printbits_int(unsigned int v, int fd);



void	save_live(t_params *params, int id, char *line);
void	save_ld(t_params *params, int id, char *line);
void	save_st(t_params *params, int id, char *line);
void	save_add(t_params *params, int id, char *line);
void	save_sub(t_params *params, int id, char *line);
void	save_and(t_params *params, int id, char *line);
void	save_or(t_params *params, int id, char *line);
void	save_xor(t_params *params, int id, char *line);
void	save_zjmp(t_params *params, int id, char *line);
void	save_ldi(t_params *params, int id, char *line);
void	save_sti(t_params *params, int id, char *line);
void	save_fork(t_params *params, int id, char *line);
void	save_lld(t_params *params, int id, char *line);
void	save_lldi(t_params *params, int id, char *line);
void	save_lfork(t_params *params, int id, char *line);
void	save_aff(t_params *params, int id, char *line);

/*
**	check parameters
**/

int		check_live_par(t_params *params, char *line, int index_line);
int		check_ld_par(t_params *params, char *line, int index_line);
int		check_st_par(t_params *params, char *line, int index_line);
int		check_add_par(t_params *params, char *line, int index_line);
int		check_sub_par(t_params *params, char *line, int index_line);
int		check_and_par(t_params *params, char *line, int index_line);
int		check_or_par(t_params *params, char *line, int index_line);
int		check_xor_par(t_params *params, char *line, int index_line);
int		check_zjmp_par(t_params *params, char *line, int index_line);
int		check_ldi_par(t_params *params, char *line, int index_line);
int		check_sti_par(t_params *params, char *line, int index_line);
int		check_fork_par(t_params *params, char *line, int index_line);
int		check_lld_par(t_params *params, char *line, int index_line);
int		check_lldi_par(t_params *params, char *line, int index_line);
int		check_lfork_par(t_params *params, char *line, int index_line);
int		check_aff_par(t_params *params, char *line, int index_line);


int		check_type(t_params *params, char *arg);

/*
**	utility functions
**/

// void	ft_error(t_params *params, char *line, int index_line);

#endif
