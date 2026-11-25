/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadout <mahadout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/08 21:15:27 by mahadout          #+#    #+#             */
/*   Updated: 2026/11/25 22:13:46 by mahadout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_format(char format, va_list *args)
{
	int	count;

	count = 0;
	if (format == 'c')
		count += ft_putchar(va_arg(*args, int));
	if (format == 's')
		count += ft_putstr(va_arg(*args, char *));
	if (format == 'i' || format == 'd')
		count += ft_putnbr(va_arg(*args, int));
	if (format == 'u')
		count += ft_putnbr_base(va_arg(*args, unsigned int), "0123456789", 10);
	if (format == 'x')
		count += ft_putnbr_base(va_arg(*args, unsigned int), \
"0123456789abcdef", 16);
	if (format == 'X')
		count += ft_putnbr_base(va_arg(*args, unsigned int), \
"0123456789ABCDEF", 16);
	if (format == 'p')
		count += ft_putptr(va_arg(*args, void *));
	if (format == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		i;
	int		count;
	va_list	args;

	count = 0;
	va_start(args, format);
	i = 0;
	if (!format)
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if ((format[++i] == 'c' || format[i] == 's' \
|| format[i] == 'i' || format[i] == 'd' \
|| format[i] == 'u' || format[i] == 'x' \
|| format[i] == 'X' || format[i] == 'p' \
|| format[i] == '%'))
				count += get_format(format[i], &args);
			else
				return (va_end(args), -1);
		}
		else
			count += ft_putchar(format[i]);
		if (count < 0)
			return (va_end(args), -1);
		i++;
	}
	return (va_end(args), count);
}
