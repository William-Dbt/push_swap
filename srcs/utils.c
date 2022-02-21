/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 14:43:30 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/21 16:02:34 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
