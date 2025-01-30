/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map_extra.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:56:20 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 01:23:07 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	flood_fill(t_game *game, int y, int x)
{
	if (y < 0 || x < 0 || y >= game->map_height || x >= game->map_width)
		return ;
	if (game->map_2[y][x] == '1' || game->map_2[y][x] == 'F')
		return ;
	game->map_2[y][x] = 'F';
	flood_fill(game, y + 1, x);
	flood_fill(game, y - 1, x);
	flood_fill(game, y, x + 1);
	flood_fill(game, y, x - 1);
}

static int	check_flood(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}

int	valid_path(t_game *game, char *fd)
{
	int	*pos;

	game->map_2 = read_map(fd);
	if (!game->map_2)
		return (ft_printf("Map read error\n"), 0);
	pos = start_pos(game->map_2);
	if (!pos)
		return (free_map(game->map_2), 0);
	flood_fill(game, pos[0], pos[1]);
	if (!check_flood(game->map_2))
		return (free(pos), free_map(game->map_2), 0);
	free(pos);
	free_map(game->map_2);
	return (1);
}

int	check_extension(const char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strncmp(filename + len - 4, ".ber", 4) == 0);
}
