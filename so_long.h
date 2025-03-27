/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:11:05 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 03:03:23 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define A 97
# define W 119
# define D 100
# define S 115
# define ECS 65307
# define TOP 65362
# define BOTTOM 65364
# define LEFT 65361
# define RIGHT 65363

typedef struct s_player
{
	int			x;
	int			y;
}				t_player;
typedef struct img
{
	void		*wall;
	void		*coin;
	void		*player;
	void		*exit;
	void		*back;
}				t_elments;

typedef struct s_data
{
	void		*mlx;
	void		*mnw;
	char		**str;
	int			collectbles;
	int			mv;
	t_player	door;
	t_player	pos_player;
	t_player	size;
	t_elments	img;
}				t_data;

char			*get_next_line(int fd);
int				ft_strchr(char *str);
char			*ft_strjoin(char *str1, char *str2);
char			*get_left_line(char *str);
char			*get_right_line(char *str);
int				ft_strlen(char *str);
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

int				count_line(char **str);
int				cheking_body(char **str);
int				movement(int event, t_data *game);
int				chek_move(char c);
int				count_collectbles(char **str);
int				chek_collecteble(char c);
int				chek_exit(char c);
char			**read_arg(char *src);
void			ft_error(char **str);
void			cheking_map(char **str);
void			flood_fill(t_data *game);
void			ft_freee(char **str);
void			cheking_ber(char *str);
void			use_elmnets(t_data *game);
void			clean(t_data *game, int i);
void			free_images(t_data *game);
void			ecs(t_data *game);
void			move_to_bottom(t_data *data);
void			move_tao_top(t_data *data);
void			move_to_right(t_data *data);
void			move_to_left(t_data *data);
void			print(int move);
t_player		finde_player(char **map);
t_player		finde_door(char **map);
t_player		get_size(t_data *game);
#endif
