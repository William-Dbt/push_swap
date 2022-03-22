/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 15:30:00 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 16:16:23 by wdebotte         ###   ########.fr       */
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

/*int	get_min_pos(t_stack **stack)
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
}*/
