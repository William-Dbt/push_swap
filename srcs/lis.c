/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 13:53:01 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/30 16:45:02 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

typedef struct s_lis
{	
	int		min_value;
	t_stack	*stack_tmp;
	t_stack	*tmp;
	t_stack	*next;
	t_stack	*lis;
}	t_lis;

void	pre_lis_sort(t_infos *inf, t_stack *lis)
{
	int		position;
	t_stack	*tmp;

	tmp = inf->stack_a;
	while (tmp != NULL)
	{
		if (is_nbr_in_lis(lis, tmp->content) == 1)
		{
			tmp = tmp->next;
			continue ;
		}
		position = get_nbr_position(inf->stack_a, tmp->content);
		while (inf->stack_a->content != tmp->content)
		{
			if (position <= get_nb_args(inf->stack_a) / 2)
				rotate(&inf->stack_a, &inf->stack_op, STACK_A);
			else
				rrotate(&inf->stack_a, &inf->stack_op, STACK_A);
		}
		push(&inf->stack_a, &inf->stack_b, &inf->stack_op, STACK_B);
		tmp = inf->stack_a;
	}
	freestack(lis);
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
			sequence->next = newlst(next->content);
			sequence = sequence->next;
			previous = next->content;
		}
		next = next->next;
	}
	return (seq_tmp);
}

void	init_lis_struct(t_lis *lis, t_infos *infos)
{
	lis->lis = NULL;
	lis->min_value = get_min_value(infos->stack_a);
	lis->stack_tmp = stackdup(infos->stack_a);
}

void	get_lis_sequence(t_infos *infos, int len_sequence, int previous_len)
{
	t_lis	lis;

	init_lis_struct(&lis, infos);
	while (lis.stack_tmp->content != lis.min_value)
		rotate_mute(&lis.stack_tmp);
	lis.tmp = lis.stack_tmp;
	while (lis.tmp != NULL)
	{
		lis.next = lis.tmp->next;
		while (lis.next != NULL)
		{
			if (lis.next->content > lis.tmp->content)
				previous_len = get_len_sequence(lis.tmp->content, lis.next);
			if (previous_len > len_sequence)
			{
				len_sequence = previous_len;
				lis.lis = fill_lis_sequence(lis.lis, lis.tmp, lis.next);
			}
			lis.next = lis.next->next;
		}
		lis.tmp = lis.tmp->next;
	}
	freestack(lis.stack_tmp);
	pre_lis_sort(infos, lis.lis);
}
