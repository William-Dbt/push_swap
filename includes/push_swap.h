/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:09:33 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/21 16:21:56 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_infos
{
	int	nb_args;
	int	*tab;
}	t_infos;

int		ft_count_args(char **argv);
int		*ft_fill_tab(int nb_args, char **argv);
int		ft_exit(int *int_tab, char **str_tab);

void	ft_freetab(int *int_tab, char **tab);

#endif
