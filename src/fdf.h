/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 20:46:26 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/05 12:57:38 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define WIDTH 1920
# define HEIGHT 1024
# include "../libftplus/libftplus.h"
# include <math.h>
# include "../MLX42/include/MLX42/MLX42.h"


typedef struct s_fdfmap
{
	int		z;
	int		r;
	int		g;
	int		b;
	int		a;
	int		x_iso;
	int		y_iso;
}					t_fdfmap;

typedef struct s_fdfvariables
{
	t_fdfmap	*map;
	int			map_width;
	int			map_height;
	int			zoom;
}					t_fdfvariables;


#endif