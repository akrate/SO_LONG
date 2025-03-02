/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 20:17:07 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/02 16:46:51 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"













int main()
{
    char **str;

    str = read_arg("test.txt");
    cheking_body(str);
    cheking_map(str);
    ft_erorr(str);

}
