/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_elments_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:03:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/28 02:06:24 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	use_img(t_data *game, int *w, int *h)
{
	game->img.wall = mlx_xpm_file_to_image(game->mlx, "textures/wall.xpm", w,
			h);
	game->img.back = mlx_xpm_file_to_image(game->mlx, "textures/back.xpm", w,
			h);
	game->img.player = mlx_xpm_file_to_image(game->mlx, "textures/player.xpm",
			w, h);
	game->img.exit = mlx_xpm_file_to_image(game->mlx, "textures/exit.xpm", w,
			h);
	game->img.coin = mlx_xpm_file_to_image(game->mlx, "textures/coin.xpm", w,
			h);
	if (!game->img.wall || !game->img.back || !game->img.player
		|| !game->img.exit || !game->img.coin)
	{
		write(1, "Failed to load the image.\n", 27);
		clean(game, 1);
	}
}

static void	use_elment(t_data *game)
{
	int (w), h, j, i = -1;
	use_img(game, &w, &h);
	while (game->str[++i])
	{
		j = 0;
		while (game->str[i][j])
		{
			if (game->str[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mnw, game->img.player,
					j * w, i * h);
			if (game->str[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mnw, game->img.coin, j
					* w, i * h);
			if (game->str[i][j] == '0')
				mlx_put_image_to_window(game->mlx, game->mnw, game->img.back, j
					* w, i * h);
			if (game->str[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mnw, game->img.wall, j
					* w, i * h);
			if (game->str[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mnw, game->img.exit, j
					* w, i * h);
			j++;
		}
	}
}

void	use_elmnets(t_data *game)
{
	free_images(game);
	use_elment(game);
}
