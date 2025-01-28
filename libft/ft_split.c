/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 00:22:26 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 06:41:27 by josmanov         ###   ########.fr       */
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
		i++;
	}
	free(token_v);
}

static int	valid_malloc(char **token_v, int position, size_t buffer)
{
	token_v[position] = malloc(buffer + 1);
	if (token_v[position] == NULL)
	{
		free_tokens(token_v, position);
		return (1);
	}
	return (0);
}

static int	add_str(char **token_v, char const *s, char delimeter)
{
	const char	*start;
	size_t		len;
	int			i;

	i = 0;
	while (*s)
	{
		len = 0;
		start = s;
		while (*s != delimeter && *s)
		{
			len++;
			s++;
		}
		if (valid_malloc(token_v, i, len))
			return (1);
		ft_strlcpy(token_v[i], start, len + 1);
		i++;
		if (*s == delimeter)
			s++;
	}
	return (0);
}

static size_t	count_tokens(char const *s, char delimeter)
{
	size_t	tokens;
	int		in_token;

	tokens = 0;
	in_token = 0;
	while (*s)
	{
		if (*s != delimeter)
		{
			if (!in_token)
				tokens++;
			in_token = 0;
		}
		else
		{
			if (!in_token)
				tokens++;
			in_token = 1;
		}
		s++;
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
		return (NULL);
	token_v[tokens] = NULL;
	return (token_v);
}
