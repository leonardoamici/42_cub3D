/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_1_p2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 17:18:23 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:20:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_v1(t_game *game, t_cam *cam, int x);
void	ft_v2(t_game *game, t_cam *cam);

int	ft_hit_check(t_game *game, t_cam *cam, int mode)
{
	int	hit;

	hit = 0;
	if (mode)
	{
		if (game->map[cam->map_x][cam->map_y] == '1')
			hit = 1;
		else if (game->map[cam->map_x][cam->map_y] == 'D' || \
			game->map[cam->map_x][cam->map_y] == 'd')
		{
			hit = 2;
			cam->side += 4;
		}
	}
	else if (!mode)
	{
		if (game->map[cam->map_x][cam->map_y] == '1')
			hit = 1;
		else if (game->map[cam->map_x][cam->map_y] == 'D')
		{
			hit = 1;
			cam->side += 4;
		}
	}
	return (hit);
}

int	ft_v3_2(t_game *game, t_cam *cam)
{
	int	hit;

	hit = 0;
	while (!hit)
	{
		if (cam->side_dist_x < cam->side_dist_y)
		{
			cam->side_dist_x += cam->delta_dist_x;
			cam->map_x += cam->step_x;
			cam->side = 1 + cam->step_x;
		}
		else
		{
			cam->side_dist_y += cam->delta_dist_y;
			cam->map_y += cam->step_y;
			cam->side = 2 + cam->step_y;
		}
		if (cam->map_x >= game->map_height || cam->map_y >= game->map_width \
			|| cam->map_x < 0 || cam->map_y < 0)
			break ;
		hit = ft_hit_check(game, cam, 1);
	}
	return (hit);
}

void	ft_door_raycasting(t_game *game)
{
	t_cam	cam;

	ft_v1(game, &cam, WIN_WIDTH / 2);
	ft_v2(game, &cam);
	if (ft_v3_2(game, &cam) == 2 && ft_perp_dist(&cam) < 1.5)
	{
		game->door_x = cam.map_x;
		game->door_y = cam.map_y;
		game->i_c_door = 1;
	}
	else
		game->i_c_door = 0;
}
