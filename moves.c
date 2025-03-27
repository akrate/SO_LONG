/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:05:01 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 03:06:25 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_to_left(t_data *data)
{
	t_player	pos;

	pos = finde_player(data->str);
	if (chek_collecteble(data->str[pos.y][pos.x - 1]) == 1)
		data->collectbles = data->collectbles - 1;
	if (chek_move(data->str[pos.y][pos.x - 1]) == 0)
	{
		if (chek_exit(data->str[pos.y][pos.x - 1]) == 1
			&& data->collectbles == 0)
			clean(data, 0);
		else
		{
			data->str[pos.y][pos.x] = '0';
			data->str[pos.y][pos.x - 1] = 'P';
		}
	}
	print(data->mv);
}

void	move_to_right(t_data *data)
{
	t_player	pos;

	pos = finde_player(data->str);
	if (chek_collecteble(data->str[pos.y][pos.x + 1]) == 1)
		data->collectbles = data->collectbles - 1;
	if (chek_move(data->str[pos.y][pos.x + 1]) == 0)
	{
		if (data->str[data->door.y][data->door.x] != 'P'
			&& data->str[data->door.y][data->door.x] != 'E')
			data->str[data->door.y][data->door.x] = 'E';
		if (chek_exit(data->str[pos.y][pos.x + 1]) == 1
			&& data->collectbles == 0)
			clean(data, 0);
		else
		{
			data->str[pos.y][pos.x] = '0';
			data->str[pos.y][pos.x + 1] = 'P';
		}
	}
	print(data->mv);
}

void	move_tao_top(t_data *data)
{
	t_player	pos;

	pos = finde_player(data->str);
	if (chek_collecteble(data->str[pos.y - 1][pos.x]) == 1)
		data->collectbles = data->collectbles - 1;
	if (chek_move(data->str[pos.y - 1][pos.x]) == 0)
	{
		if (chek_exit(data->str[pos.y - 1][pos.x]) == 1
			&& data->collectbles == 0)
			clean(data, 0);
		else
		{
			data->str[pos.y][pos.x] = '0';
			data->str[pos.y - 1][pos.x] = 'P';
		}
	}
	print(data->mv);
}

void	move_to_bottom(t_data *data)
{
	t_player	pos;

	pos = finde_player(data->str);
	if (chek_collecteble(data->str[pos.y + 1][pos.x]) == 1)
		data->collectbles = data->collectbles - 1;
	if (chek_move(data->str[pos.y + 1][pos.x]) == 0)
	{
		if (chek_exit(data->str[pos.y + 1][pos.x]) == 1
			&& data->collectbles == 0)
			clean(data, 0);
		else
		{
			data->str[pos.y][pos.x] = '0';
			data->str[pos.y + 1][pos.x] = 'P';
		}
	}
	print(data->mv);
}

void	ecs(t_data *game)
{
	clean(game, 1);
}
