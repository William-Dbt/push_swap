/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkargs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 13:42:45 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/22 12:48:05 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define SPLIT	1
#define TAB		2

int	ft_count_args(char **argv)
{
	int		i[2];
	int		args;
	char	**tmp;

	i[0] = 0;
	args = 0;
	while (argv[++i[0]] != NULL)
	{
		if (ft_strchr(argv[i[0]], ' '))
		{
			i[SPLIT] = 0;
			tmp = ft_split(argv[i[0]], ' ');
			while (tmp[i[SPLIT]++] != NULL)
				args++;
			ft_freetab(NULL, tmp);
		}
		else
			args++;
	}
	return (args);
}

int	ft_add_to_tab(int *int_tab, char *str, char **str_tab)
{
	int			i;

	i = 0;
	if (str[i] == '\0')
		return (ft_exit(int_tab, str_tab));
	if (ft_strlen(str) > 1 && (str[i] == '-' || str[i] == '+'))
		i++;
	while (str[i] != '\0')
	{
		if (!ft_isdigit(str[i]))
			return (ft_exit(int_tab, str_tab));
		i++;
	}
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		return (ft_exit(int_tab, str_tab));
	return (ft_atoi(str));
}

void	ft_check_tab(int *tab, int nb_args)
{
	int	i;
	int	n;

	i = -1;
	while (++i < nb_args)
	{
		n = 1;
		if (i == nb_args - 1)
			break ;
		while (i + n < nb_args)
		{
			if (tab[i + n++] == tab[i])
				ft_exit(tab, NULL);
		}
	}
}

int	*ft_fill_tab(int nb_args, char **argv)
{
	int		i[3];
	int		*tab;
	char	**tmp;

	tab = malloc(sizeof(int) * nb_args);
	if (tab == NULL)
		return (NULL);
	i[0] = 0;
	i[TAB] = 0;
	while (argv[++i[0]] != NULL)
	{
		if (ft_strchr(argv[i[0]], ' '))
		{
			i[SPLIT] = 0;
			tmp = ft_split(argv[i[0]], ' ');
			while (tmp[i[SPLIT]] != NULL)
				tab[i[TAB]++] = ft_add_to_tab(tab, tmp[i[SPLIT]++], tmp);
			ft_freetab(NULL, tmp);
		}
		else
			tab[i[TAB]++] = ft_add_to_tab(tab, argv[i[0]], NULL);
	}
	ft_check_tab(tab, nb_args);
	return (tab);
}
