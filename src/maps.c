/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/11 20:09:27 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/11 23:34:04 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	read_map(char *filename)
{
	int		fd;
	char	*line;
	char	*temp;
	t_map	map;

	fd = open(filename, O_RDONLY);
	temp = ft_strdup("");
	line = get_next_line(fd);
	map.y_max = -1;
	while (line)
	{
		map.y_max++;
		temp = ft_strmerge(temp, line);
		line = get_next_line(fd);
	}
	free(line);
	map.str_map = ft_split(temp, '\n');
	free(temp);
	return (map);
}
