/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:41:03 by lamici            #+#    #+#             */
/*   Updated: 2023/07/28 11:09:27 by lamici           ###   ########.fr       */
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

typedef	struct s_image
{
	void	*img;
	int		height;
	int		width;
}	t_image;


typedef struct	s_boi
{
	int x;
	void *boi;
	void *death;
	int y;
	int old_x;
	int old_y;
}				t_boi;

typedef struct s_game
{
	t_image	n;
	t_image	s;
	t_image	w;
	t_image	e;
	t_boi	imgs;
	void	*win;
	void	*mlx;
	char	*ceiling;
	char	*floor;
	char	**map;
}	t_game;

#endif