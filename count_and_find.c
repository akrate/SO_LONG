/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_and_find.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:10:47 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 23:04:05 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i][0] == '\n')
		{
			write(2, "error\nmap is not correct\n", 26);
			ft_error(str);
			exit (1);
		}
		i++;
	}
	return (i);
}

int	count_collectbles(char **str)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (str[j])
	{
		i = 0;
		while (str[j][i])
		{
			if (str[j][i] == 'C')
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

t_player	finde_player(char **map)
{
	t_player	p;
	int			y;
	int			x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
			{
				p.y = y;
				p.x = x;
			}
			x++;
		}
		y++;
	}
	return (p);
}

t_player	finde_door(char **map)
{
	t_player	p;

	p.y = 0;
	while (map[p.y])
	{
		p.x = 0;
		while (map[p.y][p.x])
		{
			if (map[p.y][p.x] == 'E')
			{
				return (p);
			}
			p.x++;
		}
		p.y++;
	}
	return (p);
}

t_player	get_size(t_data *game)
{
	t_player	size;

	size.x = cheking_body(game->str);
	size.y = count_line(game->str);
	return (size);
}
