/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:08:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 13:08:50 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_init_stack(t_infos *infos)
{
	int		i;
	t_stack	*tmp;
	t_stack	*next;

	i = 0;
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
/*	t_stack	*tmp;
	tmp = infos.stack_a;
	while (tmp != NULL)
	{
		ft_printf("%i\n", tmp->content);
		tmp = tmp->next;
	}
	ft_freestack(infos.stack_a);
	ft_freetab(infos.tab, NULL);*/
	return (0);
}
