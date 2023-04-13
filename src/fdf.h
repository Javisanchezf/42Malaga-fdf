/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:46:26 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/13 21:16:31 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1024
# include "../libftplus/libftplus.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_fdfmap
{
	int				z;
	uint8_t			r;
	uint8_t			g;
	uint8_t			b;
	uint8_t			a;
	int				x_draw;
	int				y_draw;
}					t_fdfmap;

typedef struct s_fdfvariables
{
	t_fdfmap	*map;
	mlx_image_t	*img;
	mlx_image_t	*menu;
	mlx_t		*mlx;
	int			map_width;
	int			map_height;
	int			window_width;
	int			window_height;
	int			zoom;
	float		z_zoom;
	float		x_angle;
	float		y_angle;
}					t_fdfvariables;

void		ft_menu(t_fdfvariables	*fdf);
void		ft_picasso(t_fdfvariables *fdf);
void		ft_map_construct(char *file, t_fdfvariables	*fdf);
void		ft_views_and_zoom(t_fdfvariables	*fdf);
void		ft_extract_colorandz(char *file, t_fdfvariables *fdf);

#endif