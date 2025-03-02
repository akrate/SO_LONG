/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:11:05 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/02 16:47:14 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef SO_LONG
# define SO_LONG

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
# include <fcntl.h>
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
void cheking_body(char **str);
void ft_erorr(char **str);
void cheking_map(char **str);
void cheking_map(char **str);

#endif