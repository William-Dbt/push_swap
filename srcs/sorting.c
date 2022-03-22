/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 21:45:55 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_stack_limit(t_stack *stack, t_stacklimit *stacklimit, int nbr)
{
	t_stack	*tmp;

	tmp = stack;
	stacklimit->start_value = tmp->content;
	nbr = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < nbr)
			nbr = tmp->content;
		if (tmp->next == NULL)
			stacklimit->end_value = tmp->content;
		tmp = tmp->next;
	}
	stacklimit->min_value = nbr;
	tmp = stack;
	nbr = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > nbr)
			nbr = tmp->content;
		tmp = tmp->next;
	}
	stacklimit->max_value = nbr;
	stacklimit->args = get_nb_args(stack);
}

int	get_max_moves(t_infos *infos, t_stacklimit *stacklimit, int nbr)
{
	int		moves_a;
	int		moves_b;

	if (nbr < stacklimit->min_value)
		moves_a = get_nbr_position(infos->stack_a, stacklimit->min_value);
	else if (nbr > stacklimit->max_value)
		moves_a = get_nbr_position(infos->stack_a, stacklimit->max_value);
	else
		moves_a = get_supposed_position(infos->stack_a, stacklimit, nbr);
	moves_b = get_nbr_position(infos->stack_b, nbr);
	return (moves_a + moves_b);
}

void	sort_lis(t_infos *infos)
{
	int				position;
	t_stacklimit	stacklimit;

	get_lis_sequence(infos, 0, 0);
	while (infos->stack_b != NULL)
	{
		get_stack_limit(infos->stack_a, &stacklimit, 0);
		position = get_supposed_position(infos->stack_a, &stacklimit,
			infos->stack_b->content);
		while (position-- > 0)
			rotate(&infos->stack_a, &infos->stack_op, STACK_A);
		push(&infos->stack_b, &infos->stack_a, &infos->stack_op, STACK_A);
		continue ;
	}
	int toto = 17;
	while (toto-- > 0)
		rotate(&infos->stack_a, &infos->stack_op, STACK_A);
	if (is_sorted(infos->stack_a))
		ft_putstr("Bloup bloup\n\n");
}
