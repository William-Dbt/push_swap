/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 12:40:51 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 16:21:01 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

struct s_stackinfo
{
	int	min;
	int	max;
};

void	get_stack_info(t_stack *stack, struct s_stackinfo *stackinfo)
{
	int		nbr;
	t_stack	*tmp;

	tmp = stack;
	nbr = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < nbr)
			nbr = tmp->content;
		tmp = tmp->next;
	}
	stackinfo->min = nbr;
	tmp = stack;
	nbr = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content > nbr)
			nbr = tmp->content;
		tmp = tmp->next;
	}
	stackinfo->max = nbr;
}

void	sort_lis(t_infos *infos)
{
	struct s_stackinfo	stackinfo;

	get_lis_sequence(infos, 0, 0);
	get_stack_info(infos->stack_a, &stackinfo);
	while (!is_sorted(infos->stack_a) || infos->stack_b != NULL)
	{
		
	}
}
