/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: josmanov <josmanov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/26 17:48:41 by josmanov          #+#    #+#             */
/*   Updated: 2025/01/26 17:49:47 by josmanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long_bonus.h"

int	total_collect(t_game *game)
{
	int	count;
	int	y;
	int	x;

	count = 0;
	y = -1;
	while (game->map[++y])
	{
		x = -1;
		while (game->map[y][++x])
		{
			if (game->map[y][x] == 'C')
				count++;
		}
	}
	return (count);
}

void	update_move_count_display(t_game *game)
{
	char	*count_str;
	char	*prefix;
	char	*full_str;

	if (game->img->counter)
		mlx_delete_image(game->mlx, game->img->counter);
	prefix = ft_strdup("Moves: ");
	if (!prefix)
		return ;
	count_str = ft_itoa(game->move_count);
	if (!count_str)
	{
		free(prefix);
		return ;
	}
	full_str = ft_strjoin(prefix, count_str);
	free(prefix);
	free(count_str);
	if (!full_str)
		return ;
	game->img->counter = mlx_put_string(game->mlx, full_str, 10, 10);
	free(full_str);
}
