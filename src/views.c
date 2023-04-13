/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:14:50 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/13 21:14:52 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_normalize(t_fdfvariables	*fdf)
{
	int	i;
	int	lower[2];

	i = -1;
	fdf->window_height = 0;
	fdf->window_width = 0;
	lower[0] = 0;
	lower[1] = 0;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		if (lower[0] > fdf->map[i].x_draw)
			lower[0] = fdf->map[i].x_draw;
		if (lower[1] > fdf->map[i].y_draw)
			lower[1] = fdf->map[i].y_draw;
	}
	i = -1;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_draw -= lower[0];
		fdf->map[i].y_draw -= lower[1];
		if (fdf->window_width < fdf->map[i].x_draw)
			fdf->window_width = fdf->map[i].x_draw;
		if (fdf->window_height < fdf->map[i].y_draw)
			fdf->window_height = fdf->map[i].y_draw;
	}
}

void	ft_views_and_zoom(t_fdfvariables	*fdf)
{
	int	i;
	int	x;
	int	y;
	int	z;

	i = -1;
	if (fdf->zoom <= 0)
	{
		if ((HEIGHT / fdf->map_height) > (WIDTH / fdf->map_width))
			fdf->zoom = (HEIGHT / fdf->map_height) / 2;
		else
			fdf->zoom = (WIDTH / fdf->map_width) / 2;
	}
	while (++i < (fdf->map_height * fdf->map_width))
	{
		x = ((i % fdf->map_width) * fdf->zoom);
		y = ((i / fdf->map_width) * fdf->zoom);
		z = (fdf->map[i].z * fdf->zoom * fdf->z_zoom);
		fdf->map[i].x_draw = (0.866 * x - 0.5 * y);
		fdf->map[i].y_draw = (0.866 * y + 0.5 * x - z);
	}
	ft_normalize(fdf);
}
