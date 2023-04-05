/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:20 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/05 12:58:06 by javiersa         ###   ########.fr       */
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
	fdf->map = ft_calloc((fdf->map_height * fdf->map_width), sizeof(t_fdfmap)); //CONTEMPLAR SI FALLA EL MALLOC
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

void	ft_initial_views_and_zoom(t_fdfvariables	*fdf)
{
	int	i;

	i = -1;
	if ((fdf->map_height / HEIGHT) > (fdf->map_width / WIDTH))
		fdf->zoom = (fdf->map_height / HEIGHT);
	else
		fdf->zoom = (fdf->map_width / WIDTH);
	while (++i < (fdf->map_height * fdf->map_width))
	{
		fdf->map[i].x_iso = (((i / fdf->map_width) - \
		(i % fdf->map_width)) * cos(30)) * fdf->zoom;
		fdf->map[i].y_iso = (((i / fdf->map_width) + \
		(i % fdf->map_width)) * sin(30) - fdf->map[i].z) * fdf->zoom;
	}
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
	ft_initial_views_and_zoom(fdf);
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
		ft_printf("(%d,", fdf.map[i].z);
		if (i != 0 && (i + 1) % fdf.map_width == 0)
			ft_printf("\n");
		i++;
	}
	ft_free_and_null((void **) &fdf.map);
	return (0);
}
