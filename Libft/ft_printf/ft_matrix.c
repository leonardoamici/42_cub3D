/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamici <lamici@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 09:06:35 by lamici            #+#    #+#             */
/*   Updated: 2023/06/30 15:32:53 by lamici           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_matrix(char **mat)
{
	int	x;
	int	y;
	int	count;

	y = 0;
	count = 0;
	while (mat[y] != 0)
	{
		x = 0;
		while (mat[y][x] != '\0')
		{
			write(1, &mat[y][x], 1);
			x++;
			count++;
		}
		write(1, "\n", 1);
		y++;
	}
	return (count);
}
