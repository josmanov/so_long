/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectible.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:36:11 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 19:09:20 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	take_collectables(t_game *game)
{
	int	px;
	int	py;
	int	i;

	px = game->img->player->instances[0].x / TILE_SIZE;
	py = game->img->player->instances[0].y / TILE_SIZE;
	if (game->map[py][px] != MAP_COLLECT)
		return ;
	game->map[py][px] = MAP_FLOOR;
	game->n_collect--;
	i = -1;
	while (++i < (int)game->img->collect->count)
	{
		if (game->img->collect->instances[i].x / TILE_SIZE == px
			&& game->img->collect->instances[i].y / TILE_SIZE == py)
		{
			game->img->collect->instances[i].enabled = false;
			break ;
		}
	}
}
