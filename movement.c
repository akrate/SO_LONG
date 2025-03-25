/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 19:46:41 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/25 21:29:42 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void move_to_left(t_data *data)
{
    p_player pos;
    
    pos = finde_player(data->str);
   
    if (chek_collecteble(data->str[pos.y][pos.x - 1]) == 1)
    {
        data->collectbles = data->collectbles - 1; 
        printf("collce = %d\n",data->collectbles);
    }
    if (chek_move(data->str[pos.y][pos.x - 1]) == 0)
    {
        if (chek_exit(data->str[pos.y][pos.x - 1]) == 1 && data->collectbles == 0)
        {
            exit (1);
        }else
        {
            data->str[pos.y][pos.x] = '0';
            data->str[pos.y][pos.x - 1] = 'P';
        }
    }
    
}

void move_to_right(t_data *data)
{
    p_player pos;
    
    pos = finde_player(data->str);
    if (chek_collecteble(data->str[pos.y][pos.x + 1]) == 1)
    {
        data->collectbles = data->collectbles - 1; 
        printf("collce = %d\n",data->collectbles);
    }
    if (chek_move(data->str[pos.y][pos.x + 1]) == 0)
    {
        if (data->str[data->door.y][data->door.x] != 'P' && data->str[data->door.y][data->door.x] != 'E' )
        {
            data->str[data->door.y][data->door.x] = 'E';
        }
        if (chek_exit(data->str[pos.y][pos.x + 1]) == 1 && data->collectbles == 0)
        {
            exit (1);
        }else {
            
            data->str[pos.y][pos.x] = '0';
            data->str[pos.y][pos.x + 1] = 'P';
        }
    }
}

void move_tao_top(t_data *data)
{
    p_player pos;
    
    pos = finde_player(data->str);
   
    if (chek_collecteble(data->str[pos.y - 1][pos.x]) == 1)
    {
        data->collectbles = data->collectbles - 1; 
        printf("collce = %d\n",data->collectbles);
    }
    if (chek_move(data->str[pos.y - 1][pos.x]) == 0)
    {
        if (chek_exit(data->str[pos.y - 1][pos.x]) == 1 && data->collectbles == 0)
        {
            exit (1);
        }else
        {
            data->str[pos.y][pos.x] = '0';
            data->str[pos.y - 1][pos.x] = 'P';
        }
    }
}

void move_to_bottom(t_data *data)
{
    p_player pos;
    
    pos = finde_player(data->str);
    
    if (chek_collecteble(data->str[pos.y + 1][pos.x]) == 1)
    {
        data->collectbles = data->collectbles - 1; 
        printf("collce = %d\n",data->collectbles);
    }
    if (chek_move(data->str[pos.y + 1][pos.x]) == 0)
    {
        if (chek_exit(data->str[pos.y + 1][pos.x]) == 1 && data->collectbles == 0)
        {
            
            exit (1);
        }else{
            
            
            data->str[pos.y][pos.x] = '0';
            data->str[pos.y + 1][pos.x] = 'P';
        }
    }
}
int movement(int event,t_data *game)
{
    
    if (event == W)
    {
        move_tao_top(game);
    }else if (event == A) 
    {
        move_to_left(game);
    }else if (event == S)
    {
        move_to_bottom(game);
    }else if (event == D)
    {
        move_to_right(game);
    }
    if (game->str[game->door.y][game->door.x] != 'P' && game->str[game->door.y][game->door.x] != 'E' )
    {
        game->str[game->door.y][game->door.x] = 'E';
    }
    use_elmnets(game);
    printf("move = %d\n",game->mv);
    game->mv++;
    return (0);
}