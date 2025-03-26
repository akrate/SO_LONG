/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:17:07 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/26 02:08:09 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
void    free_images(t_data *game)
{
    if (!game->mlx || !game->mnw)
        return ;
    if (game->wall)
        mlx_destroy_image(game->mlx, game->wall);
    if (game->player)
        mlx_destroy_image(game->mlx, game->player);
    if (game->coin)
        mlx_destroy_image(game->mlx, game->coin);
    if (game->back)
        mlx_destroy_image(game->mlx, game->back);
    if (game->exit)
        mlx_destroy_image(game->mlx, game->exit);
}
void clean(t_data *game)
{
    free_images(game);
    if(game->str)
        ft_freee(game->str);
    if (game->mlx && game->mnw)
        mlx_destroy_window(game->mlx ,game->mnw);
    if (game->mlx)
    {
        mlx_destroy_display(game->mlx);
        free(game->mlx);
    }
    
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
int button_x(t_data *game)
{
    clean(game);
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
    game->back =  NULL;
    game->coin =  NULL;
    game->wall = NULL;
    game->exit =  NULL;
    game->player =  NULL;
    game->door.x = 0;
    game->door.y =  0;    
}
p_player get_size(t_data *game)
{
    p_player size;
    
    size.x = cheking_body(game->str);
    size.y = count_line(game->str);

    return (size);
}
int main(int ac,char **av)
{
    t_data game;
    char **cpy;
    
    if (ac != 2)
        return (1); 
    cheking_ber(av[1]);
    init_game(&game);
    game.str = read_arg(av[1]);
    cheking_map(game.str);
    game.size = get_size(&game);
    cpy = str_cpy(game.str,game.size.x,game.size.y);
    game.pos_player = finde_player(cpy);
    flood_fill(cpy,game.size,game.pos_player);
    if (chek_valid_map(cpy) == 1)
    {
        write (1,"error valid\n",11);
        ft_freee(cpy);
        ft_erorr(game.str);
    }
    ft_freee(cpy);
    game.mlx = mlx_init();
    if (!game.mlx)
    {
        clean(&game);
        exit(1);
    }
    game.mnw = mlx_new_window(game.mlx, game.size.x * 32 , game.size.y * 32 ,"test");
    if (!game.mnw)
    {
        clean(&game);
        exit(1);
    }
    game.collectbles = count_collectbles(game.str);
    game.door = finde_door(game.str);
    use_elmnets(&game);
    mlx_key_hook(game.mnw, movement, &game);
    mlx_hook(game.mnw, 17, 0, button_x, &game);
    mlx_loop(game.mlx);
    // clean(&game);
}
