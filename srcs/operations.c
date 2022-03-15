/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:34:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/15 16:28:22 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, t_stack **stack_op, int stack_name)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	if (stack_name == STACK_A)
		save_operation(stack_op, SA);
	else if (stack_name == STACK_B)
		save_operation(stack_op, SB);
}

void	push(t_stack **stackfrom, t_stack **stackto, t_stack **stack_op,
			int stackto_name)
{
	t_stack	*tmp_from;
	t_stack	*tmp_to;

	if (*stackfrom == NULL)
		return ;
	tmp_from = *stackfrom;
	tmp_to = newlst(tmp_from->content);
	*stackfrom = tmp_from->next;
	free(tmp_from);
	tmp_to->next = *stackto;
	*stackto = tmp_to;
	if (stackto_name == STACK_A)
		save_operation(stack_op, PA);
	else
		save_operation(stack_op, PB);
}

void	rotate(t_stack **stack, t_stack **stack_op, int stack_name)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	tmp = *stack;
	second = (*stack)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	*stack = second;
	if (stack_name == STACK_A)
		save_operation(stack_op, RA);
	else
		save_operation(stack_op, RB);
}

void	rrotate(t_stack **stack, t_stack **stack_op, int stack_name)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	last = *stack;
	while (last->next != tmp)
		last = last->next;
	last->next = NULL;
	*stack = tmp;
	if (stack_name == STACK_A)
		save_operation(stack_op, RRA);
	else
		save_operation(stack_op, RRB);
}
