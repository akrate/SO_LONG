/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_event.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aoussama <aoussama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 02:33:53 by aoussama          #+#    #+#             */
/*   Updated: 2025/03/27 02:33:54 by aoussama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}			t_vars;

int	key_hook(int keycode)
{
	printf("%d\n", keycode);
	return (0);
}

int	main(void)
{
	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 640, 480, "Hello world!");
	mlx_key_hook(vars.win, key_hook, NULL);
	mlx_loop(vars.mlx);
}
