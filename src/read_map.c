/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:20 by javiersa          #+#    #+#             */
/*   Updated: 2023/03/29 22:25:12 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libftplus/libftplus.h"
#include <math.h>

typedef struct s_projection
{
	int		*z;
	int		*color;
	int		width;
	int		height;
}					t_projection;

int	ft_isspace(char c)
{
	return (c == ' ' || ((unsigned char)c >= 9 && (unsigned char)c <= 13));
}

int	ft_countwords(char *line)
{
	int	i;

	i = 0;
	while (*line)
	{
		if (ft_isspace(*line) == 0 && (ft_isspace(*(line + 1)) || !line[1]))
			i++;
		line++;
	}
	return (i);
}

int	ft_hex_to_dec(char *hex)
{
	int		len;
	int		dec;
	int		base;
	char	c;

	len = ft_strlen(hex);
	dec = 0;
	base = 1;
	while (len-- > 0)
	{
		c = hex[len];
		if (c >= '0' && c <= '9')
			dec += (c - '0') * base;
		else if (c >= 'a' && c <= 'f')
			dec += (c - 'a' + 10) * base;
		else if (c >= 'A' && c <= 'F')
			dec += (c - 'A' + 10) * base;
		base *= 16;
	}
	return (dec);
}

int	ft_takenbr(char *file, int start, int size)
{
	char			nbr[12];
	int				i;
	int				intnbr;

	i = 0;
	while (i < size && i < 11)
	{
		nbr[i] = file[start + i];
		i++;
	}
	nbr[i] = 0;
	intnbr = ft_atoi(nbr);
	return (intnbr);
}

int	ft_takecolor(char *file, int start, int size)
{
	char			nbr[12];
	int				i;
	int				intnbr;

	i = 0;
	while (i < size && i < 11)
	{
		nbr[i] = file[start + i];
		i++;
	}
	nbr[i] = 0;
	intnbr = ft_hex_to_dec(nbr);
	return (intnbr);
}

void	ft_extract_colorandz(char *file, t_projection *map)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	map->z = malloc((map->height * map->width) * sizeof(int)); //CONTEMPLAR SI FALLA EL MALLOC
	map->color = malloc((map->height * map->width) * sizeof(int)); //CONTEMPLAR SI FALLA EL MALLOC
	while (file[i] && k < (map->height * map->width))
	{
		while (ft_isspace(file[i]))
			i++;
		j = i;
		while (ft_isdigit(file[i]) || file[i] == '-')
			i++;
		map->z[k] = ft_takenbr(file, j, i - j);
		if (file[i] == ',')
		{
			i += 9;
			map->color[k] = ft_takecolor(file, i - 6, 6);
		}
		else
			map->color[k] = 0;
		if (k % map->width == 0)
			ft_printf("Construido %d/%d\n", (k / map->width) + 1, map->height);
		k++;
	}
}

void	ft_readmap(int fd, t_projection *map)
{
	char	*line;
	char	*aux;

	map->height = 0;
	line = get_next_line(fd);
	map->width = ft_countwords(line);
	aux = ft_calloc(1, 1);
	while (line)
	{
		map->height++;
		if (map->width != ft_countwords(line))
		{
			ft_free_and_null((void **) &aux);
			ft_free_and_null((void **) &line);
			ft_printf("ERROR CON EL MAPA");
			exit(EXIT_FAILURE);
		}
		aux = ft_freeandjoin(aux, line);
		line = get_next_line(fd);
	}
	ft_extract_colorandz(aux, map);
	ft_free_and_null((void **) &aux);
}

void	ft_map_construct(char *file, t_projection *map)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo.\n");
		exit(EXIT_FAILURE);
	}
	ft_readmap(fd, map);
	close(fd);
}

int	main(int narg, char **argv)
{
	t_projection	map;
	int				i;

	if (narg != 2 || !argv[1])
		return (1);
	ft_map_construct(argv[1], &map);
	ft_printf("Descripción del mapa:\nAncho: %d \nAlto: %d\n", map.width, map.height);
	i = 0;
	while(i < (map.height * map.width))
	{
		ft_printf("(%d,", map.z[i]);
		ft_printf("%d)\t", map.color[i]);
		// ft_printf("%d ", map.z[i]);
		if (i != 0 && (i + 1) % map.width == 0)
			ft_printf("\n");
		i++;
	}
	ft_free_and_null((void **) &map.color);
	ft_free_and_null((void **) &map.z);
	return (0);
}

// #include "minilibx/mlx.h"
// int main(void)
// {
//     void    *mlx_ptr;
//     void    *win_ptr;
//     mlx_ptr = mlx_init();
//     win_ptr = mlx_new_window(mlx_ptr, 500, 500, "mlx 42");
//     mlx_loop(mlx_ptr);
//     return (0);
// }

// void draw_line(void *mlx_ptr, void *win_ptr, int x0, int y0, int x1, int y1, int color)
// {
//     int	dx = x1 - x0;
//     int dy = y1 - y0;
//     int sx, sy;

// 	if (dx < 0)
// 	{
// 		dx = -dx;
// 		sx = -1;
// 	}
// 	else
// 		sx = 1;
// 	if (dy < 0)
// 	{
// 		dy = -dy;
// 		sy = -1;
// 	}
// 	else
// 		sy = 1;
//     int err = dx - dy;
//     int x = x0;
//     int y = y0;

// 	while (x != x1 || y != y1) {
// 		mlx_pixel_put(mlx_ptr, win_ptr, x, y, color);
// 		int e2 = err * 2;
// 		if (e2 > - dy) {
// 			err -= dy;
// 			x += sx;
// 		}
//         if (e2 < dx)
// 		{
// 			err += dx;
// 			y += sy;
//         }
//     }
// }