/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abettini <abettini@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 17:14:26 by abettini          #+#    #+#             */
/*   Updated: 2023/08/28 17:26:38 by abettini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_free_imgs_paths(t_game *game)
{
	if (game->n.path)
		free(game->n.path);
	if (game->s.path)
		free(game->s.path);
	if (game->w.path)
		free(game->w.path);
	if (game->e.path)
		free(game->e.path);
}

void	ft_destroy_imgs(t_game *game)
{
	mlx_destroy_image(game->mlx, game->n.img);
	mlx_destroy_image(game->mlx, game->s.img);
	mlx_destroy_image(game->mlx, game->w.img);
	mlx_destroy_image(game->mlx, game->e.img);
	mlx_destroy_image(game->mlx, game->d.img);
}

void	ft_free_game(t_game *game)
{
	ft_freemat(game->map);
	ft_destroy_imgs(game);
	ft_free_imgs_paths(game);
	mlx_destroy_window(game->mlx, game->win.ptr);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
}

/*
int	ft_free(void *ptr)
{
	if (ptr)
		free(ptr);
	return (0);
}
*/