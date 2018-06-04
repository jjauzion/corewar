/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/04 17:22:38 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"
# include "ft_printf.h"

# define SUCCESS 0

typedef	struct			s_op
{
	char		*name;
	int			nb_arg;
	int			arg_type[3];
	int			op_code;
	int			nb_cylce;
	char		*def;
	int			m_carry;
	int			plop;
}						t_op;

typedef struct			s_process
{
	char				reg[REG_NUMBER][REG_SIZE];
	int					pc;
	char				carry;
	int					exe_cycle;
	t_op				*op;
	struct s_process	*next;
}						t_process;

typedef struct			s_champion
{
	int			id;
	int			nb_live;
	uintmax_t	last_live_cycle;	
	header_t	header;
	char		*code;
}						t_champion;

typedef struct			s_arena
{
	char			*mem;
	uintmax_t		cycle;
	int				cycle2die;
	t_champion		*players;
	int				nb_champion;
}						t_arena;

void					*error_ptr(void *ptr, char *msg);
int						error_int(char *msg);
t_champion				*read_champ(char *file);
t_champion				**check_input(int argc, char **argv, int *option, int *nb_champ);
int						option(int *index, char **argv, char *valid_option, int *option);
void					print_option(int option);
int						write_champions(t_arena *arena, t_champion **champions);

#endif
