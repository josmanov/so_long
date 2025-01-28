/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 22:35:09 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/28 01:40:09 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "MLX42/MLX42.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

# define MAP_EXIT 'E'
# define MAP_ENTRY 'P'
# define MAP_COLLECT 'C'
# define MAP_WALL '1'
# define MAP_FLOOR '0'
# define TILE_SIZE 64
# define BUFF_SIZE 10000

typedef struct s_textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*player;
	mlx_texture_t	*exit;
}					t_textures;

typedef struct s_images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*counter;
	mlx_image_t	*collect;
	mlx_image_t	*player;
	mlx_image_t	*exit;
}				t_images;

typedef struct s_game
{
	t_textures		*tex;
	t_images		*img;
	mlx_t			*mlx;
	char			**map;
	char			**map_2;
	int				map_width;
	int				map_height;
	int				map_width_pixels;
	int				map_height_pixels;
	int				count_collect;
	int				move_count;
	int				n_collect;
	int				tile_size;
	bool			game_over;
	int				p_count;
	int				e_count;
	int				c_count;
}					t_game;

int		init_game_window(t_game *game);
void	cleanup_game(t_game *game);
char	**read_map(char *map_read);
void	free_map(char **map);
int		valid_map(t_game *game, char **map);
int		valid_path(t_game *game, char *fd);
int		check_extension(const char *filename); // Added
void	my_key_hook(mlx_key_data_t keydata, void *param);
void	take_collectables(t_game *game);
void	size_map(t_game *game, char **map);
int		total_collect(t_game *game);
void	draw_map(t_game *game, t_images *image);
int		min_map(t_game *game, char **map);
int		*start_pos(char **map);
void	move_up(t_game *game);
void	move_left(t_game *game);
void	move_down(t_game *game);
void	move_right(t_game *game);
int		*start_pos(char **map);
int		get_textures(t_game *game);
int		get_images(t_game *game);
void	clean_exit(t_game *game, int code);
void	error_exit(char *message, t_game *game);
void	draw_map(t_game *game, t_images *img);
void	draw_player_layer(t_game *game, t_images *img);
void	draw_player(t_game *game, t_images *img, int x, int y);
void	check_exit(t_game *game);
void	print_exit(t_game *game);

#endif
