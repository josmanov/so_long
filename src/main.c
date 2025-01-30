/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 18:48:46 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/31 01:23:34 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

static int	initialize_game(t_game *game)
{
	int	map_w_pixels;
	int	map_h_pixels;

	game->tile_size = TILE_SIZE;
	game->map_width_pixels = game->map_width * TILE_SIZE;
	game->map_height_pixels = game->map_height * TILE_SIZE;
	map_w_pixels = game->map_width_pixels;
	map_h_pixels = game->map_height_pixels;
	game->move_count = 0;
	mlx_set_setting(MLX_STRETCH_IMAGE, 1);
	game->mlx = mlx_init(map_w_pixels, map_h_pixels, "so_long", true);
	if (!game->mlx)
		return (0);
	game->tex = ft_calloc(1, sizeof(t_textures));
	game->img = ft_calloc(1, sizeof(t_images));
	if (!game->tex || !game->img)
		return (0);
	return (1);
}

static void	game_cleanup(t_game *game)
{
	cleanup_images(game);
	mlx_terminate(game->mlx);
	free_map(game->map);
	free(game->tex);
	free(game->img);
}

int	init_game_window(t_game *game)
{
	if (!initialize_game(game))
		return (0);
	if (!get_textures(game))
		return (0);
	if (!get_images(game))
		return (0);
	draw_map(game, game->img);
	mlx_key_hook(game->mlx, &my_key_hook, game);
	mlx_loop(game->mlx);
	game_cleanup(game);
	return (1);
}

int	main(int argc, char **argv)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (argc != 2)
		return (ft_printf("Error: Enter ./so_long (map name).ber\n"), 1);
	if (!check_extension(argv[1]))
		return (ft_printf("Error: Invalid file extension\n"), 1);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (ft_printf("Error: Error opening file\n"), 1);
	if (!valid_map(&game, game.map))
		return (free_map(game.map), 1);
	size_map(&game, game.map);
	if (!valid_path(&game, argv[1]))
	{
		free_map(game.map);
		ft_printf("Error: Player has no path to Collectable (C) or ");
		return (ft_printf("Exit (E).\n"), 1);
	}
	if (!init_game_window(&game))
		return (ft_printf("Error: Game initialization failed\n"), 1);
	return (0);
}
