/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 16:46:02 by josmanov          #+#    #+#             */
/*   Updated: 2024/05/06 19:08:14 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	chr;
	char	*ptr;

	ptr = NULL;
	chr = (char)c;
	while (*s)
	{
		if (*s == chr)
			ptr = (char *)s;
		s++;
	}
	if (*s == chr)
		ptr = (char *)s;
	return (ptr);
}
