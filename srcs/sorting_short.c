/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_short.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 17:54:04 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/01 13:59:58 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_get_values(int *tab, int i, t_stack *stack)
{
	int	n;

	n = 0;
	while (n < i)
	{
		tab[n++] = stack->content;
		stack = stack->next;
	}
}

void	ft_sort_two(t_stack **stack)
{
	int	i[2];

	ft_get_values(i, 2, *stack);
	if (i[0] > i[1])
		ft_swap(stack);
}

void	ft_sort_three(t_stack **stack)
{
	int	i[3];

	ft_get_values(i, 3, *stack);
	if (i[0] > i[2])
		ft_rotate(stack);
	ft_get_values(i, 3, *stack);
	if (i[0] > i[1])
		ft_swap(stack);
	ft_get_values(i, 3, *stack);
	if (i[1] > i[2])
	{
		ft_rotate(stack);
		ft_swap(stack);
		ft_rrotate(stack);
	}
}
