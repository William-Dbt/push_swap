/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:00 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/21 17:39:12 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	guess_sorting(t_infos *infos)
{
	if (infos->nb_args == 2)
		sort_two(&infos->stack_a, &infos->stack_op);
	else if (infos->nb_args == 3)
		sort_three(&infos->stack_a, &infos->stack_op);
//	else if (infos->nb_args >= 4 && infos->nb_args <= 45)
//		sort_selection(infos);
	else
		sort_lis(infos);
}

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = *stack;
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

int	get_min_pos(t_stack **stack)
{
	int		position;
	int		nbr;
	int		nbr_position;
	t_stack	*tmp;

	nbr = (*stack)->content;
	nbr_position = 1;
	position = 1;
	tmp = *stack;
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

int	get_nb_args(t_stack **stack)
{
	int		args;
	t_stack	*tmp;

	args = 0;
	tmp = *stack;
	while (tmp != NULL)
	{
		args++;
		tmp = tmp->next;
	}
	return (args);
}
