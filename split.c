/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 15:47:31 by aoussama          #+#    #+#             */
/*   Updated: 2025/02/28 22:13:32 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	count_word(const char *s)
{
	int	i;
	int	count;
	int	word;

	i = 0;
	count = 0;
	word = 0;
	while (s[i])
	{
		if (s[i] == '\n')
		{
			count = 0;
		}
		else if (count == 0)
		{
			word++;
			count = 1;
		}
		i++;
	}
	return (word);
}

static char	*str_d(const char *s, int start, int finish)
{
	char	*result;
	int		i;

	result = (char *)malloc((finish - start + 1) * sizeof(char));
	if (result == NULL)
	{
		return (NULL);
	}
	i = 0;
	while (start < finish)
	{
		result[i] = s[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}

static void	*ft_free(char **result)
{
	int	i;

	i = 0;
	while (result[i] != NULL)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return (NULL);
}

char	**ft_split(char const *s)
{
	char	**result;
	int		i;
	int		j;
	int		start;

	if (s == NULL)
		return (NULL);
	result = (char **)malloc((count_word(s) + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == '\n')
			i++;
		start = i;
		while (s[i] && s[i] != '\n')
			i++;
		if (start < i)
			result[j++] = str_d(s, start, i);
		if (result[j - 1] == NULL)
			return (ft_free(result));
	}
	return (result[j] = NULL, result);
}