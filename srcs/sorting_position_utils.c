/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_position_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:59:59 by wdebotte          #+#    #+#             */
/*   Updated: 2022/04/05 13:20:40 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_nbr_direction(int args, int pos)
{
	int	tmp;

	tmp = args;
	if (tmp % 2 == 0)
	{
		if (pos <= args / 2)
			return (MOVE_UP);
		else
			return (MOVE_DWN);
	}
	else
	{
// Must do (args + 1) / 2 and debug
		if (pos <= args + 1)
			return (MOVE_UP);
		else
			return (MOVE_DWN);
	}
	return (0);
}

int	get_nbr_position(t_stack *stack, int nbr)
{
	int		position;
	t_stack	*tmp;

	position = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		if (tmp->content == nbr)
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (position);
}

int	get_supposed_position(t_stack *stack, t_stacklimit *stacklim, int nbr)
{
	int		position;
	t_stack	*tmp;
	t_stack	*next;

	if ((nbr < stacklim->start_value && nbr > stacklim->end_value)
		|| (nbr > stacklim->end_value
			&& stacklim->end_value == stacklim->max_value)
		|| (nbr < stacklim->start_value
			&& stacklim->start_value == stacklim->min_value))
		return (0);
	if (nbr < stacklim->min_value)
		return (get_nbr_position(stack, stacklim->min_value) - 1);
	else if (nbr > stacklim->max_value)
		return (get_nbr_position(stack, stacklim->max_value));
	position = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		next = tmp->next;
		if (next != NULL && (nbr > tmp->content && nbr < next->content))
			return (position);
		position++;
		tmp = tmp->next;
	}
	return (0);
}
