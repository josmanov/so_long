/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animate_collectibles.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 01:55:28 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 02:02:08 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	update_collectible(t_game *g, int x, int y, int state)
{
	int	i;

	if (g->map[y][x] != MAP_COLLECT)
		return ;
	i = 0;
	while (i < (int)g->img->collect->count)
	{
		if ((g->img->collect->instances[i].x / TILE_SIZE == x)
			&& (g->img->collect->instances[i].y / TILE_SIZE == y))
		{
			g->img->collect->instances[i].enabled = (state == 0);
			g->img->collect2->instances[i].enabled = (state == 1);
			g->img->collect3->instances[i].enabled = (state == 2);
			break ;
		}
		i++;
	}
}

void	animate_collectibles(t_game *game)
{
	static double	last;
	double			now;
	int				state;
	int				x;
	int				y;

	now = mlx_get_time();
	if ((now - last) < 0.15)
		return ;
	last = now;
	state = (int)(now * 6.60) % 3;
	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			update_collectible(game, x, y, state);
			x++;
		}
		y++;
	}
}
