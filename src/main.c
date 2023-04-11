/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:43:38 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/11 23:01:14 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *prompt)
{
	ft_printf("%s", prompt);
	exit(EXIT_FAILURE);
}

int32_t	ft_w_center(const uint32_t n1, const uint32_t n2)
{
	if (n1 > n2)
		return ((n1 - n2) / 2);
	return ((n2 - n1) / 2);
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
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_H))
		fdf->img->enabled = 0;
	if (mlx_is_key_down(fdf->mlx, MLX_KEY_S))
		fdf->img->enabled = 1;
}

int32_t	main(int narg, char **argv)
{
	t_fdfvariables	fdf;

	if (narg != 2 || !argv[1])
		return (1);
	ft_map_construct(argv[1], &fdf);
	fdf.mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!fdf.mlx)
		error("Fallo al iniciar fdf->mlx.");
	fdf.img = mlx_new_image(fdf.mlx, fdf.window_width, fdf.window_height);
	if (!fdf.img)
		error("Fallo al crear la imagen.");
	// ft_memset(fdf.img->pixels, 100, fdf.img->width * fdf.img->height * sizeof(int));
	ft_picasso(&fdf);
	if (mlx_image_to_window(fdf.mlx, fdf.img, ft_w_center(WIDTH, fdf.img->width), ft_w_center(HEIGHT, fdf.img->height) < 0))
		error("Fallo al poner la imagen en la window.");
	ft_menu(fdf.mlx);
	mlx_loop_hook(fdf.mlx, &hook, (void *)&fdf);
	mlx_loop(fdf.mlx);
	ft_free_and_null((void **) &fdf.map);
	mlx_delete_image(fdf.mlx, fdf.img);
	mlx_terminate(fdf.mlx);
	return (EXIT_SUCCESS);
}
