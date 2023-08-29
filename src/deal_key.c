/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/02 09:27:34 by abettini          #+#    #+#             */
/*   Updated: 2023/08/29 16:07:16 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_close(t_game *game);

/* void	ft_reset_angle(t_game *game)
{
	game->coord.dir_x = -1;
	game->coord.dir_y = 0;
	game->coord.plane_x = 0;
	game->coord.plane_y = FOV;
} */
	//else if (key == ARR_UP)
	//	ft_reset_angle(game);

void	ft_open_door(t_game *game)
{
	if (game->i_c_door && (game->map[game->door_x][game->door_y] == 'D'))
		game->map[game->door_x][game->door_y] = 'd';
	else if (game->i_c_door && (game->map[game->door_x][game->door_y] == 'd'))
		game->map[game->door_x][game->door_y] = 'D';
}

int	ft_deal_key(int key, t_game *game)
{
	game->event = 1;
	if (key == ESC)
		ft_close(game);
	else if (key == KEY_W)
		game->keys_pressed |= UP_P;
	else if (key == KEY_S)
		game->keys_pressed |= DOWN_P;
	else if (key == KEY_A)
		game->keys_pressed |= LEFT_P;
	else if (key == KEY_D)
		game->keys_pressed |= RIGHT_P;
	else if (key == ARR_LEFT)
		game->keys_pressed |= ROT_L_P;
	else if (key == ARR_RIGHT)
		game->keys_pressed |= ROT_R_P;
	return (0);
}

int	ft_release_key(int key, t_game *game)
{
	game->event = 1;
	if (key == KEY_W)
		game->keys_pressed &= ~UP_P;
	else if (key == KEY_S)
		game->keys_pressed &= ~DOWN_P;
	else if (key == KEY_A)
		game->keys_pressed &= ~LEFT_P;
	else if (key == KEY_D)
		game->keys_pressed &= ~RIGHT_P;
	else if (key == ARR_LEFT)
		game->keys_pressed &= ~ROT_L_P;
	else if (key == ARR_RIGHT)
		game->keys_pressed &= ~ROT_R_P;
	else if (key == KEY_TAB)
		game->minimap ^= 1;
	else if (key == KEY_E)
		ft_open_door(game);
	return (0);
}

int	ft_loop(t_game *game)
{
	mlx_mouse_get_pos(game->mlx, game->win.ptr, &game->mouse_x, &game->mouse_y);
	mlx_mouse_hide(game->mlx, game->win.ptr);
	if (game->keys_pressed & UP_P)
		ft_key_move_up(game);
	if (game->keys_pressed & DOWN_P)
		ft_key_move_down(game);
	if (game->keys_pressed & LEFT_P)
		ft_key_move_left(game);
	if (game->keys_pressed & RIGHT_P)
		ft_key_move_right(game);
	if (game->keys_pressed & ROT_L_P || game->mouse_x < WIN_WIDTH / 2)
		ft_key_rotate_left(game);
	if (game->keys_pressed & ROT_R_P || game->mouse_x > WIN_WIDTH / 2)
		ft_key_rotate_right(game);
	ft_new_bg(game);
	game->event = 0;
	return (0);
}
//if (!game->event && !game->keys_pressed)
//	return (1);
