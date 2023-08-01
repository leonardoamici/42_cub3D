/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_board.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:20:59 by lamici            #+#    #+#             */
/*   Updated: 2023/08/01 11:25:00 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_lines(t_game *w)
{
	int	x;
	int y;
	int	mx;
	int my;

	y = 0;
	while(y < ft_matlen(w->map) + 1)	
	{
		mx = 0;
		while(mx < ft_strlen(w->map[0]) * 64 + ft_strlen(w->map[0]))
		{
			mlx_pixel_put(w->mlx, w->win, mx, y * 64 + y, 0xFFFFFF);
			mx++;
		}
		y++;
	}
	while(x < ft_strlen(w->map[0]) + 1)
	{
		my = 0;
		while(my < ft_matlen(w->map) * 64 + ft_matlen(w->map))
		{
			mlx_pixel_put(w->mlx, w->win, x * 64 + x, my, 0xFFFFFF);
			my++;
		}
		x++;
	}
}

void	ft_put_square(t_game *w, int mx, int my)
{
	int		x;
	int		y;
	int new_mx;
	int new_my;

	y = 0;
	new_my = (my * 64) + my;
	new_mx = (mx * 64) + mx;
	while(y < 64)
	{
		x = 0;
		while(x < 64)
		{
			mlx_pixel_put(w->mlx, w->win, new_mx + (x + 1), new_my + (y + 1), 0xAA5999);
			x++;
		}
		y++;
	}
}

void	ft_put_pipo(t_game *w, int color)
{
	float	it;

	it = 0.1;
	while(it < 50.0)
	{
		mlx_pixel_put(w->mlx, w->win, w->pos.px + 7 + w->pos.pdx * it, w->pos.py + 7 + w->pos.pdy * it, color);
		it += 0.2;
	}
}

static void	ft_draw_my_boy(t_game *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->imgs.boi, w->pos.px, w->pos.py);
}

int	ft_put_map(t_game *w)
{
	int		my;
	int		mx;

	my = 0;
	while(w->map[my])
	{
		mx = 0;
		while(w->map[my][mx])
		{
			if(w->map[my][mx] == '1')
				ft_put_square(w, mx, my);
			mx++;
		}
		my++;
	}
	ft_draw_my_boy(w);
	ft_put_pipo(w, 0xFFFF00);
	ft_put_lines(w);
	return (0);
}