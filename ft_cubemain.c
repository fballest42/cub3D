/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2020/10/16 12:42:50 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int			ft_cubemain(t_map *map, t_err *err, t_tex *tex)
{
	printf("RESOLUCION X %d\nRESOLUCION Y %d\n", map->rx, map->ry);
	printf("TEXTURA NO %s\nTEXTURA SO %s\nTEXTURA WE %s\nTEXTURA EA %s\nTEXTURA SP %s\n CEILING RGB %d,%d,%d\n FLOOR RGB %d,%d,%d\n", tex->rutano, tex->rutaso, tex->rutawe, tex->rutaea, tex->rutasp, tex->cei[1], tex->cei[2], tex->cei[3], tex->flo[1], tex->flo[2], tex->flo[3]);
	free(tex->rutano);
	tex->rutano = NULL;
	free(tex->rutaso);
	tex->rutaso = NULL;
	free(tex->rutawe);
	tex->rutawe = NULL;
	free(tex->rutaea);
	tex->rutaea = NULL;
	free(tex->rutasp);
	tex->rutasp = NULL;
	free(tex);
	free(map);
	free(err);




	return (0);
}
