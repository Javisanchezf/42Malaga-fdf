/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:55:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/11 21:09:25 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_menu(mlx_t	*mlx)
{
	mlx_image_t	*menu;

	menu = mlx_new_image(mlx, 250, HEIGHT);
	if (!menu)
		error("Fallo al enviar imagen.");
	ft_memset(menu->pixels, 120, menu->width * menu->height * sizeof(int));
	if (mlx_image_to_window(mlx, menu, 0, 0 < 0))
		error("fallo.");
	mlx_put_string(mlx, "---CONTROLS---", 50, 10);
	mlx_put_string(mlx, "Arrows: Basic movement", 5, 30);
	mlx_put_string(mlx, "ESC: Close the window", 5, 50);
}