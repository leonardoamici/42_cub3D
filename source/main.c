/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:39:04 by lamici            #+#    #+#             */
/*   Updated: 2023/07/26 16:04:13 by lamici           ###   ########.fr       */
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
	mlx_put_image_to_window(w->mlx, w->win, w->imgs.death, w->imgs.old_x, w->imgs.old_y);
	mlx_put_image_to_window(w->mlx, w->win, w->imgs.boi, w->imgs.x, w->imgs.y);
}
int	deal_key(int key, t_game *w)
{
	if (key == 65307)
		ft_close(w);
	else if (key == 'w' || key == 65362)
	{
		w->imgs.old_y = w->imgs.y;
		w->imgs.old_x = w->imgs.x;
		w->imgs.y -= 10;
	}
	else if (key == 'a' || key == 65361)
	{
		w->imgs.old_x = w->imgs.x;
		w->imgs.old_y = w->imgs.y;
		w->imgs.x -= 10;
	}
	else if (key == 's' || key == 65364)
	{
		w->imgs.old_y = w->imgs.y;
		w->imgs.old_x = w->imgs.x;
		w->imgs.y += 10;
	}
	else if (key == 'd' || key == 65363)
	{
		w->imgs.old_x = w->imgs.x;
		w->imgs.old_y = w->imgs.y;
		w->imgs.x += 10;
	}
	ft_draw_my_boy(w);
	return (0);
}

void	ft_put_square(t_game *w, int mx, int my)
{
	int		y;
	int		x;

	y = 0;
	my = (my * 64) + my * 2;
	mx = (mx * 64) + mx * 2;
	while(y < 64)
	{
		x = 0;
		while(x < 64)
		{
			mlx_pixel_put(w->mlx, w->win, mx + x, my + y, 0xFF0000);
			x++;
		}
		y++;
	}
}
void	ft_put_map(char **map, t_game *w)
{
	int		my;
	int		mx;

	my = 0;
	while(map[my])
	{
		mx = 0;
		while(map[my][mx])
		{
			if(map[my][mx] == '1')
				ft_put_square(w, mx, my);
			mx++;
		}
		my++;
	}
}

void ft_init_boi(t_game *w)
{
	int a;

	a = 0;
	w->imgs.x = 300;
	w->imgs.y = 300;
	w->imgs.old_x = 300;
	w->imgs.old_y = 300;
	w->imgs.boi = mlx_xpm_file_to_image(w->mlx, "img/boi.xpm", &a, &a);
	w->imgs.death = mlx_xpm_file_to_image(w->mlx, "img/death.xpm", &a, &a);
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
	w.mlx = mlx_init();
	w.win = mlx_new_window(w.mlx, 1920, 1080, "cub3D");
	ft_put_map(mat, &w);
	ft_init_boi(&w);
	mlx_hook(w.win, 2, 1L << 0, deal_key, &w);
	mlx_hook(w.win, 17, 0, ft_close, &w);
	mlx_loop(w.mlx);
}
