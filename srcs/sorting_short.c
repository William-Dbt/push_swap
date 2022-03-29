/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:54:04 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/29 12:28:39 by wdebotte         ###   ########.fr       */
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
	if (i[0] < i[1] && i[1] > i[2])
	{
		if (i[0] < i[2])
		{
			swap(stack, stack_op, STACK_A);
			rotate(stack, stack_op, STACK_A);
		}
		else if (i[0] > i[2])
			rrotate(stack, stack_op, STACK_A);
	}
	else if (i[0] > i[1] && i[0] > i[2])
	{
		rotate(stack, stack_op, STACK_A);
		if (i[1] > i[2])
			swap(stack, stack_op, STACK_A);
	}
	else if (i[0] > i[1] && i[0] < i[2] && i[1] < i[2])
		swap(stack, stack_op, STACK_A);
}

int	get_min_pos(t_stack *stack)
{
	int		position;
	int		nbr;
	int		nbr_position;
	t_stack	*tmp;

	nbr = stack->content;
	nbr_position = 1;
	position = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->content < nbr)
		{
			nbr = tmp->content;
			nbr_position = position;
		}
		position++;
		tmp = tmp->next;
	}
	return (nbr_position);
}

void	sort_selection(t_infos *infos)
{
	int	position;
	int	nb_args;

	while (!is_sorted(infos->stack_a))
	{
		position = get_min_pos(infos->stack_a);
		nb_args = get_nb_args(infos->stack_a);
		if (nb_args == 3)
			sort_three(&infos->stack_a, &infos->stack_op);
		else
		{
			if (position == 1)
			{
				push(&infos->stack_a, &infos->stack_b, &infos->stack_op,
					STACK_B);
				continue ;
			}
			if (position <= nb_args / 2)
				rotate(&infos->stack_a, &infos->stack_op, STACK_A);
			else
				rrotate(&infos->stack_a, &infos->stack_op, STACK_A);
		}
	}
	while (infos->stack_b != NULL)
		push(&infos->stack_b, &infos->stack_a, &infos-> stack_op, STACK_A);
}
