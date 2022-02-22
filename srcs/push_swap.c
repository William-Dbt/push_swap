/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:08:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 15:52:05 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack *tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_b != NULL)
			ft_printf("%i\t\t| %i\n", tmp_a->content, tmp_b->content);
		else
			ft_printf("%i\t\t| (NULL)\n", tmp_a->content);
		if (tmp_a != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b != NULL)
			tmp_b = tmp_b->next;
	}
}

void	ft_init_stack(t_infos *infos)
{
	int		i;
	t_stack	*tmp;
	t_stack	*next;

	i = 0;
	infos->stack_b = NULL;
	infos->stack_a = ft_newlst(infos->tab[i++]);
	tmp = infos->stack_a;
	while (i < infos->nb_args)
	{
		next = ft_newlst(infos->tab[i++]);
		tmp->next = next;
		tmp = next;
	}
}

int	main(int args, char **argv)
{
	t_infos	infos;

	if (args < 2)
		return (ft_printf("\n"));
	infos.nb_args = ft_count_args(argv);
	infos.tab = ft_fill_tab(infos.nb_args, argv);
	ft_init_stack(&infos);
	
	//ft_swap(infos.stack_a);
	ft_push(infos.stack_a, infos.stack_b);

	ft_print_stack(infos.stack_a, infos.stack_b);
	ft_freestack(infos.stack_a);
	ft_freestack(infos.stack_b);
	ft_freetab(infos.tab, NULL);
	return (0);
}
