/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 17:56:12 by josmanov          #+#    #+#             */
/*   Updated: 2024/04/27 07:54:07 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*chr;
	unsigned char		uc;

	chr = (const unsigned char *)s;
	uc = (unsigned char)c;
	while (n-- > 0)
	{
		if (*chr == uc)
			return ((void *)chr);
		chr++;
	}
	return (NULL);
}
