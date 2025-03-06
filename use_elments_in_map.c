/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_elments_in_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/05 21:03:06 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/05 23:48:34 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void use_wall(void *mlx,void *mnw,char **str)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
        void *img = mlx_xpm_file_to_image(mlx,"wall.xpm",&w,&h);
        while (str[i])
        {
            j = 0;
            while (str[i][j])
            {
                if (str[i][j] == '1')
                {
                    mlx_put_image_to_window(mlx,mnw,img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_background(void *mlx,void *mnw,char **str)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
        void *img = mlx_xpm_file_to_image(mlx,"water2.xpm",&w,&h);
        while (str[i])
        {
            j = 0;
            while (str[i][j])
            {
                if (str[i][j] == '0')
                {
                    mlx_put_image_to_window(mlx,mnw,img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_player(void *mlx,void *mnw,char **str)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
        void *img = mlx_xpm_file_to_image(mlx,"player.xpm",&w,&h);
        while (str[i])
        {
            j = 0;
            while (str[i][j])
            {
                if (str[i][j] == 'P')
                {
                    mlx_put_image_to_window(mlx,mnw,img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}
void use_coins(void *mlx,void *mnw,char **str)
{
    int i;
    int j;
    int w = 0,h = 0;
    i = 0;
        void *img = mlx_xpm_file_to_image(mlx,"fish2.xpm",&w,&h);
        while (str[i])
        {
            j = 0;
            while (str[i][j])
            {
                if (str[i][j] == 'C')
                {
                    mlx_put_image_to_window(mlx,mnw,img,j * 32,i * 32);
                }
                j++;
            }
            i++;
        }
}