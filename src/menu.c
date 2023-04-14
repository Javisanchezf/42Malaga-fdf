/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:55:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/14 19:31:48 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MENU_WIDTH 250
#define MENU_HEIGHT HEIGHT

void	ft_menu(t_fdfvariables	*fdf)
{
	fdf->menu = mlx_new_image(fdf->mlx, MENU_WIDTH, MENU_HEIGHT);
	if (!fdf->menu)
		ft_error("MLX NEW IMAGE FAIL.", 1, fdf->map);
	ft_memset(fdf->menu->pixels, 120, MENU_WIDTH * MENU_HEIGHT * sizeof(int));
	if (mlx_image_to_window(fdf->mlx, fdf->menu, 0, 0 < 0))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, fdf->map);
	mlx_put_string(fdf->mlx, "---CONTROLS---", 50, 10);
	mlx_put_string(fdf->mlx, "Arrows: Basic movement", 5, 30);
	mlx_put_string(fdf->mlx, "ESC: Close the window", 5, 50);
}
