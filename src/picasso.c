/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:48 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/12 12:47:23 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	ft_normalize(t_fdfvariables	*fdf)
{
	int	i;
	int	lower_x;
	int	lower_y;

	i = -1;
	fdf->window_height = 0;
	fdf->window_width = 0;
	lower_x = 0;
	lower_y = 0;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		if (lower_x > fdf->map[i].x_iso)
			lower_x = fdf->map[i].x_iso;
		if (lower_y > fdf->map[i].y_iso)
			lower_y = fdf->map[i].y_iso;
		if (fdf->window_width < fdf->map[i].x_iso)
			fdf->window_width = fdf->map[i].x_iso;
		if (fdf->window_height < fdf->map[i].y_iso)
			fdf->window_height = fdf->map[i].y_iso;
	}
	i = -1;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_iso -= lower_x;
		fdf->map[i].y_iso -= lower_y;
	}
	fdf->window_width -= lower_x;
	fdf->window_height -= lower_y;
}

void	ft_views_and_zoom(t_fdfvariables	*fdf)
{
	int	i;

	i = -1;
	if (fdf->zoom <= 0) //Para nada mas iniciar el mapa o cuando el zoom sea 0, puede que en el futuro no sirva y se eliminaria zoom=0 despues del calloc
	{
		if ((HEIGHT / fdf->map_height) > (WIDTH / fdf->map_width))
			fdf->zoom = (HEIGHT / fdf->map_height) / 2;
		else
			fdf->zoom = (WIDTH / fdf->map_width) / 2;
	}
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_iso = -1 * (((((i / fdf->map_width) * fdf->zoom)- \
		((i % fdf->map_width)) * fdf->zoom) * cos(0.523599)));
		fdf->map[i].y_iso = ((((i / fdf->map_width) * fdf->zoom) + \
		((i % fdf->map_width)) * fdf->zoom) * sin(0.523599) - (fdf->map[i].z) * fdf->zoom / 4);
	}
	ft_normalize(fdf);
}

void	ft_putrgba(int	i, t_fdfvariables *fdf)
{
	fdf->img->pixels[i] =  fdf->map->r;
	fdf->img->pixels[i + 1] =  fdf->map->g;
	fdf->img->pixels[i + 2] =  fdf->map->b;
	fdf->img->pixels[i + 3] =  fdf->map->a;
}


void	bresenham(int x1, int y1, int x2, int y2, t_fdfvariables *fdf)
{
	int dx = abs(x2 - x1);
	int dy = abs(y2 - y1);
	int sx, sy;
	(void)fdf;

	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;

	int err = dx - dy;
	int e2;
	int x = x1;
	int y = y1;

	while (1)
	{
		if (x > 0 && y > 0)
			ft_putrgba(((x - 1) * 4) + (fdf->img->width * (y - 1) * 4), fdf);
		if (x == x2 && y == y2)
            break;
		e2 = 2 * err;
		if (e2 > -dy)
		{
			err -= dy;
			x += sx;
		}
		if (e2 < dx)
		{
			err += dx;
			y += sy;
		}
	}
}


void	ft_picasso(t_fdfvariables *fdf)
{
	int	i;

	ft_memset(fdf->img->pixels, 0, fdf->img->width * fdf->img->height * sizeof(int)); 
	i = -1;
	while (++i < ((fdf->map_height * fdf->map_width)))
	{
		if ((i + 1) % fdf->map_width != 0)
			bresenham(fdf->map[i].x_iso, fdf->map[i].y_iso, \
			fdf->map[i + 1].x_iso, fdf->map[i + 1].y_iso, fdf);
		if (i / fdf->map_width != fdf->map_height - 1)
			bresenham(fdf->map[i].x_iso, fdf->map[i].y_iso, \
			fdf->map[i + fdf->map_width].x_iso, \
			fdf->map[i + fdf->map_width].y_iso, fdf);
		// if (((i + 1) % fdf->map_width != 0) && (i / fdf->map_width != fdf->map_height - 1))
		// 	bresenham(fdf->map[i].x_iso, fdf->map[i].y_iso, fdf->map[i + fdf->map_width + 1].x_iso, fdf->map[i + fdf->map_width + 1].y_iso, fdf);
		// if ((i / fdf->map_width != fdf->map_height - 1))
		// 	bresenham(fdf->map[i].x_iso, fdf->map[i].y_iso, fdf->map[i + fdf->map_width - 1].x_iso, fdf->map[i + fdf->map_width - 1].y_iso, fdf);
	}
}
