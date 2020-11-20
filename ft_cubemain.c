/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/11/20 12:42:14 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	int		i;

	i = 0;
	printf("RESOLUCION X %d\nRESOLUCION Y %d\n", map->rx, map->ry);
	printf("TEXTURA NO %s\nTEXTURA SO %s\nTEXTURA WE %s\nTEXTURA EA %s\nTEXTURA SP %s\n CEILING RGB %d %d %d\n FLOOR RGB %d %d %d\n", tex->rutano, tex->rutaso, tex->rutawe, tex->rutaea, tex->rutasp, tex->cei[1], tex->cei[2], tex->cei[3], tex->flo[1], tex->flo[2], tex->flo[3]);
	
	while (map->mapa[i] != 0 && i <= 50)
	{
		printf("\nESTE ES EL MAPA\n%s\n", map->mapa[i]);
		i++;
	}
	printf("ESTE NO ES UN ERROR DE SALIDA %s ", err->err10);
	return (0);
}
