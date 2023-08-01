/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_managing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:25:38 by lamici            #+#    #+#             */
/*   Updated: 2023/08/01 16:41:44 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_init_boi(t_game *w)
{
	int a;

	a = 0;
	w->imgs.boi = mlx_xpm_file_to_image(w->mlx, "img/boi.xpm", &a, &a);
	w->imgs.death = mlx_xpm_file_to_image(w->mlx, "img/death.xpm", &a, &a);
}
void ft_init_coord(t_coord *pos)
{
	pos->pa = PI / 2 + PI;
	pos->pdx = cos(pos->pa) * 5;
	pos->pdy = sin(pos->pa) * 5;
	pos->py = 300;
	pos->px = 300;
	pos->old_px = pos->px; 
	pos->old_py = pos->py;
}
void	ft_first_ray(t_game *w)
{
	float	atan;
	float	rx;
	float	ry;
	float	xo;
	float	yo;
	int		r,mx,my,dof = 0;

	atan = -1 / tan(w->pos.pa);
	if (w->pos.pa == 0 || w->pos.pa == PI)
	{
		rx = w->pos.px;
		ry = w->pos.py;
	}
	else if (w->pos.pa < PI)
	{
		ry = ((int)w->pos.py / 64) * 64 - 0.0001;
		rx = (w->pos.py - ry) * atan + w->pos.px;
		yo = -64;
		xo = -yo * atan;
	}
	else if (w->pos.pa > PI)
	{
		ry = ((int)w->pos.py / 64) * 64 + 64;
		rx = (w->pos.py - ry) * atan + w->pos.px;
		yo = 64;
		xo = -yo * atan;
	}
	while (dof < 8)
	{
		mx = (int)rx / 64;
		my = (int)ry / 64;
		if ((my < 8 && mx < 8) && w->map[my][mx] == '1')
			dof = 8;
		else
		{
			rx += xo;
			ry += yo;
			dof += 1;
		}
	}
}

int	ft_deal_key(int key, t_game *w)
{
	if (key == ESC)
		ft_close(w);
	ft_delete_my_boy(w);
	if (key == 'w')
	{
		w->pos.old_py = w->pos.py;
		w->pos.old_px = w->pos.px;
		w->pos.py += w->pos.pdy;
		w->pos.px += w->pos.pdx;
	}
	else if (key == 's')
	{
		w->pos.old_py = w->pos.py;
		w->pos.old_px = w->pos.px;
		w->pos.py -= w->pos.pdy;
		w->pos.px -= w->pos.pdx;
	}
	else if (key == 'a')
	{
		w->pos.old_py = w->pos.py;
		w->pos.old_px = w->pos.px;
		w->pos.py -= w->pos.pdx;
		w->pos.px += w->pos.pdy;
	}
	else if (key == 'd')
	{
		w->pos.old_py = w->pos.py;
		w->pos.old_px = w->pos.px;
		w->pos.py += w->pos.pdx;
		w->pos.px -= w->pos.pdy;
	}
	if (key == LEFT_ARROW)
	{
		w->pos.pa -= 0.1;
		if(w->pos.pa < 0)
			w->pos.pa += PI * 2;
		w->pos.pdx = cos(w->pos.pa) * 5;
		w->pos.pdy = sin(w->pos.pa) * 5;
	}
	else if (key == RIGHT_ARROW)
	{
		w->pos.pa += 0.1;
		if(w->pos.pa > PI * 2)
			w->pos.pa -= PI * 2;
		w->pos.pdx = cos(w->pos.pa) * 5;
		w->pos.pdy = sin(w->pos.pa) * 5;
	}
	ft_put_map(w);
	return (0);
}