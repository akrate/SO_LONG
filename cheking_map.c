/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:44:38 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 03:04:07 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_elements(char **str)
{
	int (i), j, player, coins, exit;
	i = 0;
	player = 0;
	coins = 0;
	exit = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == 'P')
				player++;
			else if (str[i][j] == 'C')
				coins++;
			else if (str[i][j] == 'E')
				exit++;
			j++;
		}
		i++;
	}
	if (exit != 1 || player != 1 || coins == 0)
		return (1);
	return (0);
}

static int	cheking_line(char *str)
{
	int	i;

	i = 0;
	if (str[0] != '1')
		return (1);
	while (str[i] != '\n')
	{
		if (str[i] != '1' && str[i] != 'E' && str[i] != 'P' && str[i] != 'C'
			&& str[i] != '0')
			return (1);
		i++;
	}
	if (str[i - 1] != '1')
		return (1);
	return (0);
}

static	int	cheking_last(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] != '1')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static int	cheking(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i])
	{
		if (str[i] != '1' && str[i] != '\n')
		{
			return (1);
		}
		i++;
	}
	return (0);
}

void	cheking_map(char **str)
{
	int (line), i;
	i = 1;
	line = count_line(str);
	if (cheking(str[0]) == 1 || cheking_last(str[line - 1]) == 1)
	{
		write(1, "error in map\n", 6);
		ft_error(str);
	}
	while (i < line - 1)
	{
		if (cheking_line(str[i]) == 1)
		{
			write(2, "element error\n", 14);
			ft_error(str);
		}
		i++;
	}
	if (check_elements(str) == 1)
	{
		write(2, "element error\n", 14);
		ft_error(str);
	}
}
