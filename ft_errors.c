/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/29 12:15:12 by fballest          #+#    #+#             */
/*   Updated: 2020/10/26 18:29:25 by fballest         ###   ########.fr       */
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
	err->err6 = "Error\n6.- No such file or directory for NO texture.\n";
	err->err7 = "Error\n7.- No such file or directory for SO texture.\n";
	err->err8 = "Error\n8.- No such file or directory for WE texture.\n";
	err->err9 = "Error\n9.- No such file or directory for EA texture.\n";
	err->err10 = "Error\n10.- No such file or directory for SPRITE texture.\n";
	err->err11 = "Error\n11.- No ceiling colour defined.\n";
	err->err12 = "Error\n12.- No floor colour defined.\n";
	err->err13 = "Error\n13.- Wrong colour for ceiling or floor.\n";
	err->err14 = "Error\n14.- Duplicate resolution.\n";
	err->err15 = "Error\n15.- Not valid map.\n";
	err->err16 = "Error\n16.- More than one player on map.\n";
	err->err17 = "Error\n17.- .\n";
	err->err18 = "Error\n18.- .\n";
	err->err19 = "Error\n19.- .\n";
	err->err20 = "Error\n20.- .\n";
	err->err21 = "Error\n21.- .\n";
	err->err22 = "Error\n22.- .\n";
	err->err23 = "Error\n23.- .\n";
	err->err24 = "Error\n24.- .\n";
}

void			ft_printerr(char *str)
{
	write(1, str, ft_strlenb(str));
}

int				ft_duplicateres(int y, t_map *map, t_err *err)
{
	if (map->file[y] == 'R' && map->res > 0)
	{
		ft_printerr(err->err14);
		return (-14);
	}
	return (0);
}
