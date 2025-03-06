/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:17:07 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/05 23:49:05 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


char **str_cpy(char **str,int x,int y)
{
    char **result;
    
    int (j), i = 0;
    result = (char **)malloc((y + 1) * sizeof(char *));
    if (result == NULL)
        return (NULL);
    while (str[i])
    {
        j = 0;
        result[i] = (char *)malloc((x + 1) * sizeof(char));
        if (result[i] ==  NULL)
        {
            ft_freee(result);
            return (NULL);
        }
        while (str[i][j])
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
    return 1;
}

int main()
{
    // int i = 0;
    // int j;
    char **str;
    char **cpy;
    t_pos size;
    t_pos start;

    start.x = 1;
    start.y = 1;
    str = read_arg("test.txt");
    size.x = cheking_body(str);
    cheking_map(str);
    size.y = count_line(str);
    cpy = str_cpy(str,size.x,size.y);
    flood_fill(cpy,size,start);
    if (chek_valid_map(cpy) == 1)
    {
        write (1,"error valid\n",11);
        ft_freee(cpy);
        ft_erorr(str);
    }
    ft_freee(cpy);
    // while (cpy[i])
    // {
    //     printf("%s",cpy[i]);
    //     i++;
    // }
    void *mlx;
    void *mnw;
    mlx = mlx_init();

    
    mnw = mlx_new_window(mlx,size.x * 32 , size.y * 32 ,"test");
    use_wall(mlx,mnw,str);
    use_background(mlx,mnw,str);
    use_player(mlx,mnw,str);
    use_coins(mlx,mnw,str);
    mlx_hook(mnw, 17, 0, button_x, NULL);
    mlx_loop(mlx);
    ft_erorr(str);

}
