/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:20 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/06 13:27:30 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

void	takecoloraux(char *file, int *i, int *color)
{
	char		nbr[3];

	nbr[0] = file[*i + 1];
	nbr[1] = file[*i + 2];
	nbr[2] = 0;
	*color = ft_hex_to_dec(nbr);
	*i += 2;
}

void	ft_takecolor(char *file, t_fdfvariables *fdf, int *i, int position)
{
	(*i)++;
	if (ft_isalnum(file[*i + 1]) && ft_isalnum(file[*i + 2]))
		takecoloraux(file, i, &fdf->map[position].r);
	if (ft_isalnum(file[*i + 1]) && ft_isalnum(file[*i + 2]))
		takecoloraux(file, i, &fdf->map[position].g);
	if (ft_isalnum(file[*i + 1]) && ft_isalnum(file[*i + 2]))
		takecoloraux(file, i, &fdf->map[position].b);
	if (ft_isalnum(file[*i + 1]) && ft_isalnum(file[*i + 2]))
		takecoloraux(file, i, &fdf->map[position].a);
	else
		fdf->map[position].a = 255;
}

void	ft_extract_colorandz(char *file, t_fdfvariables *fdf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	fdf->map = ft_calloc((fdf->map_height * fdf->map_width), sizeof(t_fdfmap)); //Le falta proteccion y salirse del royo
	fdf->zoom = 0;
	while (file[i] && k < (fdf->map_height * fdf->map_width))
	{
		while (ft_isspace(file[i]))
			i++;
		j = i;
		while (ft_isdigit(file[i]) || file[i] == '-')
			i++;
		fdf->map[k].z = ft_takenbr(file, j, i - j);
		if (file[i] == ',')
			ft_takecolor(file, fdf, &i, k);
		if (k % fdf->map_width == 0)
			ft_printf("Construido %d/%d\n", (k / fdf->map_width) + 1, fdf->map_height);
		k++;
	}
}

void	ft_readmap(int fd, t_fdfvariables *fdf)
{
	char	*line;
	char	*aux;

	fdf->map_height = 0;
	line = get_next_line(fd);
	fdf->map_width = ft_count_words(line);
	aux = ft_calloc(1, 1);
	while (line)
	{
		fdf->map_height++;
		if (fdf->map_width != ft_count_words(line))
		{
			ft_free_and_null((void **) &aux);
			ft_free_and_null((void **) &line);
			ft_printf("ERROR CON EL MAPA");
			exit(EXIT_FAILURE);
		}
		aux = ft_freeandjoin(aux, line);
		line = get_next_line(fd);
	}
	ft_extract_colorandz(aux, fdf);
	ft_free_and_null((void **) &aux);
}

void	ft_normalize(t_fdfvariables	*fdf)
{
	int	i;
	int	lower_x;
	int	lower_y;

	i = -1;
	fdf->window_height = 0;
	fdf->window_width = 0;
	lower_x = 0;
	lower_y = 0;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		if (lower_x > fdf->map[i].x_iso)
			lower_x = fdf->map[i].x_iso;
		if (lower_y > fdf->map[i].y_iso)
			lower_y = fdf->map[i].y_iso;
		if (fdf->window_width < fdf->map[i].x_iso)
			fdf->window_width = fdf->map[i].x_iso;
		if (fdf->window_height < fdf->map[i].y_iso)
			fdf->window_height = fdf->map[i].y_iso;
	}
	i = -1;
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_iso -= lower_x;
		fdf->map[i].y_iso -= lower_y;
	}
	fdf->window_width -= lower_x;
	fdf->window_height -= lower_y;
	ft_printf("WW: %d, WH %d\n", fdf->window_width, fdf->window_height);
}

void	ft_views_and_zoom(t_fdfvariables	*fdf)
{
	int	i;

	i = -1;
	if (fdf->zoom == 0) //Para nada mas iniciar el mapa o cuando el zoom sea 0, puede que en el futuro no sirva y se eliminaria zoom=0 despues del calloc
	{
		if ((HEIGHT / fdf->map_height) > (WIDTH / fdf->map_width))
			fdf->zoom = (HEIGHT / fdf->map_height) / 2;
		else
			fdf->zoom = (WIDTH / fdf->map_width) / 2;
	}
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_iso = ((((i / fdf->map_width) * fdf->zoom)- \
		((i % fdf->map_width)) * fdf->zoom) * cos(0.523599));
		fdf->map[i].y_iso = ((((i / fdf->map_width) * fdf->zoom) + \
		((i % fdf->map_width)) * fdf->zoom) * sin(0.523599) - (fdf->map[i].z) * fdf->zoom);
	}
	ft_normalize(fdf);
}

void	ft_map_construct(char *file, t_fdfvariables	*fdf)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error al abrir el archivo.\n");
		exit(EXIT_FAILURE);
	}
	ft_readmap(fd, fdf);
	ft_views_and_zoom(fdf);
	close(fd);
}

int	main(int narg, char **argv)
{
	t_fdfvariables	fdf;
	int				i;

	if (narg != 2 || !argv[1])
		return (1);
	ft_map_construct(argv[1], &fdf);
	ft_printf("Descripción del mapa:\nAncho: %d \nAlto: %d\n", fdf.map_width, fdf.map_height);
	i = 0;
	while(i < (fdf.map_height * fdf.map_width))
	{
		ft_printf("%d\t", fdf.map[i].z);
		if (i != 0 && (i + 1) % fdf.map_width == 0)
			ft_printf("\n");
		i++;
	}
	i = 0;
	while(i < (fdf.map_height * fdf.map_width))
	{
		ft_printf("(%d, %d)", fdf.map[i].x_iso, fdf.map[i].y_iso);
		if (i != 0 && (i + 1) % fdf.map_width == 0)
			ft_printf("\n");
		i++;
	}
	ft_free_and_null((void **) &fdf.map);
	return (0);
}


// void bresenham(int x1, int y1, int x2, int y2)
// {
// 	int dx = abs(x2 - x1);
// 	int dy = abs(y2 - y1);
// 	int sx, sy;

// 	if (x1 < x2)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (y1 < y2)
// 		sy = 1;
// 	else
// 		sy = -1;

// 	int err = dx - dy;
// 	int e2;
// 	int x = x1;
// 	int y = y1;

// 	while (1)
// 	{
// 		printf("(%d, %d)\n", x, y);
// 		if (x == x2 && y == y2)
//             break;
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			x += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			y += sy;
// 		}
// 	}
// }