/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 10:00:09 by josmanov          #+#    #+#             */
/*   Updated: 2024/07/31 19:06:27 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static const char	*get_symbols(const char format)
{
	if (format == 'X')
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

static int	handle_print_char(char c)
{
	if (ft_putchar(c) == -1)
		return (-1);
	return (1);
}

static int	print_hex_digits(unsigned long n, const char *symbols)
{
	char	hex[16];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
		return (handle_print_char('0'));
	while (n > 0)
	{
		hex[i++] = symbols[n % 16];
		n /= 16;
	}
	while (i > 0)
	{
		if (handle_print_char(hex[--i]) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_puthex(unsigned long n, const char format)
{
	const char	*symbols;

	symbols = get_symbols(format);
	return (print_hex_digits(n, symbols));
}
