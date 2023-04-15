/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:55:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/15 11:26:08 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MENU_WIDTH 250
#define LINE 30
#define MENU_HEIGHT HEIGHT

void	ft_menu(t_fdfvariables	*fdf)
{
	int	i;

	i = 0;
	fdf->menu = mlx_new_image(fdf->mlx, MENU_WIDTH, MENU_HEIGHT);
	if (!fdf->menu)
		ft_error("MLX NEW IMAGE FAIL.", 1, fdf->map);
	ft_memset(fdf->menu->pixels, 120, MENU_WIDTH * MENU_HEIGHT * sizeof(int));
	if (mlx_image_to_window(fdf->mlx, fdf->menu, 0, 0 < 0))
		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, fdf->map);
	mlx_put_string(fdf->mlx, "---FORM CONTROLS---", 20, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[Arrows]: Basic movement", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[Cursor+LeftClick]: Move", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[SCROLL +/-]: Zoom", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[W][S]: Modify height", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[A][D]: Modify width", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[ESC]: Close the window", 5, 10 + LINE * i++);
	i++;
	mlx_put_string(fdf->mlx, "---COLORS CONTROL---", 15, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[0]: Default", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[1]: White", 5, 10 + LINE * i++);
	mlx_put_string(fdf->mlx, "[2]: Earth", 5, 10 + LINE * i++);
}
