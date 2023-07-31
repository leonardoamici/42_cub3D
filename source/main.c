/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:39:04 by lamici            #+#    #+#             */
/*   Updated: 2023/07/31 17:28:59 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(t_game *w)
{
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(0);
}

static void	ft_draw_my_boy(t_game *w)
{
	//mlx_put_image_to_window(w->mlx, w->win, w->imgs.death, w->pos.old_px, w->pos.old_py);
	//mlx_put_image_to_window(w->mlx, w->win, w->imgs.boi, w->pos.px, w->pos.py);
	mlx_pixel_put(w->mlx, w->win, w->pos.old_px, w->pos.old_py, 0x000000);
	mlx_pixel_put(w->mlx, w->win, w->pos.px, w->pos.py, 0xFFFFFF);
}
int	deal_key(int key, t_game *w)
{
	if (key == ESC)
		ft_close(w);
	else if (key == 'w')
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
	else if (key == LEFT_ARROW)
	{
		w->pos.pa += 0.1;
		if(w->pos.pa > PI * 2)
			w->pos.pa -= PI * 2;
		w->pos.pdx = cos(w->pos.pa) * 5;
		w->pos.pdy = sin(w->pos.pa) * 5;
	}
	else if (key == RIGHT_ARROW)
	{
		w->pos.pa -= 0.1;
		if(w->pos.pa < 0)
			w->pos.pa += PI * 2;
		w->pos.pdx = cos(w->pos.pa) * 5;
		w->pos.pdy = sin(w->pos.pa) * 5;
	}
	return (0);
}


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
int	ft_put_map(t_game *w)
{
	int		my;
	int		mx;

	my = 0;
	ft_put_lines(w);
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
	return (0);
}

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
	mlx_loop_hook(w.mlx, &ft_put_map, &w);
	mlx_hook(w.win, 2, 1L << 0, deal_key, &w);
	mlx_hook(w.win, 17, 0, ft_close, &w);
	mlx_loop(w.mlx);
}
