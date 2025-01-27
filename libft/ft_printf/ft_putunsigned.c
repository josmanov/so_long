/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 16:49:49 by josmanov          #+#    #+#             */
/*   Updated: 2024/07/30 13:21:20 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putunsigned(unsigned int n)
{
	char	c[10];
	short	i;
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
		c[i++] = (n % 10) + 48;
		n /= 10;
	}
	while (i > 0)
	{
		if (write(1, &c[--i], 1) == -1)
			return (-1);
		count += 1;
	}
	return (count);
}
