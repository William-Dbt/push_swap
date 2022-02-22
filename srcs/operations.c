/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 13:34:03 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 15:57:34 by wdebotte         ###   ########.fr       */
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

void	ft_push(t_stack *stackfrom, t_stack *stackto)
{
	if (stackfrom == NULL)
		return ;
	stackto = ft_newlst(stackfrom->content);
}
