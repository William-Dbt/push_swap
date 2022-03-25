/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/25 16:31:25 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	move_stacks(t_infos *inf, t_stacklimit *stacklimit, int moves, int nbr)
{
	int	pos;

	if (moves == 1 && inf->stack_b->content == nbr)
	{
		push(&inf->stack_b, &inf->stack_a, &inf->stack_op, STACK_A);
		return (0);
	}
	pos = get_nbr_position(inf->stack_b, nbr);
	if (pos != 1 && moves--)
	{
		if (get_nbr_direction(stacklimit->args_b, pos) == MOVE_UP)
			rotate(&inf->stack_b, &inf->stack_op, STACK_B);
		else
			rrotate(&inf->stack_b, &inf->stack_op, STACK_B);
	}
	pos = get_supposed_position(inf->stack_a, stacklimit, nbr);
	if (pos != 0 && moves--)
	{
		if (pos <= stacklimit->args_a / 2)
			rotate(&inf->stack_a, &inf->stack_op, STACK_A);
		else
			rrotate(&inf->stack_a, &inf->stack_op, STACK_A);
	}
	return (moves);
}

void	sort_lis(t_infos *inf)
{
	int				pos;
	int				moves;
	int				nbr;
	t_stacklimit	stacklimit;

	get_lis_sequence(inf, 0, 0);
	while (inf->stack_b != NULL)
	{
		get_stack_limit(inf, &stacklimit);
		nbr = get_nbr_to_move(inf, &stacklimit);
		moves = get_max_moves(inf, &stacklimit, nbr);
		while (moves > 0)
			moves = move_stacks(inf, &stacklimit, moves, nbr);
	}
	get_stack_limit(inf, &stacklimit);
	pos = get_nbr_position(inf->stack_a, stacklimit.min_value);
	while (pos-- > 1)
	{
		if (pos > stacklimit.args_a)
			rrotate(&inf->stack_a, &inf->stack_op, STACK_A);
		else
			rotate(&inf->stack_a, &inf->stack_op, STACK_A);
	}
}
