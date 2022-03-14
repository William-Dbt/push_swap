/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:54:04 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/14 16:34:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_values(int *tab, int i, t_stack *stack)
{
	int	n;

	n = 0;
	while (n < i)
	{
		tab[n++] = stack->content;
		stack = stack->next;
	}
}

void	sort_two(t_stack **stack, t_stack **stack_op)
{
	int	i[2];

	get_values(i, 2, *stack);
	if (i[0] > i[1])
		swap(stack, stack_op, STACK_A);
}

void	sort_three(t_stack **stack, t_stack **stack_op)
{
	int	i[3];

	get_values(i, 3, *stack);
	if (i[0] > i[2])
		rotate(stack, stack_op, STACK_A);
	get_values(i, 3, *stack);
	if (i[0] > i[1])
		swap(stack, stack_op, STACK_A);
	get_values(i, 3, *stack);
	if (i[1] > i[2])
	{
		rotate(stack, stack_op, STACK_A);
		swap(stack, stack_op, STACK_A);
		rrotate(stack, stack_op, STACK_A);
	}
}
