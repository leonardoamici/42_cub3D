/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 11:36:10 by abettini          #+#    #+#             */
/*   Updated: 2023/08/29 16:07:40 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_key_rotate_left(t_game *game)
{
	game->coord.old_dir_x = game->coord.dir_x;
	game->coord.dir_x = game->coord.dir_x * cos(SPEED_ROT) - \
		game->coord.dir_y * sin(SPEED_ROT);
	game->coord.dir_y = game->coord.old_dir_x * sin(SPEED_ROT) + \
		game->coord.dir_y * cos(SPEED_ROT);
	game->coord.old_plane_x = game->coord.plane_x;
	game->coord.plane_x = game->coord.plane_x * cos(SPEED_ROT) - \
		game->coord.plane_y * sin(SPEED_ROT);
	game->coord.plane_y = game->coord.old_plane_x * sin(SPEED_ROT) + \
		game->coord.plane_y * cos(SPEED_ROT);
	mlx_mouse_move(game->mlx, game->win.ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}

void	ft_key_rotate_right(t_game *game)
{
	game->coord.old_dir_x = game->coord.dir_x;
	game->coord.dir_x = game->coord.dir_x * cos(-SPEED_ROT) - \
		game->coord.dir_y * sin(-SPEED_ROT);
	game->coord.dir_y = game->coord.old_dir_x * sin(-SPEED_ROT) + \
		game->coord.dir_y * cos(-SPEED_ROT);
	game->coord.old_plane_x = game->coord.plane_x;
	game->coord.plane_x = game->coord.plane_x * cos(-SPEED_ROT) - \
		game->coord.plane_y * sin(-SPEED_ROT);
	game->coord.plane_y = game->coord.old_plane_x * sin(-SPEED_ROT) + \
		game->coord.plane_y * cos(-SPEED_ROT);
	mlx_mouse_move(game->mlx, game->win.ptr, WIN_WIDTH / 2, WIN_HEIGHT / 2);
}
