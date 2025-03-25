/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:11:05 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/25 21:30:58 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG
# define SO_LONG

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"

# define A 97
# define W 119
# define D 100
# define S 115
# define ECS 65307
typedef struct flood{
    int x;
    int y;
}   t_pos;
typedef struct player{
    int x;
    int y;
} p_player;
typedef struct s_data{
    void *mlx;
    void *mnw;
    char **str;
    int collectbles;
    int mv;
    void *img;
    p_player door;
    
}   t_data;

// _________________get_next_line______________
char	*get_next_line(int fd);
int		ft_strchr(char *str);
char	*ft_strjoin(char *str1, char *str2);
char	*get_left_line(char *str);
char	*get_right_line(char *str);

int		ft_strlen(char *str);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
#endif
// ______________________________________________
char **read_arg(char *src);
int cheking_body(char **str);
void ft_erorr(char **str);
void cheking_map(char **str);
void cheking_map(char **str);
void flood_fill(char **map,t_pos size,p_player start);
int count_line(char **str);
void ft_freee(char **str);
// void use_wall(void *mlx,void *mnw,char **str);
// void use_background(void *mlx,void *mnw,char **str);
// void use_player(void *mlx,void *mnw,char **str);
// void use_coins(void *mlx,void *mnw,char **str);
////////////////////////////////////////////////////////
p_player finde_player(char **map);
void use_elmnets(t_data *game);
int movement(int event,t_data *game);
int chek_move(char c);
int count_collectbles(char **str);
int chek_collecteble(char c);
int chek_exit(char c);
p_player finde_door(char **map);
// void use_door(void *mlx,void *mnw,char **str);

#endif