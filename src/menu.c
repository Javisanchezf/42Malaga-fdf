/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:55:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/12 12:23:13 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(t_fdfvariables	*fdf)
{
	fdf->menu = mlx_new_image(fdf->mlx, 250, HEIGHT);
	if (!fdf->menu)
		error("Fallo al enviar imagen.");
	ft_memset(fdf->menu->pixels, 120, fdf->menu->width * fdf->menu->height * sizeof(int));
	if (mlx_image_to_window(fdf->mlx, fdf->menu, 0, 0 < 0))
		error("fallo.");
	mlx_put_string(fdf->mlx, "---CONTROLS---", 50, 10);
	mlx_put_string(fdf->mlx, "Arrows: Basic movement", 5, 30);
	mlx_put_string(fdf->mlx, "ESC: Close the window", 5, 50);
}