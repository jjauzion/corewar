/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/03 14:02:07 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/03 15:01:29 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VM_H
# define VM_H

# include "op.h"

typedef	struct		s_op
{
	char		*name;
	int			nb_arg;
	int			arg_type[3];
	int			op_code;
	int			nb_cylce;
	char		*def;
	int			m_carry;
	int			plop;
}					t_op;

# include "op.c"

#endif
