/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:41 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 21:50:45 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_putnbr(int nbr)
{
	char	*str;

	str = "0123456789";
	if (nbr > 9)
		ft_putnbr(nbr / 10);
	write(1, &str[nbr % 10], 1);
}

void	print(int move)
{
	write(1, "move = ", 7);
	ft_putnbr(move);
	write(1, "\n", 1);
}

int	movement(int event, t_data *game)
{
	if (event == W || event == TOP)
		move_tao_top(game);
	else if (event == A || event == LEFT)
		move_to_left(game);
	else if (event == S || event == BOTTOM)
		move_to_bottom(game);
	else if (event == D || event == RIGHT)
		move_to_right(game);
	else if (event == ECS)
		ecs(game);
	if (game->str[game->door.y][game->door.x] != 'P'
		&& game->str[game->door.y][game->door.x] != 'E')
		game->str[game->door.y][game->door.x] = 'E';
	use_elmnets(game);
	return (0);
}
