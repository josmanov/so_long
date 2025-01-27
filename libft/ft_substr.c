/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 09:44:25 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 21:33:42 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	size_t			j;
	char			*ss;

	if (s == NULL)
		return (NULL);
	if (start >= ft_strlen(s) || len == 0)
		return (ft_strdup(""));
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	i = start;
	j = 0;
	ss = malloc((len + 1) * sizeof(char));
	if (ss == NULL)
		return (NULL);
	while (s[i] && j < len)
	{
		ss[j] = s[i];
		i++;
		j++;
	}
	ss[j] = '\0';
	return (ss);
}
