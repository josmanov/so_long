/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_config.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:30:55 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/28 04:02:47 by josmanov         ###   ########.fr       */
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

static char	**check_empty_lines(char **map)
{
	int	i;

	if (!map)
		return (NULL);
	i = 0;
	while (map[i])
	{
		if (ft_strlen(map[i]) == 0)
		{
			free_map(map);
			return (NULL);
		}
		i++;
	}
	return (map);
}

char	**read_map(char *map_read)
{
	int		fd;
	char	*line;
	char	*temp_join;
	char	*temp_line;
	char	**map;

	fd = open(map_read, O_RDONLY);
	temp_join = ft_strdup("");
	if (fd < 0 || !temp_join)
		return (free(temp_join), NULL);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		temp_line = temp_join;
		temp_join = ft_strjoin(temp_join, line);
		free(temp_line);
		free(line);
	}
	close(fd);
	map = ft_split(temp_join, '\n');
	free(temp_join);
	return (check_empty_lines(map));
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
