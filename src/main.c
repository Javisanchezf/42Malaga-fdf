/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:43:38 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/04 21:39:13 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "fdf.h"


// #include <stdio.h>
// #include <unistd.h>
// #include <stdlib.h>
// #include <memory.h>


// mlx_image_t	*g_img;

// static void	error(void)
// {
// 	puts(mlx_strerror(mlx_errno));
// 	exit(EXIT_FAILURE);
// }

// void	hook(void *param)
// {
// 	mlx_t	*mlx;

// 	mlx = param;
// 	if (mlx_is_key_down(param, MLX_KEY_ESCAPE))
// 		mlx_close_window(param);
// 	if (mlx_is_key_down(param, MLX_KEY_UP))
// 		g_img->instances[0].y -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_DOWN))
// 		g_img->instances[0].y += 5;
// 	if (mlx_is_key_down(param, MLX_KEY_LEFT))
// 		g_img->instances[0].x -= 5;
// 	if (mlx_is_key_down(param, MLX_KEY_RIGHT))
// 		g_img->instances[0].x += 5;
// 	if (mlx_is_mouse_down(param, MLX_MOUSE_BUTTON_LEFT))
// 		mlx_get_mouse_pos(param, &g_img->instances[0].x, &g_img->instances[0].y);
// 	if (mlx_is_key_down(param, MLX_KEY_H))
// 		g_img->enabled = 0;
// 	if (mlx_is_key_down(param, MLX_KEY_S))
// 		g_img->enabled = 1;
// }

// int32_t	main(void)
// {
// 	mlx_t	*mlx;

// 	mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
// 	if (!mlx)
// 		error();
// 	g_img = mlx_new_image(mlx, 128, 128);
// 	if (!g_img)
// 		error();
// 	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
// 	if (mlx_image_to_window(mlx, g_img, 0, 0) < 0)
// 		error();
// 	mlx_loop_hook(mlx, &hook, mlx);
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, g_img);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


//-----------------------------------------------------------------------------
// int32_t	main(void)
// {
// 	uint8_t *disp;
// 	uint8_t *disp1;
	
// //   

	
// 	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
// 	if (!mlx)
//         error();
// 	mlx_image_t* img = mlx_new_image(mlx, 1920, 1024);
// 	if (!img)
// 		error();
// 	// memset(img->pixels, 127, img->width * img->height * sizeof(int32_t));
// 	disp = calloc(img->width * img->height , sizeof(int32_t));
// 	disp1 = calloc(img->width * img->height , sizeof(int32_t));
// 	 unsigned long i;
//    for(i=0; i<(img->width * img->height*sizeof(int32_t)); i++) 
//    {
// 		if ((i / img->height)%2 == 1)
//         	disp[i] = 255;
// 		// if ((i / img->height)%2 == 0)
//         // 	disp[i] = 120;
//    }
// 	img->pixels = disp;
// 	// if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//     //     error();
// // 	   for(i=0; ((i * 10) + i)<(img->width * img->height*sizeof(int32_t)); i++) 
// //    {
// // 		// if ((i / img->height)%2 == 1)
// //         // 	disp[i] = 255;
// //         	disp1[((i * 10) + i)] = 255;
// //    }
// 	int	j;
// 	j = 0;
// 	int color = 255;
// 	for (i=0; i<(img->width * img->height * sizeof(int32_t)); i++)
// 	{
// 		j++;
// 		if (j == 16)
// 		{
// 			disp1[i] = color;
// 			disp1[i - 1] = color;
// 			disp1[i - 2] = color;
// 			disp1[i - 3] = color;
// 			disp1[i - 4] = 255;
// 			disp1[i - 5] = 2;
// 			disp1[i - 6] = 2;
// 			disp1[i - 7] = 8 * 16 + 1;
// 			j = 0;
// 		}
// 		if(i > 1024 * 4 * 100)
// 			color = 42;
// 	}
// 	img->pixels = disp1;
// 	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
//         error();
// 	mlx_loop(mlx);
// 	mlx_delete_image(mlx, img);
// 	mlx_terminate(mlx);
// 	// ft_free_and_null((void **) &disp);
// 	return (EXIT_SUCCESS);
// }