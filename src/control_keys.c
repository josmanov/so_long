/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_keys.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 19:01:51 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 01:22:41 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	update_player_position(t_game *game, int dx, int dy)
{
	game->img->player->instances[0].x += dx * game->tile_size;
	game->img->player->instances[0].y += dy * game->tile_size;
	game->move_count++;
	ft_printf("MOVES: %i\n", game->move_count);
}

void	move_up(t_game *game)
{
	int	x;
	int	y;

	x = game->img->player->instances[0].x / TILE_SIZE;
	y = game->img->player->instances[0].y / TILE_SIZE;
	if (y > 0 && game->map[y - 1][x] != MAP_WALL &&
		(game->map[y - 1][x] || game->n_collect == 0))
	{
		update_player_position(game, 0, -1);
		take_collectables(game);
		check_exit(game);
	}
}

void	move_down(t_game *game)
{
	int	x;
	int	y;

	x = game->img->player->instances[0].x / TILE_SIZE;
	y = game->img->player->instances[0].y / TILE_SIZE;
	if (y < game->map_height - 1 && game->map[y + 1][x] != MAP_WALL &&
		(game->map[y + 1][x] || game->n_collect == 0))
	{
		update_player_position(game, 0, 1);
		take_collectables(game);
		check_exit(game);
	}
}

void	move_left(t_game *game)
{
	int	x;
	int	y;

	x = game->img->player->instances[0].x / TILE_SIZE;
	y = game->img->player->instances[0].y / TILE_SIZE;
	if (x > 0 && game->map[y][x - 1] != MAP_WALL &&
		(game->map[y][x - 1] || game->n_collect == 0))
	{
		update_player_position(game, -1, 0);
		take_collectables(game);
		check_exit(game);
	}
}

void	move_right(t_game *game)
{
	int	x;
	int	y;

	x = game->img->player->instances[0].x / TILE_SIZE;
	y = game->img->player->instances[0].y / TILE_SIZE;
	if (x < game->map_width - 1 && game->map[y][x + 1] != MAP_WALL &&
		(game->map[y][x + 1] || game->n_collect == 0))
	{
		update_player_position(game, 1, 0);
		take_collectables(game);
		check_exit(game);
	}
}
