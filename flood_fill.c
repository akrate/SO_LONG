/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 01:16:33 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/03 17:16:32 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void fill(char **map,t_pos size,int x,int y)
{
    if (x < 0 || y < 0 || x >= size.x || y >= size.y)
        return;
    if (map[x][y] == '1' || map[x][y] == 'S')
        return ;
    map[x][y] = 'S';
    fill(map,size,x +1,y);
    fill(map,size,x -1,y);
    fill(map,size,x,y +1);
    fill(map,size,x,y -1);
}
void flood_fill(char **map,t_pos size,t_pos start)
{
    fill(map,size,start.x,start.y);
}