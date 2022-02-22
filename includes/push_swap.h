/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:09:33 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 13:09:20 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int		content;
	void	*next;
}	t_stack;

typedef struct s_infos
{
	int		nb_args;
	int		*tab;
	t_stack	*stack_a;
	t_stack	*stack_b;
}	t_infos;

int		ft_count_args(char **argv);
int		*ft_fill_tab(int nb_args, char **argv);
int		ft_exit(int *int_tab, char **str_tab);

void	ft_freetab(int *int_tab, char **tab);
void	ft_freestack(t_stack *stack);

t_stack	*ft_newlst(int content);

#endif
