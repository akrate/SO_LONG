/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:42:56 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/28 02:08:02 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	exit(1);
}

void	ft_freee(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	free_images(t_data *game)
{
	if (!game->mlx || !game->mnw)
		return ;
	if (game->img.wall)
		mlx_destroy_image(game->mlx, game->img.wall);
	if (game->img.player)
		mlx_destroy_image(game->mlx, game->img.player);
	if (game->img.coin)
		mlx_destroy_image(game->mlx, game->img.coin);
	if (game->img.back)
		mlx_destroy_image(game->mlx, game->img.back);
	if (game->img.exit)
		mlx_destroy_image(game->mlx, game->img.exit);
}

void	clean(t_data *game, int i)
{
	free_images(game);
	if (game->str)
		ft_freee(game->str);
	if (game->mlx && game->mnw)
		mlx_destroy_window(game->mlx, game->mnw);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	if (i == 1)
		exit(1);
	else if (i == 0)
	{
		exit(0);
	}
	else if (i == 2)
	{
		write (1, "you win :)\n", 12);
		exit(0);
	}
}
