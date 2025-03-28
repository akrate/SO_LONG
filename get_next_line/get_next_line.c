/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 14:08:51 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/28 21:27:11 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static char	*read_and_accimulate(int fd, char *remainder)
{
	ssize_t	read_size;
	char	*str_read;

	str_read = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str_read)
		return (NULL);
	read_size = read(fd, str_read, BUFFER_SIZE);
	while (read_size > 0)
	{
		str_read[read_size] = '\0';
		remainder = ft_strjoin(remainder, str_read);
		if (ft_strchr(remainder) != -1)
			break ;
		read_size = read(fd, str_read, BUFFER_SIZE);
	}
	if (read_size == -1)
	{
		free(str_read);
		free(remainder);
		return (NULL);
	}
	free(str_read);
	return (remainder);
}

static char	*extract_next_line(char **remainder)
{
	char	*line;

	if (!*remainder || ft_strlen(*remainder) == 0)
	{
		free(*remainder);
		*remainder = NULL;
		return (NULL);
	}
	line = get_left_line(*remainder);
	*remainder = get_right_line(*remainder);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*remainder;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	remainder = read_and_accimulate(fd, remainder);
	if (!remainder)
		return (NULL);
	return (extract_next_line(&remainder));
}
