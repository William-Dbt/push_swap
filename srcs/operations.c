/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:34:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/24 11:15:00 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	ft_push(t_stack **stackfrom, t_stack **stackto)
{
	t_stack	*tmp_from;
	t_stack	*tmp_to;

	if (*stackfrom == NULL)
		return ;
	tmp_from = *stackfrom;
	tmp_to = ft_newlst(tmp_from->content);
	*stackfrom = tmp_from->next;
	free(tmp_from);
	tmp_to->next = *stackto;
	*stackto = tmp_to;
}

void	ft_rotate(t_stack **stack)
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

void	ft_rrotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;

	if (*stack == NULL)
		return ;
	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *stack;
	last = *stack;
	while (last->next != tmp)
		last = last->next;
	last->next = NULL;
	*stack = tmp;
}
