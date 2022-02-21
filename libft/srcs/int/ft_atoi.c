/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 14:41:53 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/21 16:59:52 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_whitespace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

long long int	ft_atoi(const char *str)
{
	int				is_negativ;
	long long int	number;

	number = 0;
	is_negativ = 1;
	while (*str && ft_is_whitespace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			is_negativ = -is_negativ;
	while (*str && (*str >= '0' && *str <= '9'))
		number = number * 10 + *(str++) - 48;
	return (number * is_negativ);
}
