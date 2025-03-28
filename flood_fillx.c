/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:16:33 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 21:45:52 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**str_cpy(char **str, int x, int y)
{
	char	**result;

	int (j), i = 0;
	result = malloc((y + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	while (str[i])
	{
		j = 0;
		result[i] = (char *)malloc((x + 1) * sizeof(char));
		if (result[i] == NULL)
			return (ft_freee(result), NULL);
		while (j < x)
		{
			result[i][j] = str[i][j];
			j++;
		}
		result[i][j] = '\0';
		i++;
	}
	result[i] = NULL;
	return (result);
}

static int	chek_valid_map(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] && str[i][j] != '\n')
		{
			if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'S')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void	fill(char **map, t_player size, int x, int y)
{
	if (x < 0 || y < 0 || x >= size.x || y >= size.y)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'S')
		return ;
	map[y][x] = 'S';
	fill(map, size, x + 1, y);
	fill(map, size, x - 1, y);
	fill(map, size, x, y + 1);
	fill(map, size, x, y - 1);
}

void	flood_fill(t_data *game)
{
	char	**cpy;

	cpy = str_cpy(game->str, game->size.x, game->size.y);
	if (cpy == NULL)
	{
		write(2, "error\nerror in malloc:(\n", 25);
		ft_error(game->str);
	}
	game->pos_player = finde_player(cpy);
	fill(cpy, game->size, game->pos_player.x, game->pos_player.y);
	if (chek_valid_map(cpy) == 1)
	{
		write(2, "error\nplayer cannot access all elements:(\n", 43);
		ft_freee(cpy);
		ft_error(game->str);
	}
	ft_freee(cpy);
}
