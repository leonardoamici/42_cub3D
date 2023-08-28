/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images_data.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:26:09 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:01:01 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	*ft_get_img_xpm(void *mlx, t_data *data)
{
	return (mlx_xpm_file_to_image(mlx, data->path, \
		&data->width, &data->height));
}

void	ft_get_img_addr(t_data *data)
{
	data->addr = mlx_get_data_addr(data->img, \
		&data->bits_per_pixel, &data->line_length, &data->endian);
}

void	ft_get_imgs_data(t_game *game)
{
	game->n.img = ft_get_img_xpm(game->mlx, &(game->n));
	game->s.img = ft_get_img_xpm(game->mlx, &(game->s));
	game->w.img = ft_get_img_xpm(game->mlx, &(game->w));
	game->e.img = ft_get_img_xpm(game->mlx, &(game->e));
	game->d.img = mlx_xpm_file_to_image(game->mlx, "./textures/door.xpm", \
		&game->d.width, &game->d.height);
	ft_get_img_addr(&game->d);
	ft_get_img_addr(&game->n);
	ft_get_img_addr(&game->s);
	ft_get_img_addr(&game->w);
	ft_get_img_addr(&game->e);
}
