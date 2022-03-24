/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:08:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/24 14:27:08 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*tmp_a;
	t_stack	*tmp_b;

	tmp_a = stack_a;
	tmp_b = stack_b;
	while (tmp_a != NULL || tmp_b != NULL)
	{
		if (tmp_b != NULL && tmp_a != NULL)
			ft_printf("%i\t\t| %i\n", tmp_a->content, tmp_b->content);
		else if (tmp_b == NULL)
			ft_printf("%i\t\t| (NULL)\n", tmp_a->content);
		else
			ft_printf("(NULL)\t\t| %i\n", tmp_b->content);
		if (tmp_a != NULL)
			tmp_a = tmp_a->next;
		if (tmp_b != NULL)
			tmp_b = tmp_b->next;
	}
}

void	guess_sorting(t_infos *infos)
{
	if (infos->nb_args == 2)
		sort_two(&infos->stack_a, &infos->stack_op);
	else if (infos->nb_args == 3)
		sort_three(&infos->stack_a, &infos->stack_op);
	else
		sort_lis(infos);
}

void	init_stack(t_infos *infos)
{
	int		i;
	t_stack	*tmp;
	t_stack	*next;

	i = 0;
	infos->stack_b = NULL;
	infos->stack_op = NULL;
	infos->stack_a = newlst(infos->tab[i++]);
	tmp = infos->stack_a;
	while (i < infos->nb_args)
	{
		next = newlst(infos->tab[i++]);
		tmp->next = next;
		tmp = next;
	}
	freetab(infos->tab, NULL);
}

int	main(int args, char **argv)
{
	t_infos	infos;

	if (args <= 1)
		return (0);
	infos.nb_args = count_args(argv);
	infos.tab = fill_tab(infos.nb_args, argv);
	if (infos.tab == NULL)
		return (0);
	init_stack(&infos);
	if (infos.nb_args == 1)
		return (0);
	else if (infos.nb_args >= 2)
		guess_sorting(&infos);
//	print_stack(infos.stack_a, infos.stack_b);
	print_operations(infos.stack_op);
	freestack(infos.stack_a);
	freestack(infos.stack_op);
	return (0);
}
