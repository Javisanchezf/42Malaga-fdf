/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color_and_z.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:07:49 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/15 12:20:30 by javiersa         ###   ########.fr       */
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

void	takecoloraux(char *file, int *i, uint8_t *color)
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
	fdf->map[position].r = 255;
	fdf->map[position].g = 140;
	fdf->map[position].b = 0;
	fdf->map[position].a = 255;
	if (file[*i] == ',' && file[*i + 1] == '0' && file[*i + 2] == 'x')
	{
		*i += 3;
		if (ft_isalnum(file[*i]) && ft_isalnum(file[*i + 1]))
			takecoloraux(file, i, &fdf->map[position].r);
		if (ft_isalnum(file[*i]) && ft_isalnum(file[*i + 1]))
			takecoloraux(file, i, &fdf->map[position].g);
		if (ft_isalnum(file[*i]) && ft_isalnum(file[*i + 1]))
			takecoloraux(file, i, &fdf->map[position].b);
		if (ft_isalnum(file[*i]) && ft_isalnum(file[*i + 1]))
			takecoloraux(file, i, &fdf->map[position].a);
	}
}

void	create_initial_map(char *file, t_fdfvariables *fdf)
{
	fdf->map = ft_calloc((fdf->map_height * fdf->map_width), sizeof(t_fdfmap));
	if (!fdf->map)
		ft_error("Problem allocating memory, try freeing up space.", 1, file);
	fdf->z_max = 0;
	fdf->zoom = 0;
	fdf->z_zoom = 0.4;
	fdf->x_zoom = 1;
	fdf->radians = 0;
	fdf->view = 'I';
}

void	ft_extract_colorandz(char *file, t_fdfvariables *fdf)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	create_initial_map(file, fdf);
	while (file[i] && k < (fdf->map_height * fdf->map_width))
	{
		while (ft_isspace(file[i]))
			i++;
		j = i;
		while (ft_isdigit(file[i]) || file[i] == '-')
			i++;
		fdf->map[k].z = ft_takenbr(file, j, i - j);
		if (fdf->map[k].z > fdf->z_max)
			fdf->z_max = fdf->map[k].z;
		ft_takecolor(file, fdf, &i, k);
		if (k % fdf->map_width == 0)
			ft_printf("Construido %d/%d\n", (k / fdf->map_width) + 1, fdf->map_height);
		k++;
	}
}
