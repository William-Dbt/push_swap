/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:34:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/23 16:47:11 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_stack *stack)
{
	int	tmp;
	t_stack	*second;

	if (stack == NULL || stack->next == NULL)
		return ;
	tmp = stack->content;
	second = stack->next;
	stack->content = second->content;
	second->content = tmp;
}

void	ft_push(t_stack **stackfrom, t_stack **stackto)
{
	t_stack	*tmp_from;
	t_stack	*tmp_to;

	if (stackfrom == NULL)
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
	if (stack == NULL)
		return ;
}
