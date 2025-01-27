/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:22:26 by josmanov          #+#    #+#             */
/*   Updated: 2024/06/01 21:35:10 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static void	free_tokens(char **token_v, int position)
{
	int	i;

	i = 0;
	while (i < position)
	{
		free(token_v[i]);
		++i;
	}
	free(token_v);
}

static int	valid_malloc(char **token_v, int position, size_t buffer)
{
	token_v[position] = malloc(buffer + 1);
	if (NULL == token_v[position])
	{
		free_tokens(token_v, position);
		return (1);
	}
	return (0);
}

static int	add_str(char **token_v, char const *s, char delimeter)
{
	size_t	len;
	int		i;

	i = 0;
	while (*s)
	{
		len = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (len)
		{
			if (valid_malloc(token_v, i, len))
				return (1);
			ft_strlcpy(token_v[i], s - len, len + 1);
			i++;
		}
	}
	return (0);
}

static size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	int		inside_token;

	tokens = 0;
	while (*s)
	{
		inside_token = 0;
		while (*s == delimeter && *s)
			s++;
		while (*s != delimeter && *s)
		{
			if (!inside_token)
			{
				++tokens;
				inside_token = 1;
			}
			s++;
		}
	}
	return (tokens);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	tokens;
	char	**token_v;

	if (NULL == s)
		return (NULL);
	tokens = count_tokens(s, c);
	token_v = malloc((tokens + 1) * sizeof(char *));
	if (NULL == token_v)
		return (NULL);
	i = 0;
	while (i < tokens)
	{
		token_v[i] = NULL;
		++i;
	}
	if (add_str(token_v, s, c))
	{
		return (NULL);
	}
	token_v[tokens] = NULL;
	return (token_v);
}
