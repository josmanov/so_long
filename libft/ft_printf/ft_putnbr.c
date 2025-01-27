/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 06:03:59 by josmanov          #+#    #+#             */
/*   Updated: 2024/07/31 18:48:06 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"

static int	handle_int_min(int *n)
{
	if (write(1, "-", 1) == -1)
		return (-1);
	if (write(1, "2", 1) == -1)
		return (-1);
	*n = 147483648;
	return (2);
}

static int	print_number(int n)
{
	char	nbr[11];
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (n == 0)
	{
		if (write(1, "0", 1) == -1)
			return (-1);
		return (1);
	}
	while (n > 0)
	{
		nbr[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		if (write(1, &nbr[--i], 1) == -1)
			return (-1);
		count++;
	}
	return (count);
}

int	ft_putnbr(int n)
{
	int	count;

	count = 0;
	if (n == -2147483648)
		count += handle_int_min(&n);
	else if (n < 0)
	{
		if (write(1, "-", 1) == -1)
			return (-1);
		count++;
		n *= -1;
	}
	count += print_number(n);
	return (count);
}
