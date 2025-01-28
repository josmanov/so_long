/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_config.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:01:37 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/28 01:38:08 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static void	cleanup_textures(t_game *game)
{
	mlx_delete_texture(game->tex->floor);
	mlx_delete_texture(game->tex->wall);
	mlx_delete_texture(game->tex->collect);
	mlx_delete_texture(game->tex->player);
	mlx_delete_texture(game->tex->exit);
}

int	get_textures(t_game *game)
{
	game->tex->floor = mlx_load_png("./textures/floor.png");
	game->tex->wall = mlx_load_png("./textures/wall.png");
	game->tex->collect = mlx_load_png("./textures/collect.png");
	game->tex->player = mlx_load_png("./textures/player.png");
	game->tex->exit = mlx_load_png("./textures/exit.png");
	if (!game->tex->floor
		|| !game->tex->wall
		|| !game->tex->collect
		|| !game->tex->player
		|| !game->tex->exit)
		return (ft_printf("Error: Couldnt load textures\n"), 0);
	return (1);
}

int	get_images(t_game *game)
{
	game->img->floor = mlx_texture_to_image(game->mlx, game->tex->floor);
	game->img->wall = mlx_texture_to_image(game->mlx, game->tex->wall);
	game->img->collect = mlx_texture_to_image(game->mlx, game->tex->collect);
	game->img->player = mlx_texture_to_image(game->mlx, game->tex->player);
	game->img->exit = mlx_texture_to_image(game->mlx, game->tex->exit);
	cleanup_textures(game);
	if (!game->img->floor
		|| !game->img->wall
		|| !game->img->collect
		|| !game->img->player
		|| !game->img->exit)
		return (ft_printf("Error: Couldnt set textures as images\n"), 0);
	return (1);
}
