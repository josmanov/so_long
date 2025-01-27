/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:18:15 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 18:15:34 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	draw_floor(t_game *game, t_images *img, int x, int y)
{
	mlx_image_to_window(game->mlx, img->floor, x * TILE_SIZE, y * TILE_SIZE);
}

static void	draw_walls(t_game *game, t_images *img, int x, int y)
{
	if (game->map[y][x] == MAP_WALL)
		mlx_image_to_window(game->mlx, img->wall,
			x * TILE_SIZE, y * TILE_SIZE);
}

void	draw_collectibles(t_game *game, t_images *img, int x, int y)
{
	int	x_tile_size;
	int	y_tile_size;

	x_tile_size = x * TILE_SIZE;
	y_tile_size = y * TILE_SIZE;
	if (game->map[y][x] == MAP_COLLECT)
	{
		mlx_image_to_window(game->mlx, img->collect, x_tile_size, y_tile_size);
		mlx_image_to_window(game->mlx, img->collect2, x_tile_size, y_tile_size);
		mlx_image_to_window(game->mlx, img->collect3, x_tile_size, y_tile_size);
		img->collect2->instances[img->collect2->count - 1].enabled = false;
		img->collect3->instances[img->collect3->count - 1].enabled = false;
	}
}

static void	draw_exit(t_game *game, t_images *img, int x, int y)
{
	int	x_tile_size;
	int	y_tile_size;

	x_tile_size = x * TILE_SIZE;
	y_tile_size = y * TILE_SIZE;
	if (game->map[y][x] == MAP_EXIT)
	{
		mlx_image_to_window(game->mlx, img->exit, x_tile_size, y_tile_size);
		mlx_image_to_window(game->mlx, img->exit_2, x_tile_size, y_tile_size);
		img->exit_2->instances[img->exit_2->count - 1].enabled = false;
	}
}

void	draw_map(t_game *game, t_images *img)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			draw_floor(game, img, x, y);
			draw_walls(game, img, x, y);
			draw_collectibles(game, img, x, y);
			draw_exit(game, img, x, y);
		}
	}
	draw_player_layer(game, img);
}
