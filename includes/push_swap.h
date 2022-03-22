/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <wdebotte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 14:09:33 by wdebotte          #+#    #+#             */
/*   Updated: 2022/03/22 16:16:31 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>

# define SA			0
# define SB			1
# define PA			2
# define PB			3
# define RA			4
# define RB			5
# define RRA		6
# define RRB		7
# define STACK_A	10
# define STACK_B	11

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
	t_stack	*stack_op;
}	t_infos;

int		count_args(char **argv);
int		*fill_tab(int nb_args, char **argv);
int		exit_program(int *int_tab, char **str_tab);

void	freetab(int *int_tab, char **tab);
void	freestack(t_stack *stack);

// OPERATIONS
void	swap(t_stack **stack, t_stack **stack_op, int stack_name);
void	push(t_stack **stackfrom, t_stack **stackto, t_stack **stack_op,
			int stackto_name);
void	rotate(t_stack **stack, t_stack **stack_op, int stack_name);
void	rrotate(t_stack **stack, t_stack **stack_op, int stack_name);
void	print_operations(t_stack *stack_op);
void	print_operation(int operation);
void	save_operation(t_stack **stack_op, int operation);
// ----------

// SORTING
int		is_sorted(t_stack *stack);
int		get_nb_args(t_stack *stack);

void	guess_sorting(t_infos *infos);
void	sort_two(t_stack **stack, t_stack **stack_op);
void	sort_three(t_stack **stack, t_stack **stack_op);
void	sort_lis(t_infos *infos);
void	get_lis_sequence(t_infos *infos, int len_sequence, int previous_len);
// ----------

t_stack	*newlst(int content);

#endif
