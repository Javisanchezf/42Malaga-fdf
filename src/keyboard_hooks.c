/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyboard_hooks.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 17:26:07 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/17 18:22:25 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	color_hooks(t_fdfvariables *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_0))
		ft_picasso_colors(0, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_1))
		ft_picasso_colors(1, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_2))
		ft_picasso_colors(2, fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_3))
		ft_picasso_colors(3, fdf);
}

void	views_hook(t_fdfvariables *fdf)
{
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

void	modify_form_hook(t_fdfvariables *fdf)
{
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
}

void	keyboard_others_hook(t_fdfvariables *fdf)
{
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(fdf->mlx);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_4))
	{
		fdf->radians += 1 * M_PI / 180.0;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_6))
	{
		fdf->radians -= 1 * M_PI / 180.0;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_8))
	{
		fdf->radians2 += 1 * M_PI / 180.0;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_KP_2))
	{
		fdf->radians2 -= 1 * M_PI / 180.0;
		remake(1, fdf);
	}
}

void	keyboard_hooks(void *param)
{
	t_fdfvariables	*fdf;

	fdf = param;
	color_hooks(fdf);
	views_hook(fdf);
	modify_form_hook(fdf);
	keyboard_others_hook(fdf);
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_UP))
		fdf->img->instances->y -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_DOWN))
		fdf->img->instances->y += 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_LEFT))
		fdf->img->instances->x -= 5;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_RIGHT))
		fdf->img->instances->x += 5;
	if (mlx_is_key_down(fdf->mlx, 334))
	{
		fdf->zoom += 1;
		remake(1, fdf);
	}
	if (mlx_is_key_down(fdf->mlx, 333))
	{
		fdf->zoom -= 1;
		remake(1, fdf);
	}
}
