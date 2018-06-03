/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 19:05:55 by jjauzion         ###   ########.fr       */
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
}						t_arena;

void					*error_ptr(char *msg);
int						error_int(char *msg);
t_champion				*read_champ(int argc, char **argv, int nb_champ);

#endif
