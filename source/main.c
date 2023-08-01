/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:39:04 by lamici            #+#    #+#             */
/*   Updated: 2023/08/01 11:35:41 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	main(int ac, char **av)
{
	t_game	w;
	char *mat[] =
	{
		"1111111111111",
		"1000100000101",
		"1000100000111",
		"1000100000001",
		"1000000000001",
		"1000000001001",
		"1000000000001",
		"1111111111111",
		0
	};
	w.map = mat;
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1920, 1080, "cub3D");
	ft_init_coord(&w.pos);
	ft_init_boi(&w);
	//mlx_loop_hook(w.mlx, &ft_put_map, &w);
	mlx_hook(w.win, 2, 1L << 0, ft_deal_key, &w);
	mlx_hook(w.win, 17, 0, ft_close, &w);
	mlx_loop(w.mlx);
}
// color for yellow 0xFFFF00