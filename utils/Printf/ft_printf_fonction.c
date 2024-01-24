/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fonction.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 03:35:31 by msan              #+#    #+#             */
/*   Updated: 2023/11/20 19:05:56 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (write(1, "(null)", 6));
	if (!str)
		return (0);
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int	ft_count(int nb)
{
	int	i;

	i = 1;
	if (nb < 0)
	{
		nb = nb * -1;
		i++;
	}
	while (nb > 9)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

int	ft_putnbr(int nb)
{
	long int	n;

	n = nb;
	if (n == -2147483648)
		return (ft_putstr("-2147483648"));
	if (nb >= 0 && nb <= 9)
		ft_putchar(nb + '0');
	else if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(nb * -1);
	}
	return (ft_count(nb));
}

/*int	ft_print_digit(long number, int base)
{
	int		count;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (number < 0)
	{
		write(1, "-", 1);
		return (ft_print_digit(-number, base) + 1);
	}
	else if (number < base)
		return (ft_putchar(symbols[number]));
	else
	{
		count = ft_print_digit(number / base, base);
		return (count + ft_print_digit(number % base, base));
	}
}*/
