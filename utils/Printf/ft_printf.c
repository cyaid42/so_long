/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyaid <cyaid@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 02:32:00 by msan              #+#    #+#             */
/*   Updated: 2023/11/20 19:05:33 by cyaid            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_h(unsigned long int nb, unsigned long int b)
{
	int	i;

	i = 1;
	while (nb >= b)
	{
		nb = nb / b;
		i++;
	}
	return (i);
}

int	ft_print_digit(unsigned long int n, char *base)
{
	if (n < ft_strlen(base))
	{
		ft_putchar(base[n]);
	}
	if (n >= ft_strlen(base))
	{
		ft_print_digit(n / ft_strlen(base), base);
		ft_print_digit(n % ft_strlen(base), base);
	}
	return (ft_count_h(n, ft_strlen(base)));
}

int	ft_print_format2(char spec, va_list ap, int i)
{
	if (spec == 'c')
		i = ft_putchar(va_arg(ap, int));
	else if (spec == 's')
		i = ft_putstr(va_arg(ap, char *));
	else if (spec == 'd' || spec == 'i')
		i = ft_putnbr((long)va_arg(ap, int));
	return (i);
}

int	ft_print_format(char spec, va_list ap)
{
	int		i;
	void	*p;

	i = 0;
	if (spec == 'c' || spec == 's' || (spec == 'd' || spec == 'i'))
		i = ft_print_format2(spec, ap, i);
	else if (spec == 'u')
		i = ft_print_digit(va_arg(ap, unsigned int), "0123456789");
	else if (spec == 'x')
		i = ft_print_digit((long)va_arg(ap, unsigned int), "0123456789abcdef");
	else if (spec == 'X')
		i = ft_print_digit((long)va_arg(ap, unsigned int), "0123456789ABCDEF");
	else if (spec == 'p')
	{
		p = va_arg(ap, void *);
		if (!p)
			return (write(1, "(nil)", 5));
		return (ft_putstr("0x") + ft_print_digit((unsigned long int)p,
				"0123456789abcdef"));
	}
	else if (spec == '%')
		return (ft_putchar('%'));
	else
		i += write(1, &spec, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	ap;

	va_start(ap, format);
	i = 0;
	count = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
			count += ft_print_format(format[++i], ap);
		else
		{
			ft_putchar(format[i]);
			count++;
		}
		i++;
	}
	va_end(ap);
	return (count);
}
