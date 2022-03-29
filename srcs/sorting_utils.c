/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:00 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/29 13:47:54 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = stack;
	while (tmp->next != NULL)
	{
		next = tmp->next;
		while (next != NULL)
		{
			if (tmp->content > next->content)
				return (0);
			next = next->next;
		}
		tmp = tmp->next;
	}
	return (1);
}

int	get_nb_args(t_stack *stack)
{
	int		args;
	t_stack	*tmp;

	args = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		args++;
		tmp = tmp->next;
	}
	return (args);
}

void	get_stack_limit(t_infos *infos, t_stacklimit *stacklimit)
{
	int		min;
	int		max;
	t_stack	*tmp;

	tmp = infos->stack_a;
	stacklimit->start_value = tmp->content;
	min = tmp->content;
	max = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		if (tmp->content > max)
			max = tmp->content;
		if (tmp->next == NULL)
			stacklimit->end_value = tmp->content;
		tmp = tmp->next;
	}
	stacklimit->min_value = min;
	stacklimit->max_value = max;
	stacklimit->args_a = get_nb_args(infos->stack_a);
	stacklimit->args_b = get_nb_args(infos->stack_b);
}

int	get_max_moves(t_infos *infos, t_stacklimit *stacklimit, int nbr)
{
	int		moves_a;
	int		moves_b;

	if (nbr < stacklimit->min_value)
		moves_a = get_nbr_position(infos->stack_a, stacklimit->min_value) - 1;
	else if (nbr > stacklimit->max_value)
		moves_a = get_nbr_position(infos->stack_a, stacklimit->max_value);
	else
		moves_a = get_supposed_position(infos->stack_a, stacklimit, nbr);
	if (moves_a > stacklimit->args_a / 2 && moves_a != stacklimit->args_a)
		moves_a = stacklimit->args_a - moves_a;
	else if (moves_a == stacklimit->args_a)
		moves_a = 0;
	moves_b = get_nbr_position(infos->stack_b, nbr) - 1;
	if (get_nbr_direction(stacklimit->args_b, moves_b) == MOVE_DWN)
		moves_b = stacklimit->args_b - moves_b;
	return (moves_a + moves_b + 1);
}

int	get_nbr_to_move(t_infos *infos, t_stacklimit *stacklimit)
{
	int		nbr;
	int		moves;
	int		min_moves;
	t_stack	*tmp;

	min_moves = -1;
	tmp = infos->stack_b;
	while (tmp != NULL)
	{
		moves = get_max_moves(infos, stacklimit, tmp->content);
		if (min_moves == -1 || moves < min_moves)
		{
			nbr = tmp->content;
			min_moves = moves;
		}
		tmp = tmp->next;
	}
	return (nbr);
}
