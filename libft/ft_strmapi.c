/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 01:51:29 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 20:38:32 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*new_str;
	char			*start;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	i = 0;
	new_str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (new_str == NULL)
		return (NULL);
	start = new_str;
	while (*s)
	{
		*start++ = f(i++, *s++);
	}
	*start = '\0';
	return (new_str);
}
