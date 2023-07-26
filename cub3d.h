/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 10:41:03 by lamici            #+#    #+#             */
/*   Updated: 2023/07/26 12:02:43 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define DEBUG printf("ciao\n")

# include "Libft/libft.h"
# include "minilibx-linux/mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>

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