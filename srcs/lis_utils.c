/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:04:48 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/29 15:26:39 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_mute(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL)
		return ;
	first = *stack;
	tmp = *stack;
	second = (*stack)->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = first;
	first->next = NULL;
	*stack = second;
}

int	get_min_value(t_stack *stack)
{
	int		min;
	t_stack	*tmp;

	tmp = stack;
	min = tmp->content;
	while (tmp != NULL)
	{
		if (tmp->content < min)
			min = tmp->content;
		tmp = tmp->next;
	}
	return (min);
}

t_stack	*stackdup(t_stack *stack)
{
	t_stack	*buffer;
	t_stack	*tmpbuf;
	t_stack	*tmp;

	buffer = newlst(stack->content);
	tmp = stack->next;
	while (tmp != NULL)
	{
		tmpbuf = buffer;
		while (tmpbuf->next != NULL)
			tmpbuf = tmpbuf->next;
		tmpbuf->next = newlst(tmp->content);
		tmpbuf = tmpbuf->next;
		tmp = tmp->next;
	}
	return (buffer);
}
