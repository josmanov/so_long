/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:14:48 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 01:52:13 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	empty_map(char **map)
{
	if (map[0])
		return (1);
	return (0);
}

int	rectangle_map(char **map)
{
	size_t	len;
	int		i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int	invalid_map(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (!ft_strchr("01CEPX", map[y][x]))
				return (1);
		}
	}
	return (0);
}

int	boundary_map(char **map)
{
	int	x;
	int	y;
	int	height;

	height = 0;
	while (map[height])
		height++;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if ((y == 0 || y == height - 1 || x == 0
					|| x == (int)ft_strlen(map[y]) - 1)
				&& map[y][x] != '1')
				return (0);
		}
	}
	return (1);
}

int	valid_map(t_game *game, char **map)
{
	if (!empty_map(map))
		return (ft_printf("Error: Map is empty\n"), 0);
	if (invalid_map(map))
		return (ft_printf("Error: Map contains invalid characters\n"), 0);
	if (!rectangle_map(map))
		return (ft_printf("Error: Map is not rectangular\n"), 0);
	if (!boundary_map(map))
		return (ft_printf("Error: Map is not closed by walls\n"), 0);
	min_map(game, map);
	if (game->p_count < 1)
		return (ft_printf("Error: Map must contain 1 player (P)\n"), 0);
	if (game->e_count < 1)
		return (ft_printf("Error: Map must contain 1 exit (E)\n"), 0);
	if (game->p_count > 1)
		return (ft_printf("Error: Map has more than 1 player (P)\n"), 0);
	if (game->e_count > 1)
		return (ft_printf("Error: Map has more than 1 exit (E).\n"), 0);
	if (game->c_count < 1)
		return (ft_printf("Error: Map has no collectibles (C)\n"), 0);
	return (1);
}
