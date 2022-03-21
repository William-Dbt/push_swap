/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/21 17:43:39 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_lis_sort(t_stack *lis, t_infos *infos)
{
	int		lis_args;
	t_stack	*lis_tmp;

	lis_args = get_nb_args(&lis);
	lis_tmp = lis;
	while (get_nb_args(&infos->stack_a) != lis_args)
	{
		if (lis_tmp == NULL || infos->stack_a->content != lis_tmp->content)
			push(&infos->stack_a, &infos->stack_b, &infos->stack_op, STACK_B);
		else
		{
			rotate(&infos->stack_a, &infos->stack_op, STACK_A);
			lis_tmp = lis_tmp->next;
		}
	}
	freestack(lis);
}

void	sort_lis(t_infos *infos)
{
	t_stack	*lis;

	lis = get_lis_sequence(&infos->stack_a, 0, 0);
	if (lis != NULL)
		pre_lis_sort(lis, infos);
}

void	sort_selection(t_infos *infos)
{
	int	position;
	int	nb_args;
	
	while (!is_sorted(&infos->stack_a))
	{
		position = get_min_pos(&infos->stack_a);
		nb_args = get_nb_args(&infos->stack_a);
		if (nb_args == 3)
			sort_three(&infos->stack_a, &infos->stack_op);
		else
		{
			if (position == 1)
			{
				push(&infos->stack_a, &infos->stack_b, &infos->stack_op, STACK_B);
				continue ;
			}
			if (position < nb_args / 2)
				rotate(&infos->stack_a, &infos->stack_op, STACK_A);
			else
				rrotate(&infos->stack_a, &infos->stack_op, STACK_A);
		}
	}
	while (infos->stack_b != NULL)
		push(&infos->stack_b, &infos->stack_a, &infos->stack_op, STACK_A);
}
