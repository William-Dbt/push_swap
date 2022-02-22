/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:43:30 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 13:08:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_newlst(int content)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

void	ft_freetab(int *int_tab, char **str_tab)
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

void	ft_freestack(t_stack *stack)
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

int	ft_exit(int *int_tab, char **str_tab)
{
	if (int_tab != NULL)
		ft_freetab(int_tab, NULL);
	if (str_tab != NULL)
		ft_freetab(NULL, str_tab);
	ft_printf("Error\n");
	exit(EXIT_FAILURE);
	return (1);
}
