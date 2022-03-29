/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:53:01 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/29 16:26:50 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pstack(t_stack *stacktmp)
{
	t_stack	*stack;

	stack = stacktmp;
	ft_putstr("###\n");
	ft_printf("nb_args: %i\n", get_nb_args(stack));
	while (stack != NULL)
	{
		if (stack->next != NULL)
			ft_printf("%i, ", stack->content);
		else
			ft_printf("%i\n", stack->content);
		stack = stack->next;
	}
	ft_putstr("###\n");
}

int	get_len_sequence(int ref, t_stack *first_ref)
{
	int		len;
	t_stack	*tmp;

	len = 1;
	tmp = first_ref;
	while (tmp != NULL)
	{
		if (tmp->content > ref)
		{
			ref = tmp->content;
			len++;
		}
		tmp = tmp->next;
	}
	return (len);
}

t_stack	*fill_lis_sequence(t_stack *lis, t_stack *first, t_stack *next)
{
	int		previous;
	t_stack	*sequence;
	t_stack	*seq_tmp;

	if (first == NULL || next == NULL)
		return (NULL);
	if (lis != NULL)
		freestack(lis);
	sequence = newlst(first->content);
	previous = first->content;
	seq_tmp = sequence;
	while (next != NULL)
	{
		if (previous < next->content)
		{
			seq_tmp->next = newlst(next->content);
			seq_tmp = seq_tmp->next;
			previous = next->content;
		}
		next = next->next;
	}
	return (sequence);
}

void	get_lis_sequence(t_infos *infos, int len_sequence, int previous_len)
{
	int		min_value;
	t_stack	*stack_tmp;
	t_stack	*tmp;
	t_stack	*next;
	t_stack	*lis;

	lis = NULL;
	min_value = get_min_value(infos->stack_a);
	stack_tmp = stackdup(infos->stack_a);
	while (stack_tmp->content != min_value)
		rotate_mute(&stack_tmp);
	tmp = stack_tmp;
	while (tmp != NULL)
	{
		next = tmp->next;
		while (next != NULL)
		{
			if (next->content > tmp->content)
				previous_len = get_len_sequence(tmp->content, next);
			if (previous_len > len_sequence)
			{
				len_sequence = previous_len;
				lis = fill_lis_sequence(lis, tmp, next);
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	freestack(stack_tmp);
	pstack(lis);
}
