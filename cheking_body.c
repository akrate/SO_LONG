/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:41:51 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/28 02:07:45 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cheking_body(char **str)
{
	int (i), j, len;
	len = 0;
	i = 1;
	while (str[0][len] && str[0][len] != '\n')
		len++;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != '\n' && str[i][j])
			j++;
		if (j != len)
		{
			write(1, "erorr\nin map:(\n", 16);
			ft_error(str);
		}
		i++;
	}
	return (len);
}

static void	error_name(void)
{
	write(2, "Error\nFile extension must be .ber or name too short\n", 53);
	exit(1);
}

void	cheking_ber(char *str)
{
	char	*src;

	int (i), j = 0;
	i = 0;
	src = ".ber";
	while (str[i])
		i++;
	i--;
	while (str[i] != '.' && i > 0)
		i--;
	if (i == 0 || str[i - 1] == '/')
		error_name();
	else
	{
		while (src[j])
		{
			if (src[j] != str[i])
				error_name();
			i++;
			j++;
		}
	}
	if (str[i] != '\0')
		error_name();
}
