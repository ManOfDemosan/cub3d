/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehwkim <jaehwkim@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 14:26:41 by jaehwkim          #+#    #+#             */
/*   Updated: 2022/10/25 11:10:57 by jaehwkim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"
#include "../mlx/mlx.h"

int	main(int ac, char **av)
{
	t_game	game;

	check_arguments(ac, av);
	init_all(&game);
	read_map(av[1], &game);
	init_mlx(&game);
	game.screen->img_ptr = mlx_new_image(game.mlx->mlx_ptr, WIN_W, WIN_H);
	mlx_hook(game.mlx->win_ptr, X_EVENT_KEY_PRESS, 0, &deal_key, &game);
	mlx_hook(game.mlx->win_ptr, X_EVENT_KEY_EXIT, 0, &ft_close, &game);
	mlx_loop_hook(game.mlx->mlx_ptr, &main_loop, &game);
	mlx_loop(game.mlx->mlx_ptr);
	return (0);
}
