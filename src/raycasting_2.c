/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 14:57:37 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:08:25 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

double	ft_perp_dist(t_cam *cam)
{
	if (cam->side % 2 == 0)
		cam->perp_wall_dist = (cam->side_dist_x - cam->delta_dist_x);
	else
		cam->perp_wall_dist = (cam->side_dist_y - cam->delta_dist_y);
	if (cam->perp_wall_dist < 0.000001)
		cam->perp_wall_dist = 0.000001;
	return (cam->perp_wall_dist);
}

void	ft_v4(t_cam *cam, t_line *line)
{
	ft_perp_dist(cam);
	line->line_height = (int)((double)WIN_HEIGHT / cam->perp_wall_dist);
	line->draw_start = -(line->line_height) / 2 + WIN_HEIGHT / 2;
	if (line->draw_start < 0)
		line->draw_start = 0;
	line->draw_end = line->line_height / 2 + WIN_HEIGHT / 2;
	if (line->draw_end >= WIN_HEIGHT)
		line->draw_end = WIN_HEIGHT - 1;
}

void	ft_v5(t_game *game, t_cam *cam, t_line *line)
{
	if (cam->side % 2 == 0)
		line->wall_x = game->coord.pos_y + cam->perp_wall_dist * cam->ray_dir_y;
	else
		line->wall_x = game->coord.pos_x + cam->perp_wall_dist * cam->ray_dir_x;
	line->wall_x -= (int)(line->wall_x);
	line->tex_x = (int)(line->wall_x * (double)(TEX_WIDTH));
	if (cam->side % 2 == 0 && cam->ray_dir_x > 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
	if (cam->side % 2 == 1 && cam->ray_dir_y < 0)
		line->tex_x = TEX_WIDTH - line->tex_x - 1;
	line->step = (double)TEX_HEIGHT / line->line_height;
	line->tex_pos = (line->draw_start - WIN_HEIGHT / 2 + line->line_height / 2) \
		* line->step;
}

void	ft_v6(t_game *game, t_cam *cam, t_line *line, int x)
{
	int		y;
	int		color;

	y = line->draw_start;
	while (y < line->draw_end)
	{
		color = 0;
		line->tex_y = (int)(line->tex_pos) % TEX_HEIGHT;
		if (cam->side == 0)
			color = ft_get_pixel_color(&game->n, line->tex_x, line->tex_y);
		else if (cam->side == 1)
			color = ft_get_pixel_color(&game->w, line->tex_x, line->tex_y);
		else if (cam->side == 2)
			color = ft_get_pixel_color(&game->s, line->tex_x, line->tex_y);
		else if (cam->side == 3)
			color = ft_get_pixel_color(&game->e, line->tex_x, line->tex_y);
		else if (cam->side >= 4)
			color = ft_get_pixel_color(&game->d, line->tex_x, line->tex_y);
		ft_recolor_pixel(&game->bg, x, y, color);
		line->tex_pos += line->step;
		y++;
	}
}

void	ft_raycasting_2(t_game *game, t_cam *cam, int x)
{
	t_line	line;

	ft_v4(cam, &line);
	ft_v5(game, cam, &line);
	ft_v6(game, cam, &line, x);
}
