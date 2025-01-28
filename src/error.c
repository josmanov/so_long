/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:26:28 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/27 19:59:14 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../includes/so_long.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

void	clean_exit(t_game *game, int code)
{
	if (game->mlx)
		mlx_terminate(game->mlx);
	if (game->map)
		free_map(game->map);
	if (game->tex)
		free(game->tex);
	if (game->img)
		free(game->img);
	exit(code);
}

void	error_exit(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	clean_exit(game, EXIT_FAILURE);
}
