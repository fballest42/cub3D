/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:15:12 by fballest          #+#    #+#             */
/*   Updated: 2020/11/13 00:13:29 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void			ft_inierr(t_err *err)
{
	err->err1 = "Error\n1.- Invalid number of arguments.\n";
	err->err2 = "Error\n2.- Not valid map extension.\n";
	err->err3 = "Error\n3.- Invalid arguments.\n";
	err->err4 = "Error\n4.- Could not open the file.\n";
	err->err5 = "Error\n5.- Not defined or not valid resolution.\n";
	err->err6 = "Error\n6.- Not a valid texture extension.\n";
	err->err7 = "Error\n7.- Not valid info on Resolution, Ceiling or Floor.\n";
	err->err8 = "Error\n8.- Ceiling or Floor must use ',' between values.\n";
	err->err9 = "Error\n9.- Blank line in the middle of the map.\n";
	err->err10 = "Error\n10.- No such file or directory for texture file.\n";
	err->err11 = "Error\n11.- No ceiling colour defined.\n";
	err->err12 = "Error\n12.- No floor colour defined.\n";
	err->err13 = "Error\n13.- Wrong colour for ceiling or floor.\n";
	err->err14 = "Error\n14.- Duplicate parameter.\n";
	err->err15 = "Error\n15.- Not valid map.\n";
	err->err16 = "Error\n16.- Wrong number of players on map.\n";
	err->err17 = "Error\n17.- Not valid parameters in the map file.\n";
	err->err18 = "Error\n18.- Not valid symbols included in the map.\n";
	err->err19 = "Error\n19.- Could not open a texture file.\n";
	err->err20 = "Error\n20.- Not valid texture extension.\n";
	err->err21 = "Error\n21.- Not a coma between colours.\n";
	err->err22 = "Error\n22.- .\n";
	err->err23 = "Error\n23.- .\n";
	err->x = 0;
	err->ok = 0;
}

void			ft_printerr(char *str)
{
	write(1, str, ft_strlenb(str));
}

int				ft_duplicateres(int y, t_map *map, t_err *err)
{
	if (map->file[y] == 'R' && map->res > 1)
	{
		ft_printerr(err->err14);
		exit(-14);
	}
	return (0);
}

int				ft_checktexture(char *str, t_err *err)
{
	char		*ext;
	int			y;

	y = 0;
	ext = ft_extfile(str);
	y = ft_strlenb(ext);
	if (ft_strncmpb(ext, ".xpm", y) == 0)
		return (0);
	else
	{
		ft_printerr(err->err6);
		exit(-6);
	}
}
