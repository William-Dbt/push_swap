/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:42:45 by wdebotte          #+#    #+#             */
/*   Updated: 2022/04/04 10:48:53 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define INDEX	0
#define SPLIT	1
#define TAB		2

int	count_args(char **argv)
{
	int		i[2];
	int		args;
	char	**tmp;

	i[INDEX] = 0;
	args = 0;
	while (argv[++i[INDEX]] != NULL)
	{
		if (ft_strchr(argv[i[INDEX]], ' '))
		{
			i[SPLIT] = 0;
			tmp = ft_split(argv[i[INDEX]], ' ');
			while (tmp[i[SPLIT]++] != NULL)
				args++;
			freetab(NULL, tmp);
		}
		else
			args++;
	}
	return (args);
}

int	add_to_tab(int *int_tab, char *str, char **str_tab)
{
	int	i;

	if (str[0] == '\0')
		return (exit_program(int_tab, str_tab));
	i = 0;
	if (ft_strlen(str) > 1 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (exit_program(int_tab, str_tab));
		i++;
	}
	if (ft_atoli(str) > 2147483647 || ft_atoli(str) < -2147483648)
		return (exit_program(int_tab, str_tab));
	return (ft_atoi(str));
}

int	*check_tab(int *tab, int nb_args)
{
	int	i;
	int	n;
	int	is_sorted;

	is_sorted = 1;
	i = -1;
	while (++i < nb_args)
	{
		n = 1;
		if (i == nb_args - 1)
			break ;
		while (i + n < nb_args)
		{
			if (tab[i + n] == tab[i])
				exit_program(tab, NULL);
			if (tab[i + n++] < tab[i])
				is_sorted = 0;
		}
	}
	if (is_sorted)
	{
		free(tab);
		return (NULL);
	}
	return (tab);
}

int	*fill_tab(int nb_args, char **argv)
{
	int		i[3];
	int		*tab;
	char	**tmp;

	tab = malloc(sizeof(int) * nb_args);
	if (tab == NULL)
		return (NULL);
	i[INDEX] = 0;
	i[TAB] = 0;
	while (argv[++i[INDEX]] != NULL)
	{
		if (ft_strchr(argv[i[INDEX]], ' '))
		{
			i[SPLIT] = 0;
			tmp = ft_split(argv[i[INDEX]], ' ');
			while (tmp[i[SPLIT]] != NULL)
				tab[i[TAB]++] = add_to_tab(tab, tmp[i[SPLIT]++], tmp);
			freetab(NULL, tmp);
		}
		else
			tab[i[TAB]++] = add_to_tab(tab, argv[i[INDEX]], NULL);
	}
	tab = check_tab(tab, nb_args);
	return (tab);
}
