/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:48 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/15 17:05:13 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


typedef struct s_bresenham
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;
}					t_bresenham;

void	ft_putrgba(int i, t_fdfvariables *fdf, int j)
{
	fdf->img->pixels[i] = fdf->map[j].r;
	fdf->img->pixels[i + 1] = fdf->map[j].g;
	fdf->img->pixels[i + 2] = fdf->map[j].b;
	fdf->img->pixels[i + 3] = fdf->map[j].a;
}

void	bresenham_aux(t_bresenham	*brshm)
{
	if (brshm->e2 > -brshm->dy)
	{
		brshm->err -= brshm->dy;
		brshm->x += brshm->sx;
	}
	if (brshm->e2 < brshm->dx)
	{
		brshm->err += brshm->dx;
		brshm->y += brshm->sy;
	}
}

void	bresenham(int position, int x1, int y1, int x2, int y2, t_fdfvariables *fdf)
{
	t_bresenham	brshm;

	brshm.dx = ft_abs(x2 - x1);
	brshm.dy = ft_abs(y2 - y1);
	if (x1 < x2)
		brshm.sx = 1;
	else
		brshm.sx = -1;
	if (y1 < y2)
		brshm.sy = 1;
	else
		brshm.sy = -1;
	brshm.err = brshm.dx - brshm.dy;
	brshm.x = x1;
	brshm.y = y1;
	while (brshm.x != x2 || brshm.y != y2)
	{
		ft_putrgba((ft_abs(brshm.x - 1) * 4) + \
		(fdf->img->width * ft_abs(brshm.y - 1) * 4), fdf, position);
		brshm.e2 = 2 * brshm.err;
		bresenham_aux(&brshm);
	}
}

void	ft_picasso(t_fdfvariables *fdf)
{
	int	i;
	int	aux;

	ft_memset(fdf->img->pixels, 0, fdf->img->width * \
	fdf->img->height * sizeof(int));
	i = -1;
	while (++i < ((fdf->map_height * fdf->map_width)))
	{
		aux = i;
		if ((i + 1) % fdf->map_width != 0)
		{
			if (fdf->map[i].z < fdf->map[i + 1].z)
				aux = i + 1;
			bresenham(aux, fdf->map[i].x_draw, fdf->map[i].y_draw, \
			fdf->map[i + 1].x_draw, fdf->map[i + 1].y_draw, fdf);
		}
		if (i / fdf->map_width != fdf->map_height - 1)
		{
			if (fdf->map[i].z < fdf->map[i + fdf->map_width].z)
				aux = i + fdf->map_width;
			bresenham(aux, fdf->map[i].x_draw, fdf->map[i].y_draw, \
			fdf->map[i + fdf->map_width].x_draw, \
			fdf->map[i + fdf->map_width].y_draw, fdf);
		}
	}
}
