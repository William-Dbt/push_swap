/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_position_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:59:59 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/24 14:04:49 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
