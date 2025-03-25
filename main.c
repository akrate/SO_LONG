/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:17:07 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/25 21:31:28 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void clean(t_data *game)
{
    if(game->str)
        ft_freee(game->str);
    // free_textures(game);
    
}
char **str_cpy(char **str,int x,int y)
{
    char **result;
    
    int (j), i = 0;
    result = malloc((y + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);
    while (str[i])
    {
        j = 0;
        result[i] = (char *)malloc((x + 1) * sizeof(char));
        if (result[i] ==  NULL)
            return (ft_freee(result), NULL);
        while (j < x)
        {
            result[i][j] = str[i][j];
            j++;
        }
        result[i][j] = '\0';
        i++;
    }
    result[i] = NULL;
    return (result);
}
int chek_valid_map(char **str)
{
    int i;
    int j;
    
    i = 0;
    while (str[i])
    {
        j = 0;
        while (str[i][j] && str[i][j] != '\n')
        {
            if (str[i][j] != '1' && str[i][j] != '0' && str[i][j] != 'S')
                return (1);
            j++;
        }
        i++;
    }
    return (0);
}
int button_x()
{
    exit(0);
}

void cheking_ber(char *str)
{
    int i;
    int j;
    char *src;
    
    i = 0;
    j = 0;
    src = ".ber";
    while (str[i])
        i++;
    i--;
    while (str[i] != '.' && i > 0)
        i--;
    if(i == 0)
        exit (1);
    else 
        while (src[j])
        {
            if (src[j] != str[i])
                exit (1);
            i++;
            j++;
        }
    if (str[i] != '\0')
        exit (1);
}
p_player finde_player(char **map)
{
    p_player p;
    int y;
    int x;
    
    y = 0;
    while (map[y])
    {
        x = 0;
        while (map[y][x])
        {
            if (map[y][x] == 'P')
            {
                p.y = y;
                p.x = x;
            }
            x++;
        }
        y++;
    }
    return (p);
}
p_player finde_door(char **map)
{
    p_player p;

    p.y = 0;
    while (map[p.y])
    {
        p.x = 0;
        while (map[p.y][p.x])
        {
            if (map[p.y][p.x] == 'E')
            {
                return (p);
            }
            p.x++;
        }
        p.y++;
    }
    return (p);
}
int prints(int event)
{
    printf("%d\n",event);
    return (1);
}

void init_game(t_data *game)
{
    game->mlx = NULL;
    game->mnw = NULL;
    game->str =   NULL;
    game->collectbles = 0;
    game->mv = 0;
}
int main(int ac,char **av)
{
    if (ac != 2)
        return (1);
    cheking_ber(av[1]);
    t_data game;
    char **cpy;
    t_pos size;
    p_player player_pos;

    // init_game(&game);
    game.str = read_arg(av[1]);
    size.x = cheking_body(game.str);
    cheking_map(game.str);
    size.y = count_line(game.str);
    cpy = str_cpy(game.str,size.x,size.y);
    player_pos = finde_player(cpy);
    flood_fill(cpy,size,player_pos);
    if (chek_valid_map(cpy) == 1)
    {
        write (1,"error valid\n",11);
        ft_freee(cpy);
        ft_erorr(game.str);
    }
    ft_freee(cpy);
    game.mlx = mlx_init();
    game.mnw = mlx_new_window(game.mlx,size.x * 32 , size.y * 32 ,"test");
    game.collectbles = count_collectbles(game.str);
    game.door = finde_door(game.str);
    game.mv = 0;
    use_elmnets(&game);
    mlx_hook(game.mnw, 17, 0, button_x, NULL);
    mlx_key_hook(game.mnw, movement, &game);
    mlx_loop(game.mlx);
    ft_erorr(game.str);

}
