/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:08:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/21 17:14:59 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int args, char **argv)
{
	t_infos	infos;
	int		i;

	i = 0;
	if (args < 2)
		return (ft_printf("\n"));
	infos.nb_args = ft_count_args(argv);
	infos.tab = ft_fill_tab(infos.nb_args, argv);
	while (infos.nb_args-- > 0)
		ft_printf("%i\n", infos.tab[i++]);
	free(infos.tab);
	return (0);
}
