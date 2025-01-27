/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 18:38:31 by josmanov          #+#    #+#             */
/*   Updated: 2024/05/05 22:48:21 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t	i;
	char	*ptrsrc;
	char	*ptrdst;

	ptrsrc = (char *)src;
	ptrdst = (char *)dst;
	if (ptrdst < ptrsrc)
	{
		i = 0;
		while (i < len)
		{
			ptrdst[i] = ptrsrc[i];
			i++;
		}
	}
	else if (ptrdst > ptrsrc)
	{
		i = len;
		while (len--)
		{
			i--;
			ptrdst[i] = ptrsrc[i];
		}
	}
	return (dst);
}
