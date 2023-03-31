/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:43:38 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/31 21:49:55 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <memory.h>
#define WIDTH 5120
#define HEIGHT 2880

static void error(void)
{
	puts(mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int32_t	main(void)
{
	uint8_t *disp;
	uint8_t *disp1;
	
//   

	
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "FDF", true);
	if (!mlx)
        error();
	mlx_image_t* img = mlx_new_image(mlx, 1024, 1024);
	if (!img)
		error();
	// memset(img->pixels, 127, img->width * img->height * sizeof(int32_t));
	disp = calloc(img->width * img->height , sizeof(int32_t));
	disp1 = calloc(img->width * img->height , sizeof(int32_t));
	ft_printf("%d y %d", (img->width * img->height ), sizeof(uint8_t));
	 unsigned long i;
   for(i=0; i<(img->width * img->height*sizeof(int32_t)); i++) 
   {
		if ((i / img->height)%2 == 1)
        	disp[i] = 255;
		// if ((i / img->height)%2 == 0)
        // 	disp[i] = 120;
   }
	img->pixels = disp;
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();
// 	   for(i=0; ((i * 10) + i)<(img->width * img->height*sizeof(int32_t)); i++) 
//    {
// 		// if ((i / img->height)%2 == 1)
//         // 	disp[i] = 255;
//         	disp1[((i * 10) + i)] = 255;
//    }
	int	j;
	j = 0;
	int color = 255;
	for (i=0; i<(img->width * img->height * sizeof(int32_t)); i++)
	{
		j++;
		if (j == 16)
		{
			disp1[i] = color;
			disp1[i - 1] = color;
			disp1[i - 2] = color;
			disp1[i - 3] = color;
			disp1[i - 4] = 255;
			disp1[i - 5] = 2;
			disp1[i - 6] = 2;
			disp1[i - 7] = 8 * 16 + 1;
			j = 0;
		}
		if(i > 1024 * 4 * 100)
			color = 42;
	}
	img->pixels = disp1;
	if (mlx_image_to_window(mlx, img, 0, 0) < 0)
        error();
	mlx_loop(mlx);
	mlx_delete_image(mlx, img);
	mlx_terminate(mlx);
	// ft_free_and_null((void **) &disp);
	return (EXIT_SUCCESS);
}