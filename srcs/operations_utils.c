/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:06:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/21 14:12:23 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	save_operation(t_stack **stack_op, int operation)
{
	t_stack	*tmp;

	if (*stack_op == NULL)
		*stack_op = newlst(operation);
	else
	{
		tmp = *stack_op;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = newlst(operation);
	}
}

int	check_next_op(int op, int next_op)
{
	if ((op == SA && next_op == SB) || (op == SB && next_op == SA))
	{
		ft_putstr("ss\n");
		return (1);
	}
	else if ((op == RA && next_op == RB) || (op == RB && next_op == RA))
	{
		ft_putstr("rr\n");
		return (1);
	}
	else if ((op == RRA && next_op == RRB) || (op == RRB && next_op == RRA))
	{
		ft_putstr("rrr\n");
		return (1);
	}
	return (0);
}

void	print_operation(int operation)
{
	if (operation == SA)
		ft_putstr("sa\n");
	else if (operation == SB)
		ft_putstr("sb\n");
	else if (operation == PA)
		ft_putstr("pa\n");
	else if (operation == PB)
		ft_putstr("pb\n");
	else if (operation == RA)
		ft_putstr("ra\n");
	else if (operation == RB)
		ft_putstr("rb\n");
	else if (operation == RRA)
		ft_putstr("rra\n");
	else if (operation == RRB)
		ft_putstr("rrb\n");
}

void	print_operations(t_stack *stack_op)
{
	int		operation;
	t_stack	*tmp;
	t_stack	*next;

	tmp = stack_op;
	while (tmp != NULL)
	{
		operation = tmp->content;
		next = tmp->next;
		if (next != NULL && check_next_op(next->content, operation))
		{
			tmp = next->next;
			continue ;
		}
		print_operation(operation);
		tmp = tmp->next;
	}
}
