/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:30:55 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 02:12:25 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	size_map(t_game *game, char **map)
{
	int	i;

	i = 0;
	game->map_width = ft_strlen(map[0]);
	while (map[i])
		i++;
	game->map_height = i;
	game->n_collect = total_collect(game);
	game->map_width_pixels = game->map_width * TILE_SIZE;
	game->map_height_pixels = game->map_height * TILE_SIZE;
}

char	**read_map(char *map_read)
{
	int		fd;
	char	*line;
	char	*joined;
	char	*temp;
	char	**map;

	fd = open(map_read, O_RDONLY);
	if (fd < 0)
		return (NULL);
	joined = ft_strdup("");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp = joined;
		joined = ft_strjoin(joined, line);
		free(temp);
		free(line);
	}
	map = ft_split(joined, '\n');
	free(joined);
	close(fd);
	return (map);
}

int	min_map(t_game *game, char **map)
{
	int	y;
	int	x;

	game->p_count = 0;
	game->e_count = 0;
	game->c_count = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
				game->p_count++;
			else if (map[y][x] == 'E')
				game->e_count++;
			else if (map[y][x] == 'C')
				game->c_count++;
		}
	}
	return (game->p_count && game->e_count && game->c_count >= 1);
}

int	*start_pos(char **map)
{
	int	y;
	int	x;
	int	*pos;

	y = -1;
	pos = malloc(sizeof(int) * 2);
	if (!pos)
		return (NULL);
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'P')
			{
				pos[0] = y;
				pos[1] = x;
				return (pos);
			}
		}
	}
	free(pos);
	return (NULL);
}

int	check_flood(char **map)
{
	int	y;
	int	x;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == 'C' || map[y][x] == 'E')
				return (0);
		}
	}
	return (1);
}
