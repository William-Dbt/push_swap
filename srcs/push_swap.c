/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:08:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/18 17:00:40 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_check_args(int args, char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (i <= args)
	{
		n = 1;
		while (i + n <= args)
		{
			if ()
		}
	}
}

int	main(int args, char **argv)
{
	t_stack stack_a;

	if (args <= 2)
	{
		ft_printf("Usage: ./push_swap [int 0] [int 1] [...]\n");
		return (1);
	}
	ft_check_args(args, argv);
	return (0);
}
