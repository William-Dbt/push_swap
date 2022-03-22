/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:00 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 21:42:38 by wdebotte         ###   ########.fr       */
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

int	get_nbr_position(t_stack *stack, int nbr)
{
	int		position;
	t_stack	*tmp;

	position = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		position++;
		if (tmp->content == nbr)
			return (position);
		tmp = tmp->next;
	}
	return (position);
}

int	get_supposed_position(t_stack *stack, t_stacklimit *stacklim, int nbr)
{
	int	position;
	t_stack	*tmp;
	t_stack	*next;

	position = 0;
	if (nbr < stacklim->start_value && nbr > stacklim->end_value)
		return (position);
	if (nbr < stacklim->min_value)
		return (get_nbr_position(stack, stacklim->min_value));
	else if (nbr > stacklim->max_value)
		return (get_nbr_position(stack, stacklim->max_value));
	tmp = stack;
	while (tmp->next != NULL)
	{
		position++;
		next = tmp->next;
		if (nbr > tmp->content && nbr < next->content)
			return (position);
		tmp = tmp->next;
	}
	return (position);
}
