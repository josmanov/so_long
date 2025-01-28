/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:47:51 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 21:52:47 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long_bonus.h"

void	game_loop(void *param)
{
	static double	last_time = 0;
	t_game			*game;
	double			current_time;

	game = (t_game *)param;
	current_time = mlx_get_time();
	if (!game)
		return ;
	enemy_check_collision(game);
	if (current_time - last_time >= 0.2)
	{
		move_enemies(game);
		animate_collectibles(game);
		last_time = current_time;
	}
}
