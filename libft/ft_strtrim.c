/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:55:00 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 21:34:33 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	is_set(char c, const char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*new_str;
	char	*start;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return (ft_strdup(s1));
	while (*s1 && is_set(*s1, set))
		s1++;
	len = ft_strlen(s1);
	while (len > 0 && is_set(s1[len - 1], set))
		len--;
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	start = new_str;
	while (len--)
		*new_str++ = *s1++;
	*new_str = '\0';
	return (start);
}
