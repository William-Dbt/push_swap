/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/17 13:51:29 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_selection(t_stack **stack_a, t_stack **stack_b, t_stack **stack_op)
{
	int	position;
	int	nb_args;

	while (!is_sorted(stack_a))
	{
		position = get_min_pos(stack_a);
		nb_args = get_nb_args(stack_a);
		if (nb_args == 3)
			sort_three(stack_a, stack_op);
		else
		{
			if (position == 1)
			{
				push(stack_a, stack_b, stack_op, STACK_B);
				continue ;
			}
			if (position < nb_args / 2)
				rotate(stack_a, stack_op, STACK_A);
			else
				rrotate(stack_a, stack_op, STACK_A);
		}
	}
	while (*stack_b != NULL)
		push(stack_b, stack_a, stack_op, STACK_A);
}
