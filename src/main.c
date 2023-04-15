/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:43:38 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/15 18:48:34 by javiersa         ###   ########.fr       */
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

void	hook(void *param)
{
	t_fdfvariables	*fdf;

	fdf = param;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->img->instances->y -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->img->instances->y += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->img->instances->x -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->img->instances->x += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		ft_picasso_colors(0, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		ft_picasso_colors(1, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		ft_picasso_colors(2, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		ft_picasso_colors(3, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_Y))
	{
		fdf->radians += 1 * M_PI / 180.0;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_H))
	{
		fdf->radians -= 1 * M_PI / 180.0;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
	{
		fdf->z_zoom -= 0.01;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_W))
	{
		fdf->z_zoom += 0.01;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_A))
	{
		fdf->x_zoom -= 0.01;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_D))
	{
		fdf->x_zoom += 0.01;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_I))
	{
		fdf->view = 'I';
		remake(0, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_C))
	{
		fdf->view = 'C';
		remake(0, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_P))
	{
		fdf->view = 'P';
		remake(0, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_O))
	{
		fdf->view = 'O';
		remake(0, fdf);
	}
}

void	ft_leaks(void)
{
	system("leaks -q fdf");
}

void	scroll_hook(double xdelta, double ydelta, void* param)
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
	mlx_loop_hook(fdf.mlx, &hook, (void *)&fdf);
	mlx_scroll_hook(fdf.mlx, &scroll_hook, (void *)&fdf);
	mlx_cursor_hook(fdf.mlx, &cursor_hook, (void *)&fdf);
	mlx_loop(fdf.mlx);
	ft_multiple_free(1, fdf.map);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
