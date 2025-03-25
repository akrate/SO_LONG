/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_elments_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:03:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/25 21:32:14 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void use_door(t_data *game)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
        game->img = mlx_xpm_file_to_image(game->mlx,"textures/wall.xpm",&w,&h);
        while (game->str[i])
        {
            j = 0;
            while (game->str[i][j])
            {
                if (game->str[i][j] == 'E')
                {
                    mlx_put_image_to_window(game->mlx,game->mnw,game->img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_wall(t_data *game)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
    game->img = mlx_xpm_file_to_image(game->mlx,"textures/wall.xpm",&w,&h);
        while (game->str[i])
        {
            j = 0;
            while (game->str[i][j])
            {
                if (game->str[i][j] == '1')
                {
                    mlx_put_image_to_window(game->mlx,game->mnw,game->img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_background(t_data *game)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
    game->img = mlx_xpm_file_to_image(game->mlx,"textures/water2.xpm",&w,&h);
        while (game->str[i])
        {
            j = 0;
            while (game->str[i][j])
            {
                if (game->str[i][j] == '0')
                {
                    mlx_put_image_to_window(game->mlx,game->mnw,game->img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_player(t_data *game)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
    game->img = mlx_xpm_file_to_image(game->mlx,"textures/player.xpm",&w,&h);
        while (game->str[i])
        {
            j = 0;
            while (game->str[i][j])
            {
                if (game->str[i][j] == 'P')
                {
                    mlx_put_image_to_window(game->mlx,game->mnw,game->img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_coins(t_data *game)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
    game->img = mlx_xpm_file_to_image(game->mlx,"textures/fish2.xpm",&w,&h);
        while (game->str[i])
        {
            j = 0;
            while (game->str[i][j])
            {
                if (game->str[i][j] == 'C')
                {
                    mlx_put_image_to_window(game->mlx,game->mnw,game->img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_elmnets(t_data *game)
{
    use_wall(game);
    use_background(game);
    use_player(game);
    use_coins(game);
    use_door(game);
}