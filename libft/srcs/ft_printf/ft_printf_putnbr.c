/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 10:19:15 by wdebotte          #+#    #+#             */
/*   Updated: 2022/01/11 13:17:16 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_putnbr(int nb, int count)
{
	long int	nbr;

	nbr = nb;
	if (nb < 0)
	{
		count++;
		ft_putchar('-');
		nbr = -nbr;
	}
	if (nbr <= 9)
		ft_putchar(nbr + '0');
	else
	{
		count = ft_printf_putnbr(nbr / 10, count);
		ft_putchar((nbr % 10) + '0');
	}
	return (++count);
}

int	ft_printf_putnbr_u(unsigned int nb, int count)
{
	if (nb <= 9)
		ft_putchar(nb + '0');
	else
	{
		count = ft_printf_putnbr(nb / 10, count);
		ft_putchar((nb % 10) + '0');
	}
	return (++count);
}

int	ft_printf_putnbr_hexa(int nb, int caps, int count)
{
	unsigned int	nbr;

	nbr = nb;
	if (nbr <= 15)
	{
		if (caps && (nbr >= 10 && nbr <= 15))
			ft_putchar(HEXA[nbr] - 32);
		else
			ft_putchar(HEXA[nbr]);
	}
	else
	{
		count = ft_printf_putnbr_hexa(nbr / 16, caps, count);
		nbr %= 16;
		if (caps && (nbr >= 10 && nbr <= 15))
			ft_putchar(HEXA[nbr] - 32);
		else
			ft_putchar(HEXA[nbr]);
	}
	return (++count);
}

int	ft_printf_putnbr_hexa_u(unsigned long long int nb, int count)
{
	if (nb <= 15)
		ft_putchar(HEXA[nb]);
	else
	{
		count = ft_printf_putnbr_hexa_u(nb / 16, count);
		ft_putchar(HEXA[nb % 16]);
	}
	return (++count);
}
