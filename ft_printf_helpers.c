/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_helpers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahadout <mahadout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 21:12:19 by mahadout          #+#    #+#             */
/*   Updated: 2026/11/13 21:55:49 by mahadout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	return (write(1, &c, 1));
}

int	ft_putstr(char *str)
{
	int	count;
	int	i;

	if (!str)
		return (ft_putstr("(null)"));
	count = 0;
	i = 0;
	while (str[i])
	{
		count += ft_putchar(str[i++]);
		if (count < 0)
			return (-1);
	}
	return (count);
}

int	ft_putnbr_base(unsigned long n, char *base, int base_len)
{
	int	count;

	count = 0;
	if (n >= (unsigned long)base_len)
		count += ft_putnbr_base(n / base_len, base, base_len);
	count += ft_putchar(base[n % base_len]);
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n < 0)
	{
		count += ft_putchar('-');
		count += ft_putnbr_base(-(unsigned long)n, "0123456789", 10);
	}
	else
		count += ft_putnbr_base((unsigned long)n, "0123456789", 10);
	return (count);
}

int	ft_putptr(void *p)
{
	int	count;

	if (!p)
		return (ft_putstr("(nil)"));
	count = 0;
	count += ft_putstr("0x");
	count += ft_putnbr_base((unsigned long)p, "0123456789abcdef", 16);
	return (count);
}
