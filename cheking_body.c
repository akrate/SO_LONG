/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cheking_body.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/02 16:41:51 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/02 16:42:14 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void cheking_body(char **str)
{
    int i;
    int j;
    int len;
    len = 0;
    i = 1;
    while (str[0][len] && str[0][len] != '\n')
    len++;
    while (str[i])
    {
        j = 0;
        while (str[i][j] != '\n' && str[i][j])
            j++;
        if (j != len)
        {
            write (1,"erorr\n",6);
            ft_erorr(str);
        }
        i++; 
    }
    if (i >= len)
    {
        write (1,"erorr\n",6);
        ft_erorr(str);
    }
        
}