/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/29 05:45:00 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 18:15:29 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
	{
		if (write(1, "(null)", 6) == -1)
			return (-1);
		else
			return (6);
	}
	while (*str)
	{
		if (ft_putchar((int)*str) == -1)
			return (-1);
		str++;
		i++;
	}
	return (i);
}
