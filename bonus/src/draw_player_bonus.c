/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:57:26 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 18:58:12 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

void	draw_player(t_game *game, t_images *img, int x, int y)
{
	int	x_tile_size;
	int	y_tile_size;

	x_tile_size = x * TILE_SIZE;
	y_tile_size = y * TILE_SIZE;
	if (!img->player || !img->player_left)
		error_exit("Player textures failed to load", game);
	mlx_image_to_window(game->mlx, img->player, x_tile_size, y_tile_size);
	mlx_image_to_window(game->mlx, img->player_left, x_tile_size, y_tile_size);
	img->player_left->instances[0].enabled = false;
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
