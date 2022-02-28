/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:33:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/02/24 20:34:19 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	is_valid_file_extension(const char *file, const char *ext);

int	fd_verifier(int fd)
{
	if (fd < 0)
	{
		fd_error("open", "Failed to open file.");
		return (1);
	}
	return (0);
}

int	data_verifier(t_data *data)
{
	if (data->is_valid > 0)
		return (0);
	dismount_mlx(data);
	return (1);
}

int	param_verifier(const int argc, const char *map_file)
{
	if (argc < 2)
		return (arg_error("fdf", "Too few arguments."));
	if (argc > 2)
		return (arg_error("fdf", "Too many arguments."));
	if (!is_valid_file_extension(map_file, ".fdf"))
		return (arg_error("fdf", "Invalid file name or extension."));
	return (0);
}

static int	is_valid_file_extension(const char *file, const char *ext)
{
	size_t	ext_len;
	size_t	file_len;

	if (!file || !ext)
		return (0);
	ext_len = ft_strlen(ext);
	file_len = ft_strlen(file);
	if (file_len <= ext_len)
		return (0);
	if (ft_strncmp(file + file_len - ext_len, ext, ext_len) != 0)
		return (0);
	return (1);
}
