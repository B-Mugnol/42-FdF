/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmugnol- <bmugnol-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 22:33:41 by bmugnol-          #+#    #+#             */
/*   Updated: 2022/01/28 19:23:10 by bmugnol-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	param_checker(int argc, char *map_file)
{
	char	*file_extension;

	if (argc < 2)
		return (arg_error("fdf", "Too few arguments."));
	if (argc > 2)
		return (arg_error("fdf", "Too many arguments."));
	file_extension = ft_strrchr(map_file, '.');
	if (!file_extension || ft_strncmp(file_extension, ".fdf", 4))
		return (arg_error("fdf", "Wrong file extension."));
	if (file_extension != ft_strchr(map_file, '.'))
		return (arg_error("fdf", "Filename cannot contain '.' character."));
	if (file_extension == map_file)
		return (arg_error("fdf", "Dotfiles are not allowed."));
	return (1);
}
