/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:08:52 by wdebotte          #+#    #+#             */
/*   Updated: 2022/02/08 14:14:59 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_valid_arg(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%')
		return (1);
	return (0);
}

static int	ft_print_var(va_list args, char c)
{
	if (c == 'c')
		ft_putchar(va_arg(args, int));
	else if (c == 's')
		return (ft_printf_putstr(va_arg(args, char *)));
	else if (c == 'p')
		return (ft_printf_putstr("0x") + ft_printf_putnbr_hexa_u
			(va_arg(args, unsigned long long int), 0));
	else if (c == 'd')
		return (ft_printf_putnbr(va_arg(args, int), 0));
	else if (c == 'i')
		return (ft_printf_putnbr(va_arg(args, int), 0));
	else if (c == 'u')
		return (ft_printf_putnbr_u(va_arg(args, unsigned int), 0));
	else if (c == 'x')
		return (ft_printf_putnbr_hexa(va_arg(args, int), 0, 0));
	else if (c == 'X')
		return (ft_printf_putnbr_hexa(va_arg(args, int), 1, 0));
	else if (c == '%')
		ft_putchar('%');
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int		char_count;
	va_list	args;

	char_count = 0;
	va_start(args, str);
	while (*str != '\0')
	{
		if (*str == '%' && is_valid_arg(*(str + 1)))
		{
			str++;
			char_count += ft_print_var(args, *str);
		}
		else
		{
			ft_putchar(*str);
			char_count++;
		}
		str++;
	}
	va_end(args);
	return (char_count);
}
