/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:57:26 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 19:10:40 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	draw_player(t_game *game, t_images *img, int x, int y)
{
	int	x_tile_size;
	int	y_tile_size;

	x_tile_size = x * TILE_SIZE;
	y_tile_size = y * TILE_SIZE;
	if (!img->player)
		error_exit("Player texture failed to load", game);
	mlx_image_to_window(game->mlx, img->player, x_tile_size, y_tile_size);
}

void	draw_player_layer(t_game *game, t_images *img)
{
	int	y;
	int	x;

	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == MAP_ENTRY)
				draw_player(game, img, x, y);
		}
	}
}
