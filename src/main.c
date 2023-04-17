/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:43:38 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/17 17:28:47 by javiersa         ###   ########.fr       */
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

void	ft_leaks(void)
{
	system("leaks -q fdf");
}

int32_t	ft_w_center(const uint32_t n1, const uint32_t n2)
{
	if (n1 > n2)
		return ((n1 - n2) / 2);
	return ((n2 - n1) / 2);
}

int32_t	main(int narg, char **argv)
{
	t_fdfvariables	fdf;

	atexit(ft_leaks);
	if (narg != 2 || !argv[1])
		return (1);
	ft_map_construct(argv[1], &fdf);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF - javiersa", true);
	if (!fdf.mlx)
		ft_error("MLX INIT FAIL.", 1, fdf.map);
	fdf.img = mlx_new_image(fdf.mlx, fdf.window_width, fdf.window_height);
	if (!fdf.img)
		ft_error("MLX NEW IMAGE FAIL.", 1, fdf.map);
	ft_picasso(&fdf);
	if (mlx_image_to_window(fdf.mlx, fdf.img, \
	ft_w_center(WIDTH, fdf.img->width), ft_w_center(HEIGHT, fdf.img->height)))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, fdf.map);
	ft_menu(&fdf);
	mlx_loop_hook(fdf.mlx, &keyboard_hooks, (void *)&fdf);
	mlx_scroll_hook(fdf.mlx, &scroll_hook, (void *)&fdf);
	mlx_cursor_hook(fdf.mlx, &cursor_hook, (void *)&fdf);
	mlx_loop(fdf.mlx);
	ft_multiple_free(1, fdf.map);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
