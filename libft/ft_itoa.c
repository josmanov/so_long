/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:34:43 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 20:35:48 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	get_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*number;
	int		len;
	int		neg;

	len = get_len(n);
	number = (char *)malloc(len + 1);
	if (!number)
		return (NULL);
	number[len] = '\0';
	if (n < 0)
		neg = -1;
	else
		neg = 1;
	while (len-- > 0)
	{
		number[len] = '0' + (n % 10) * neg;
		n /= 10;
	}
	if (neg == -1)
		number[0] = '-';
	return (number);
}
