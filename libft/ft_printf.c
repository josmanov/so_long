/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 02:07:57 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 18:12:24 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	print_format(char format, va_list ap)
{
	int	len;

	len = 0;
	if (format == 'c')
		len += ft_putchar(va_arg(ap, int));
	else if (format == 's')
		len += ft_putstr(va_arg(ap, char *));
	else if (format == 'd' || format == 'i')
		len += ft_putnbr(va_arg(ap, int));
	else if (format == 'u')
		len += ft_putunsigned(va_arg(ap, unsigned int));
	else if (format == 'x' || format == 'X')
		len += ft_puthex(va_arg(ap, unsigned int), format);
	else if (format == 'p')
		len += ft_putpointer(va_arg(ap, void *));
	else if (format == '%')
		len += ft_putchar('%');
	else
	{
		len += ft_putchar('%');
		len += ft_putchar(format);
	}
	return (len);
}

static int	process_format(const char **format, va_list ap)
{
	int	len;
	int	result;

	len = 0;
	while (**format)
	{
		if (**format == '%')
		{
			(*format)++;
			if (**format == '\0')
				return (-1);
			result = print_format(**format, ap);
			if (result == -1)
				return (-1);
			len += result;
		}
		else
		{
			if (write(1, *format, 1) == -1)
				return (-1);
			len++;
		}
		(*format)++;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		result;

	result = 0;
	if (format == NULL)
		return (-1);
	va_start(ap, format);
	result = process_format(&format, ap);
	va_end(ap);
	return (result);
}
