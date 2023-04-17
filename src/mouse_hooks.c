/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:25:06 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/17 18:05:54 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	scroll_hook(double xdelta, double ydelta, void *param)
{
	t_fdfvariables	*fdf;

	fdf = param;
	(void)xdelta;
	if (ydelta > 0)
	{
		fdf->zoom += 1;
		remake(1, fdf);
	}
	else if (ydelta < 0)
	{
		fdf->zoom -= 1;
		remake(1, fdf);
	}
}

void	rotation_cursor_hook(double x2, double y2, t_fdfvariables *fdf)
{
	static int		i = 2;
	static double	y1 = 0;
	static double	x1 = 0;

	if (mlx_is_mouse_down(fdf->mlx, MLX_MOUSE_BUTTON_RIGHT))
	{
		if (i == 2)
		{
			fdf->radians -= ((long)x2 - (long)x1) % 100 / 10 * M_PI / 180.0;
			fdf->radians2 -= ((long)y2 - (long)y1) % 100 / 10 * M_PI / 180.0;
			x1 = x2;
			y1 = y2;
			i = 0;
		}
		else
		{
			fdf->radians -= ((long)x2 - (long)x1) % 100 / 10 * M_PI / 180.0;
			fdf->radians2 -= ((long)y2 - (long)y1) % 100 / 10 * M_PI / 180.0;
		}
		ft_views(fdf);
		mlx_resize_image(fdf->img, fdf->window_width, fdf->window_height);
		ft_picasso(fdf);
		i++;
	}
}

void	cursor_hook(double x2, double y2, void *param)
{
	t_fdfvariables	*fdf;
	static int		i = 2;
	static double	y1 = 0;
	static double	x1 = 0;

	fdf = param;
	rotation_cursor_hook(x2, y2, param);
	if (mlx_is_mouse_down(fdf->mlx, MLX_MOUSE_BUTTON_LEFT))
	{
		if (i == 2)
		{
			fdf->img->instances->x += ((long)x2 - (long)x1) % 30 ;
			fdf->img->instances->y += ((long)y2 - (long)y1) % 30 ;
			x1 = x2;
			y1 = y2;
			i = 0;
		}
		else
		{
			fdf->img->instances->x += ((long)x2 - (long)x1) % 30 ;
			fdf->img->instances->y += ((long)y2 - (long)y1) % 30 ;
		}
		i++;
	}
}
