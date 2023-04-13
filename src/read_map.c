/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: javiersa <javiersa@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 17:51:20 by javiersa          #+#    #+#             */
/*   Updated: 2023/04/13 20:21:06 by javiersa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_readmap(int fd, t_fdfvariables *fdf)
{
	char	*line;
	char	*aux;

	fdf->map_height = 0;
	aux = ft_calloc(1, 1);
	if (!aux)
		error("ERROR: Problem allocating memory, try freeing up space.");
	line = get_next_line(fd);
	if (!line)
		error("ERROR: Problem allocating memory, try freeing up space.");
	fdf->map_width = ft_count_words(line);
	while (line && ++fdf->map_height)
	{
		if (fdf->map_width != ft_count_words(line))
		{
			ft_free_and_null((void **) &aux);
			ft_free_and_null((void **) &line);
			error("ERROR: The file does not contain a valid map.");
		}
		aux = ft_freeandjoin(aux, line);
		line = get_next_line(fd);
	}
	ft_extract_colorandz(aux, fdf);
	ft_multiple_free(2, aux, line);
}

void	ft_map_construct(char *file, t_fdfvariables	*fdf)
{
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		error("ERROR: Could not read the file.");
	ft_readmap(fd, fdf);
	ft_views_and_zoom(fdf);
	close(fd);
}
