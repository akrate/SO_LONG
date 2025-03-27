/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:17:07 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 02:29:56 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	button_x(t_data *game)
{
	clean(game, 1);
	return (1);
}

void	init_game(t_data *game)
{
	game->mlx = NULL;
	game->mnw = NULL;
	game->str = NULL;
	game->collectbles = 0;
	game->mv = 0;
	game->img.back = NULL;
	game->img.coin = NULL;
	game->img.wall = NULL;
	game->img.exit = NULL;
	game->img.player = NULL;
	game->door.x = 0;
	game->door.y = 0;
	game->pos_player.x = 0;
	game->pos_player.y = 0;
	game->size.x = 0;
	game->size.y = 0;
}

int	main(int ac, char **av)
{
	t_data	game;

	if (ac != 2)
		return (1);
	cheking_ber(av[1]);
	init_game(&game);
	game.str = read_arg(av[1]);
	cheking_map(game.str);
	game.size = get_size(&game);
	flood_fill(&game);
	game.mlx = mlx_init();
	if (!game.mlx)
		clean(&game, 1);
	game.mnw = mlx_new_window(game.mlx, game.size.x * 32, game.size.y * 32,
			"test");
	if (!game.mnw)
		clean(&game, 1);
	game.collectbles = count_collectbles(game.str);
	game.door = finde_door(game.str);
	use_elmnets(&game);
	mlx_hook(game.mnw, 2, (1L << 0), movement, &game);
	mlx_hook(game.mnw, 17, 0, button_x, &game);
	mlx_loop(game.mlx);
}
