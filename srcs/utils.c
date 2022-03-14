/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:43:30 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/14 15:34:37 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*newlst(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	print_operation(int operation)
{
	if (operation == SA)
		ft_printf("sa\n");
	else if (operation == SB)
		ft_printf("sb\n");
	else if (operation == PA)
		ft_printf("pa\n");
	else if (operation == PB)
		ft_printf("pb\n");
	else if (operation == RA)
		ft_printf("ra\n");
	else if (operation == RB)
		ft_printf("rb\n");
	else if (operation == RRA)
		ft_printf("rra\n");
	else if (operation == RRB)
		ft_printf("rrb\n");
}

void	freetab(int *int_tab, char **str_tab)
{
	int	i;

	if (int_tab != NULL)
		free(int_tab);
	if (str_tab != NULL)
	{
		i = 0;
		while (str_tab[i])
			free(str_tab[i++]);
		free(str_tab);
	}
}

void	freestack(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
}

int	exit_program(int *int_tab, char **str_tab)
{
	if (int_tab != NULL)
		freetab(int_tab, NULL);
	if (str_tab != NULL)
		freetab(NULL, str_tab);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
	return (1);
}
