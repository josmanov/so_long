/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_control_config.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:58:14 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 01:09:46 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	update_sprite(t_enemy *enemy, int i)
{
	if (enemy->direction == 0)
	{
		enemy->image->instances[i].enabled = false;
		enemy->image_up->instances[i].enabled = true;
	}
	else
	{
		enemy->image->instances[i].enabled = true;
		enemy->image_up->instances[i].enabled = false;
	}
}

static void	handle_movement(t_enemy *enemy, t_game *g, int i)
{
	int	next[2];

	next[0] = enemy->x;
	next[1] = enemy->y;
	if (enemy->direction == 0)
		next[1]--;
	else if (enemy->direction == 1)
		next[1]++;
	else if (enemy->direction == 2)
		next[0]--;
	else if (enemy->direction == 3)
		next[0]++;
	if (next[1] < 0 || next[1] >= g->map_height || next[0] < 0
		|| next[0] >= g->map_width)
		enemy->direction = (enemy->direction + 1) % 4;
	else if (g->map[next[1]][next[0]] != MAP_WALL)
	{
		enemy->x = next[0];
		enemy->y = next[1];
	}
	else
		enemy->direction = (enemy->direction + 1) % 4;
	update_sprite(enemy, i);
}

static void	set_positions(t_enemy *enemy, t_game *g, int i)
{
	enemy->image->instances[i].x = enemy->x * g->tile_size;
	enemy->image->instances[i].y = enemy->y * g->tile_size;
	enemy->image_up->instances[i].x = enemy->x * g->tile_size;
	enemy->image_up->instances[i].y = enemy->y * g->tile_size;
}

void	enemy_check_collision(t_game *game)
{
	t_enemy	*enemy;
	int		player_x;
	int		player_y;
	int		i;

	i = 0;
	if (game->game_over)
		return ;
	player_x = game->img->player->instances[0].x / game->tile_size;
	player_y = game->img->player->instances[0].y / game->tile_size;
	while (i < game->num_enemies)
	{
		enemy = &game->enemies[i];
		if (enemy->x == player_x && enemy->y == player_y)
		{
			ft_printf("\n********************************\n");
			ft_printf("|   Game Over :( - Try Again?  |\n");
			game->game_over = true;
			game->final_time = mlx_get_time();
			clean_exit(game, EXIT_SUCCESS);
			return ;
		}
		i++;
	}
}

void	move_enemies(t_game *game)
{
	int	i;

	i = 0;
	if (game->num_enemies == 0 || !game->img->enemy)
		return ;
	while (i < game->num_enemies)
	{
		handle_movement(&game->enemies[i], game, i);
		set_positions(&game->enemies[i], game, i);
		i++;
	}
}
