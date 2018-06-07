/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_op.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjauzion <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 13:43:43 by jjauzion          #+#    #+#             */
/*   Updated: 2018/06/07 10:18:26 by jjauzion         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"
#include "op.c"

static int			get_op_size(int arg_type[3], int nb_arg)
{
	int	i;
	int	op_size;

	i = 0;
	op_size = 1;
	while (i < nb_arg)
	{
		if (arg_type[i] == REG_CODE)
		{
			op_size += 1; //check define
			printf("i :%d  op_size : %d\n", i, op_size );
		}
		if (arg_type[i] == DIR_CODE)
			op_size += DIR_SIZE;
		if (arg_type[i] == IND_CODE)
			op_size += IND_SIZE;
		i++;
	}
	return (op_size);
}
	

static int		read_ocp(t_op *op, int op_index, t_process *process)
{
	int		i;
	int		ret;

	ret = SUCCESS;
	process->op_size = 1;
	printf("op-ocp = %c\n", op->ocp);
	op->arg_type[0] = op->ocp >> 6;
	op->arg_type[1] = op->ocp >> 4 & 0x3;
	op->arg_type[2] = op->ocp >> 2 & 0x3;
	i = 0;
	while (i < op_tab[i].nb_arg)
	{
		if (op->arg_type[i] == REG_CODE)
			op->arg_type[i] = T_REG;
		if (op->arg_type[i] == DIR_CODE)
			op->arg_type[i] = T_DIR;
		if (op->arg_type[i] == IND_CODE)
			op->arg_type[i] = T_IND;
		/*printf("arg_type[%d] = %d\n", i, op->arg_type[i]);
		printf("op_tab = %d\n", op_tab[op_index].arg_type[i]);
		printf("op_size = %d\n", op_size);*/
		if ((op->arg_type[i] | op_tab[op_index].arg_type[i]) != op_tab[op_index].arg_type[i])
			ret = ERROR;
		i++;
	}
	process->op_size += get_op_size(op->arg_type, op_tab[op_index].nb_arg);
	return (ret);
}

t_op			*read_op(t_arena *arena, t_process *process)
{
	int		i;
	t_op	*op;

	if (!(op = (t_op*)ft_memalloc(sizeof(t_op))))
		return (error_ptr(NULL, "error op malloc\n"));
	op->ocp = 0;
	op->op_code = arena->mem[process->pc];
	i = -1;
	while (op_tab[++i].op_code != op->op_code && op_tab[i].name)
	{}
	if (op_tab[i].name == NULL)
		return (error_ptr(op, ""));
	op->ocp = arena->mem[process->pc + 1];
	if (op_tab[i].ocp == 1 && (read_ocp(op, i, process) == ERROR))
		return (error_ptr(op, ""));
	else if (op_tab[i].ocp == 0)
		process->op_size = get_op_size(op_tab[i].arg_type, op_tab[i].nb_arg);
	op->nb_arg = op_tab[i].nb_arg;
	op->nb_cycle = op_tab[i].nb_cycle;
	process->exe_cycle = arena->cycle + op->nb_cycle;
	return (op);
}
