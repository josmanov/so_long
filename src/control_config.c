/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:50:04 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 19:14:57 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	check_exit(t_game *game)
{
	int	px;
	int	py;

	px = game->img->player->instances[0].x / TILE_SIZE;
	py = game->img->player->instances[0].y / TILE_SIZE;
	if (game->map[py][px] == MAP_EXIT && game->n_collect == 0)
	{
		ft_printf("You win!\n");
		clean_exit(game, EXIT_SUCCESS);
	}
}

void	my_key_hook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.action == MLX_PRESS || keydata.action == MLX_REPEAT)
	{
		if (keydata.key == MLX_KEY_W || keydata.key == MLX_KEY_UP)
			move_up(game);
		else if (keydata.key == MLX_KEY_S || keydata.key == MLX_KEY_DOWN)
			move_down(game);
		else if (keydata.key == MLX_KEY_A || keydata.key == MLX_KEY_LEFT)
			move_left(game);
		else if (keydata.key == MLX_KEY_D || keydata.key == MLX_KEY_RIGHT)
			move_right(game);
		else if (keydata.key == MLX_KEY_ESCAPE)
			clean_exit(game, EXIT_SUCCESS);
	}
}
