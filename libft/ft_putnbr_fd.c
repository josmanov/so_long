/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 03:54:00 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 20:37:34 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbl;
	char	c[10];
	short	i;

	i = 0;
	nbl = n;
	if (nbl == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nbl < 0)
	{
		nbl *= -1;
		write(fd, "-", 1);
	}
	while (nbl > 0)
	{
		c[i++] = (nbl % 10) + 48;
		nbl /= 10;
	}
	while (i > 0)
	{
		write(fd, &c[--i], 1);
	}
}
