/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:48 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/13 12:56:57 by javiersa         ###   ########.fr       */
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
		x =  ((i % fdf->map_width) * fdf->zoom);
		y = ((i / fdf->map_width) * fdf->zoom);
		z = (fdf->map[i].z * fdf->zoom * fdf->z_zoom);
		// fdf->map[i].x_iso = -1 * (((((i / fdf->map_width) * fdf->zoom)- 
		// ((i % fdf->map_width)) * fdf->zoom) * fdf->x_angle));
		// fdf->map[i].y_iso = ((((i / fdf->map_width) * fdf->zoom) + 
		// ((i % fdf->map_width)) * fdf->zoom) * fdf->y_angle - (fdf->map[i].z) * 
		// fdf->zoom * fdf->z_zoom);
		fdf->map[i].x_iso = (x + 0.5 * z);
		fdf->map[i].y_iso = (y + 0.5 * z);
		// fdf->map[i].x_iso = (0.866 * x - y);
		// fdf->map[i].y_iso = (y + x * 0.47 - z);
	}
	ft_normalize(fdf);
}

void	ft_putrgba(int i, t_fdfvariables *fdf)
{
	fdf->img->pixels[i] = fdf->map->r;
	fdf->img->pixels[i + 1] = fdf->map->g;
	fdf->img->pixels[i + 2] = fdf->map->b;
	fdf->img->pixels[i + 3] = fdf->map->a;
}

// void	bresenham(int x1, int y1, int x2, int y2, t_fdfvariables *fdf)
// {
// 	int dx = abs(x2 - x1);
// 	int dy = abs(y2 - y1);
// 	int sx, sy;
// 	(void)fdf;

// 	if (x1 < x2)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (y1 < y2)
// 		sy = 1;
// 	else
// 		sy = -1;

// 	int err = dx - dy;
// 	int e2;
// 	int x = x1;
// 	int y = y1;

// 	while (1)
// 	{
// 		if (x > 0 && y > 0)
// 			ft_putrgba(((x - 1) * 4) + (fdf->img->width * (y - 1) * 4), fdf);
// 		if (x == x2 && y == y2)
// 			break;
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y += sy;
// 		}
// 	}
// }

void	bresenham(int x1, int y1, int x2, int y2, t_fdfvariables *fdf)
{
	int	dx;
	int	dy;
	int	sx;
	int	sy;
	int	err;
	int	e2;
	int	x;
	int	y;

	dx = abs(x2 - x1);
	dy = abs(y2 - y1);
	if (x1 < x2)
		sx = 1;
	else
		sx = -1;
	if (y1 < y2)
		sy = 1;
	else
		sy = -1;
	err = dx - dy;
	x = x1;
	y = y1;
	while (x != x2 || y != y2)
	{
		if (x > 0 && y > 0)
			ft_putrgba((abs(x - 1) * 4) + (fdf->img->width * abs(y - 1) * 4), fdf);
		else
			ft_putrgba((x * 4) + (fdf->img->width * y * 4), fdf);
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

	ft_memset(fdf->img->pixels, 0, fdf->img->width * \
	fdf->img->height * sizeof(int));
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
	}
}


// typedef struct s_point
// {
//     int x;
//     int y;
// } t_point;

// void transformarCoordenadas(float x, float y, float z, char vista, t_point *punto) {
//     if (vista == 'I') { // Vista Isométrica
//         punto->x = (int)(0.866 * x + 0.5 * y);
//         punto->y = (int)(-0.5 * x + 0.866 * y - z);
//     } else if (vista == 'C') { // Vista Caballera
//         punto->x = (int)(x + 0.5 * z);
//         punto->y = (int)(y + 0.5 * z);
//     } else if (vista == 'O') { // Vista Cónica
//         punto->x = (int)(x / z);
//         punto->y = (int)(y / z);
//     } else {
//         printf("Vista no válida.\n");
//         exit(1);
//     }
// }

// void aplicarRotacion(float *x, float *y, float angulo) {
//     float x_orig = *x;
//     float y_orig = *y;
//     float radianes = angulo * M_PI / 180.0;
//     *x = x_orig * cos(radianes) - y_orig * sin(radianes);
//     *y = x_orig * sin(radianes) + y_orig * cos(radianes);
// }

// int main() {
//     void *mlx_ptr;
//     void *win_ptr;
//     t_point punto_2d;

//     float x = 3.0;
//     float y = 4.0;
//     float z = 5.0;
//     char vista = 'I';

//     // Transformar las coordenadas a 2D para poder dibujarlas con MINILIBX
//     transformarCoordenadas(x, y, z, vista, &punto_2d);

//     // Aplicar una rotación adicional de 45 grados
//     aplicarRotacion(&punto_2d.x, &punto_2d.y, 45.0);

//     // Iniciar MINILIBX y dibujar el punto
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 800, 600, "Ejemplo");
//     mlx_pixel_put(mlx_ptr, win_ptr, punto_2d.x, punto_2d.y, 0xFFFFFF);
//     mlx_loop(mlx_ptr);

//     return 0;
// }
