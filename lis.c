/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:56 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 16:17:28 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_lis_sort(t_stack *lis, t_infos *infos)
{
	int		lis_args;
	t_stack	*lis_tmp;

	lis_args = get_nb_args(lis);
	lis_tmp = lis;
	while (get_nb_args(infos->stack_a) != lis_args)
	{
		if (lis_tmp == NULL || infos->stack_a->content != lis_tmp->content)
			push(&infos->stack_a, &infos->stack_b, &infos->stack_op, STACK_B);
		else
		{
			rotate(&infos->stack_a, &infos->stack_op, STACK_A);
			lis_tmp = lis_tmp->next;
		}
	}
	freestack(lis);
}

int	get_len_sequence(int ref, t_stack *first_ptr)
{
	int		len;
	t_stack	*tmp;

	len = 1;
	tmp = first_ptr;
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
	t_stack			*tmp;
	t_stack			*next;
	t_stack			*lis;

	lis = NULL;
	tmp = infos->stack_a;
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
	if (lis != NULL)
		pre_lis_sort(lis, infos);
}
