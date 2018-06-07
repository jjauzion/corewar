/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/07 18:55:00 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"
# define SUCCESS 0

typedef	struct			s_op
{
	char			*name;
	int				nb_arg;
	int				arg_type[3];
	int				op_code;
	int				nb_cycle;
	char			*def;
	unsigned char	ocp;
	int				dir_size;
}						t_op;

typedef struct			s_process
{
	char				reg[REG_NUMBER][REG_SIZE];
	int					pc;
	char				carry;
	int					exe_cycle;
	t_op				*op;
	int					op_size;
	int					exe_op;
	uintmax_t			last_live_cycle;
	struct s_process	*next;
}						t_process;

typedef struct			s_champion
{
	int			id;
	int			nb_live;
	header_t	header;
	char		*code;
	uintmax_t	last_live_cycle;
}						t_champion;

typedef struct			s_arena
{
	char			*mem;
	int				cycle;
	int				cycle2die;
	int				last_check;
	int				nb_check;
	int				nb_process;
	t_champion		**champions;
	int				nb_champion;
	t_process		*process;
	int				nb_live;
}						t_arena;

typedef struct			s_op_fct
{
	int		op_code;
	int		(*fct)(t_process *process, t_arena *arena);
}						t_op_fct;

void					*error_ptr(void *ptr, char *msg);
int						error_int(char *msg);
t_champion				*read_champ(char *file);
t_champion				**check_input(int argc, char **argv, int *option, int *nb_champ);
int						option(int *index, char **argv, char *valid_option, int *option);
void					print_option(int option);
int						init_arena(t_arena *arena, t_champion **champions);
t_process				*create_process(int address, int id, t_process *origin_process);
int						run_arena(t_arena *arena);
int						mem2int(char *mem, int size);
t_op					*read_op(t_arena *arena, t_process *process);
int						exec_op(t_process *process, t_arena *arena);
int						get_address(int address);

int						ld(t_process *process, t_arena *arena);

#endif
