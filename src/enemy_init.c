/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 01:00:04 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 02:21:01 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	count_enemies(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	game->num_enemies = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == 'X')
				game->num_enemies++;
			x++;
		}
		y++;
	}
}

static void	init_single_enemy(t_game *game, int *i, int x, int y)
{
	mlx_image_t	*enemy_image;
	mlx_image_t	*enemy_up_image;
	int			x_tile_n;
	int			y_tile_n;
	int			enemy_direction;

	enemy_image = game->img->enemy;
	enemy_up_image = game->img->enemy_up;
	enemy_direction = (x + y) % 4;
	x_tile_n = x * game->tile_size;
	y_tile_n = y * game->tile_size;
	game->enemies[*i].x = x;
	game->enemies[*i].y = y;
	game->enemies[*i].direction = enemy_direction;
	game->enemies[*i].image = enemy_image;
	game->enemies[*i].image_up = enemy_up_image;
	mlx_image_to_window(game->mlx, enemy_image, x_tile_n, y_tile_n);
	mlx_image_to_window(game->mlx, enemy_up_image, x_tile_n, y_tile_n);
	game->enemies[*i].image_up->instances[*i].enabled = (enemy_direction == 0);
	game->enemies[*i].image->instances[*i].enabled = !(enemy_direction == 0);
	(*i)++;
}

void	init_enemies(t_game *game)
{
	int	i;
	int	y;
	int	x;

	i = 0;
	y = -1;
	count_enemies(game);
	if (game->num_enemies == 0 || !game->img->enemy)
		return ;
	game->enemies = malloc(sizeof(t_enemy) * game->num_enemies);
	if (!game->enemies)
		error_exit("Enemy allocation failed", game);
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
			if (game->map[y][x] == 'X')
				init_single_enemy(game, &i, x, y);
	}
}

void	cleanup_enemies(t_game *game)
{
	free(game->enemies);
}
