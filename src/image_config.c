/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:01:37 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 18:13:20 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	load_bonus_textures(t_game *game)
{
	game->tex->collect2 = mlx_load_png("./textures/collect2.png");
	game->tex->collect3 = mlx_load_png("./textures/collect3.png");
	game->tex->player_left = mlx_load_png("./textures/player_left.png");
	game->tex->exit_2 = mlx_load_png("./textures/exit2.png");
	game->tex->enemy = mlx_load_png("./textures/enemy.png");
	game->tex->enemy_up = mlx_load_png("./textures/enemy_up.png");
}

void	get_textures(t_game *game)
{
	game->tex->floor = mlx_load_png("./textures/floor.png");
	game->tex->wall = mlx_load_png("./textures/wall.png");
	game->tex->collect = mlx_load_png("./textures/collect.png");
	game->tex->player = mlx_load_png("./textures/player.png");
	game->tex->exit = mlx_load_png("./textures/exit.png");
	load_bonus_textures(game);
}

static void	cleanup_textures(t_game *game)
{
	mlx_delete_texture(game->tex->floor);
	mlx_delete_texture(game->tex->wall);
	mlx_delete_texture(game->tex->collect);
	mlx_delete_texture(game->tex->player);
	mlx_delete_texture(game->tex->exit);
	mlx_delete_texture(game->tex->collect2);
	mlx_delete_texture(game->tex->collect3);
	mlx_delete_texture(game->tex->player_left);
	mlx_delete_texture(game->tex->exit_2);
	mlx_delete_texture(game->tex->enemy);
	mlx_delete_texture(game->tex->enemy_up);
}

void	get_images(t_game *game)
{
	mlx_texture_t	*player_left_tex;

	player_left_tex = game->tex->player_left;
	game->img->floor = mlx_texture_to_image(game->mlx, game->tex->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->tex->wall);
	game->img->collect = mlx_texture_to_image(game->mlx, game->tex->collect);
	game->img->player = mlx_texture_to_image(game->mlx, game->tex->player);
	game->img->exit = mlx_texture_to_image(game->mlx, game->tex->exit);
	game->img->collect2 = mlx_texture_to_image(game->mlx, game->tex->collect2);
	game->img->collect3 = mlx_texture_to_image(game->mlx, game->tex->collect3);
	game->img->player_left = mlx_texture_to_image(game->mlx, player_left_tex);
	game->img->exit_2 = mlx_texture_to_image(game->mlx, game->tex->exit_2);
	game->img->enemy = mlx_texture_to_image(game->mlx, game->tex->enemy);
	game->img->enemy_up = mlx_texture_to_image(game->mlx, game->tex->enemy_up);
	cleanup_textures(game);
}
