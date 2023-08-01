/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:41:03 by lamici            #+#    #+#             */
/*   Updated: 2023/08/01 11:37:07 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# define DEBUG printf("ciao\n")
# define PI 3.1415926535
# define RIGHT_ARROW 65363
# define LEFT_ARROW 65361
# define ESC 65307

typedef	struct s_image
{
	void	*img;
	int		height;
	int		width;
}	t_image;


typedef struct	s_boi
{
	void *boi;
	void *death;
}				t_boi;

typedef struct	s_coord
{
	float pa;
	float pdx;
	float pdy;
	float px;
	float py;
	float old_px;
	float old_py;
}				t_coord;

typedef struct	s_game
{
	t_image	n;
	t_image	s;
	t_image	w;
	t_image	e;
	t_boi	imgs;
	t_coord	pos;
	void	*win;
	void	*mlx;
	char	*ceiling;
	char	*floor;
	char	**map;
}				t_game;

int		ft_deal_key(int key, t_game *w);
int		ft_put_map(t_game *w);
void 	ft_init_coord(t_coord *pos);
int		ft_close(t_game *w);
void	ft_delete_my_boy(t_game *w);
void	ft_init_coord(t_coord *pos);
void	ft_init_boi(t_game *w);
void	ft_put_pipo(t_game *w, int color);

#endif