/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   views.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:14:50 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/15 18:29:47 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

typedef struct s_coords
{
	int				x;
	int				y;
	int				z;
}					t_coords;

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

void	ft_checkzoom(t_fdfvariables	*fdf)
{
	if (fdf->zoom <= 0)
	{
		if ((HEIGHT / fdf->map_height) > (WIDTH / fdf->map_width))
			fdf->zoom = (HEIGHT / fdf->map_height) / 2;
		else
			fdf->zoom = (WIDTH / fdf->map_width) / 2;
	}
}

void	ft_set_coords(int i, t_coords c, t_fdfvariables *fdf)
{
	if (fdf->view == 'I')
	{
		fdf->map[i].x_draw = (0.866 * c.x - 0.5 * c.y);
		fdf->map[i].y_draw = (0.866 * c.y + 0.5 * c.x - c.z);
	}
	else if (fdf->view == 'C')
	{
		fdf->map[i].x_draw = (c.x - 0.71 * c.z) - 0.71 * (c.y - 0.71 * c.z);
		fdf->map[i].y_draw = (c.y - 0.71 * c.z);
	}
	else if (fdf->view == 'P')
	{
		fdf->map[i].x_draw = c.x;
		fdf->map[i].y_draw = c.y;
	}
	else if (fdf->view == 'O')
	{
		fdf->map[i].x_draw = c.y + c.x;
		fdf->map[i].y_draw = -c.z;
	}
}

void	ft_views(t_fdfvariables	*fdf)
{
	int			i;
	t_coords	coord;

	i = -1;
	ft_checkzoom(fdf);
	while (++i < (fdf->map_height * fdf->map_width))
	{
		coord.x = (fdf->x_zoom * (i % fdf->map_width) * fdf->zoom) * \
		cos(fdf->radians) - ((i / fdf->map_width) * fdf->zoom) * \
		sin(fdf->radians);
		coord.y = ((i / fdf->map_width) * fdf->zoom) * cos(fdf->radians) \
		* cos(fdf->radians2) \
		+ ((i % fdf->map_width) * fdf->zoom) * sin(fdf->radians) \
		- (fdf->map[i].z * fdf->zoom * fdf->z_zoom) * sin(fdf->radians2);
		coord.z = (fdf->map[i].z * fdf->zoom * fdf->z_zoom) * \
		cos(fdf->radians2) \
		+ ((i / fdf->map_width) * fdf->zoom) * sin(fdf->radians2);

		ft_set_coords(i, coord, fdf);
	}
	ft_normalize(fdf);
}
