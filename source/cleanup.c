/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:33:49 by lamici            #+#    #+#             */
/*   Updated: 2023/08/01 11:34:08 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void ft_delete_my_boy(t_game *w)
{
	mlx_put_image_to_window(w->mlx, w->win, w->imgs.death, w->pos.px, w->pos.py);
	ft_put_pipo(w, 0x000000);
}

int	ft_close(t_game *w)
{
	mlx_destroy_window(w->mlx, w->win);
	mlx_destroy_display(w->mlx);
	free(w->mlx);
	exit(0);
}	