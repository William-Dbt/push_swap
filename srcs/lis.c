/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 14:06:56 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/21 16:11:34 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

t_stack	*fill_lis_sequence(t_stack *first_ref)
{
	int		previous;
	t_stack	*sequence;
	t_stack	*seq_tmp;

	if (first_ref == NULL)
		return (NULL);
	previous = first_ref->content;
	sequence = newlst(previous);
	seq_tmp = sequence;
	first_ref = first_ref->next;
	while (first_ref != NULL)
	{
		if (first_ref->content > previous)
		{
			previous = first_ref->content;
			seq_tmp->next = newlst(previous);
			seq_tmp = seq_tmp->next;
		}
		first_ref = first_ref->next;
	}
	return (sequence);
}

t_stack	*get_lis_sequence(t_stack **stack, int len_sequence, int previous_len)
{
	t_stack			*tmp;
	t_stack			*next;
	t_stack			*first_ref;

	first_ref = NULL;
	tmp = *stack;
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
				first_ref = tmp;
			}
			next = next->next;
		}
		tmp = tmp->next;
	}
	return (fill_lis_sequence(first_ref));
}
