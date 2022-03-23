/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/23 20:42:37 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_lis(t_infos *inf)
{
	int				pos;
	int				moves;
	int				nbr;
	t_stacklimit	stacklimit;

	//int	toto = 8;
	get_lis_sequence(inf, 0, 0);
	while (/*toto--*/inf->stack_b != NULL)
	{
		get_stack_limit(inf, &stacklimit, 0);
		nbr = get_nbr_to_move(inf, &stacklimit);
		moves = get_max_moves(inf, &stacklimit, nbr);
		while (moves > 0)
		{
			if (moves == 1)
			{
				push(&inf->stack_b, &inf->stack_a, &inf->stack_op, STACK_A);
				break ;
			}
			pos = get_nbr_position(inf->stack_b, nbr);
			if (pos != 1)
			{
				if (pos <= stacklimit.args_b / 2)
					rotate(&inf->stack_b, &inf->stack_op, STACK_B);
				else
					rrotate(&inf->stack_b, &inf->stack_op, STACK_B);
				moves--;
			}
			pos = get_supposed_position(inf->stack_a, &stacklimit, nbr);
			if (pos != 0)
			{
				if (pos <= stacklimit.args_a / 2)
					rotate(&inf->stack_a, &inf->stack_op, STACK_A);
				else
					rrotate(&inf->stack_a, &inf->stack_op, STACK_A);
				moves--;
			}
		}
	}
	while (!is_sorted(inf->stack_a))
		rotate(&inf->stack_a, &inf->stack_op, STACK_A);
}
