/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chek_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 00:04:19 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/25 01:15:23 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int chek_move(char c)
{
    if (c == '1')
        return (1);
    else
        return (0);
}
int chek_exit(char c)
{
    if (c == 'E')
        return (1);
    else
        return (0);
}
int chek_collecteble(char c)
{
    if (c == 'C')
    return (1);
else
    return (0);
}
int count_collectbles(char **str)
{
    int i;
    int j;
    int count;

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