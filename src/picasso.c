/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   picasso.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 11:53:48 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/14 21:22:54 by javiersa         ###   ########.fr       */
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

void	bresenham(int position1, int x1, int y1, int x2, int y2, t_fdfvariables *fdf)
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
		ft_putrgba((abs(brshm.x - 1) * 4) + \
		(fdf->img->width * abs(brshm.y - 1) * 4), fdf, position1);
		brshm.e2 = 2 * brshm.err;
		bresenham_aux(&brshm);
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
			bresenham(i + 1, fdf->map[i].x_draw, fdf->map[i].y_draw, \
			fdf->map[i + 1].x_draw, fdf->map[i + 1].y_draw, fdf);
		if (i / fdf->map_width != fdf->map_height - 1)
			bresenham(i + fdf->map_width, fdf->map[i].x_draw, fdf->map[i].y_draw, \
			fdf->map[i + fdf->map_width].x_draw, \
			fdf->map[i + fdf->map_width].y_draw, fdf);
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
