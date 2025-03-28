/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:40:00 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/28 00:23:54 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_arg(const char *src)
{
	int		f;
	int		i;
	char	*str;

	f = open(src, O_RDONLY);
	if (f == -1)
	{
		write(2, "error\nwe did not find this map :(\n", 35);
		exit(1);
	}
	i = 0;
	str = get_next_line(f);
	while (str != NULL)
	{
		i++;
		free(str);
		str = get_next_line(f);
	}
	close(f);
	if (i == 0)
	{
		write(2, "error\nwe did not find this map :(\n", 35);
		exit(1);
	}
	return (i);
}

char	**read_arg(char *src)
{
	char	**str;

	int (i), fd;
	i = 0;
	fd = open(src, O_RDONLY);
	if (fd == -1)
	{
		write(2, "error\nwe did not find this map :(\n", 35);
		exit(1);
	}
	str = (char **)malloc((count_arg(src) + 1) * sizeof(char *));
	if (str == NULL)
	{
		write(2, "error\nerror in malloc", 22);
		exit(1);
	}
	str[i] = get_next_line(fd);
	while (str[i] != NULL)
	{
		i++;
		str[i] = get_next_line(fd);
	}
	close(fd);
	return (str);
}
