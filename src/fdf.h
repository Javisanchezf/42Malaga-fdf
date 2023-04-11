/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:46:26 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/11 22:34:04 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1024
# include "../libftplus/libftplus.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"

mlx_image_t	*g_img;

typedef struct s_fdfmap
{
	int				z;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
	int				x_iso;
	int				y_iso;
}					t_fdfmap;

typedef struct s_fdfvariables
{
	t_fdfmap	*map;
	mlx_image_t	*img;
	mlx_t		*mlx;
	int			map_width;
	int			map_height;
	int			window_width;
	int			window_height;
	int			zoom;
}					t_fdfvariables;

void		error(char *prompt);
void		ft_menu(mlx_t	*mlx);
void		ft_picasso(t_fdfvariables *fdf);
void		ft_map_construct(char *file, t_fdfvariables	*fdf);

#endif