/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 23:29:30 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 20:38:08 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_s;
	char	*start;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdup(s2));
	if (!s2)
		return (ft_strdup(s1));
	new_s = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!(new_s))
		return (NULL);
	start = new_s;
	while (*s1)
	{
		*new_s++ = *s1++;
	}
	while (*s2)
	{
		*new_s++ = *s2++;
	}
	*new_s = '\0';
	return (start);
}
