/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:03:23 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/17 19:27:13 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	remake(int reset, t_fdfvariables *fdf)
{
	if (reset == 0)
	{
		fdf->z_max = 0;
		fdf->zoom = 0;
		fdf->z_zoom = 0.4;
		fdf->x_zoom = 1;
		fdf->radians = 0;
		fdf->radians2 = 0;
	}
	ft_views(fdf);
	mlx_resize_image(fdf->img, fdf->window_width, fdf->window_height);
	ft_picasso(fdf);
}

void	ft_piccaso_brush(uint8_t r, uint8_t g, uint8_t b, t_fdfmap	*map)
{
		map->r = r;
		map->g = g;
		map->b = b;
		map->a = 255;
}

void	ft_piccaso_basic_colors(int colors, t_fdfvariables *fdf)
{
	int	i;

	i = -1;
	if (colors == 1)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_piccaso_brush(255, 140, 0, &fdf->map[i]);
	else if (colors == 2)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_piccaso_brush(255, 255, 255, &fdf->map[i]);
	else if (colors == 3)
		while (++i < (fdf->map_height * fdf->map_width))
			ft_piccaso_brush(0, 0, 0, &fdf->map[i]);
}

void	ft_picasso_colors(int colors, t_fdfvariables *fdf)
{
	int	i;
	int	aux;

	i = -1;
	aux = 0;
	if (colors == 0)
	{
		while (++i < (fdf->map_height * fdf->map_width))
		{
			if (fdf->z_max != 0)
				aux = fdf->map[i].z * 60 / fdf->z_max;
			if (fdf->map[i].z == fdf->z_max)
				ft_piccaso_brush(255, 255, 255, &fdf->map[i]);
			else if (fdf->map[i].z >= 0)
				ft_piccaso_brush(80, 100 - aux, 0, &fdf->map[i]);
			else if (fdf->map[i].z < 0)
				ft_piccaso_brush(0, 0, 128, &fdf->map[i]);
		}
	}
	else
		ft_piccaso_basic_colors(colors, fdf);
	remake(1, fdf);
}
