/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 20:55:58 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/17 19:22:19 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

#define MENU_WIDTH 300
#define LINE 30
#define MENU_HEIGHT HEIGHT

// void	ft_menu(t_fdfvariables	*fdf)
// {
// 	int	i;

// 	i = 0;
// 	fdf->menu = mlx_new_image(fdf->mlx, MENU_WIDTH, MENU_HEIGHT);
// 	if (!fdf->menu)
// 		ft_error("MLX NEW IMAGE FAIL.", 1, fdf->map);
// 	ft_memset(fdf->menu->pixels, 120, MENU_WIDTH * MENU_HEIGHT * sizeof(int));
// 	if (mlx_image_to_window(fdf->mlx, fdf->menu, 0, 0 < 0))
// 		ft_error("MLX IMAGE TO WINDOW FAIL.", 1, fdf->map);
// 	mlx_put_string(fdf->mlx, "---KEYBOARD CONTROLS---", 20, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[Arrows]: Move", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[KP4][KP6][KP2][KP8]: Rotate", 5, 10 + 30 * i++);
// 	mlx_put_string(fdf->mlx, "[KP+][KP-]: Zoom", 5, 10 + 30 * i++);
// 	mlx_put_string(fdf->mlx, "[W][S]: Modify height", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[A][D]: Modify width", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[ESC]: Close the window", 5, 10 + LINE * i++);
// 	i++;
// 	mlx_put_string(fdf->mlx, "---MOUSE CONTROLS---", 25, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[Cursor+LeftClick]: Move", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[Cursor+RightClick]: Rotate", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[SCROLL +/-]: Zoom", 5, 10 + LINE * i++);
// 	i++;
// 	mlx_put_string(fdf->mlx, "---COLORS CONTROL---", 20, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[0]: Earth", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[1]: Default", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[2]: White", 5, 10 + LINE * i++);
// 	mlx_put_string(fdf->mlx, "[2]: Black", 5, 10 + LINE * i++);
// }

void	menu_instructions(t_fdfvariables *fdf, int *i)
{
	mlx_put_string(fdf->mlx, "---KEYBOARD CONTROLS---", 20, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[Arrows]: Move", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[KP4][KP6][KP2][KP8]: Rotate", 5, 35 * (*i)++);
	mlx_put_string(fdf->mlx, "[KP+][KP-]: Zoom", 5, 10 + 30 * (*i)++);
	mlx_put_string(fdf->mlx, "[W][S]: Modify height", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[A][D]: Modify width", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[ESC]: Close the window", 5, 10 + LINE * (*i)++);
	(*i)++;
	mlx_put_string(fdf->mlx, "---MOUSE CONTROLS---", 25, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[Cursor+LeftClick]: Move", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[Cursor+RightClick]: Rotate", 5, 31 * (*i)++);
	mlx_put_string(fdf->mlx, "[SCROLL +/-]: Zoom", 5, 10 + LINE * (*i)++);
	(*i)++;
	mlx_put_string(fdf->mlx, "---COLORS CONTROL---", 20, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[0]: Earth", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[1]: Default", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[2]: White", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[2]: Black", 5, 10 + LINE * (*i)++);
	(*i)++;
}

void	menu_views(t_fdfvariables *fdf, int *i)
{
	mlx_put_string(fdf->mlx, "---VIEWS CONTROL---", 20, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[I]: Isometric projection", 5, 10 + 30 * (*i)++);
	mlx_put_string(fdf->mlx, "[C]: Cavalier projection", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[F]: Front view", 5, 10 + LINE * (*i)++);
	mlx_put_string(fdf->mlx, "[T]: Top view", 5, 10 + LINE * (*i)++);
}

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
	menu_instructions(fdf, &i);
	menu_views(fdf, &i);
}
