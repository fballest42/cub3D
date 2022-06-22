/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2021/05/11 15:38:25 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_tex *tex)
{
	ft_getdefres(map, tex);
	map->mlx_ptr = mlx_init();
	ft_loadtex(map);
	if (map->save == 1)
		ft_raycasting(map);
	map->mlx_win = mlx_new_window(map->mlx_ptr, map->rx, map->ry, map->name);
	mlx_hook(map->mlx_win, 17, 1L << 17, ft_exit_game, map);
	mlx_hook(map->mlx_win, 2, 1L << 0, ft_keypress, map);
	mlx_hook(map->mlx_win, 3, 1L << 1, ft_keyrelease, map);
	mlx_loop_hook(map->mlx_ptr, ft_raycasting, map);
	mlx_loop(map->mlx_ptr);
	return (0);
}

int				ft_raycasting(t_map *map)
{
	int			x;

	x = 0;
	ft_key_hook(map);
	map->mlx_img = mlx_new_image(map->mlx_ptr, map->rx, map->ry);
	map->mlx_imgaddr = mlx_get_data_addr(map->mlx_img, &map->mlx_bxp,
		&map->mlx_sili, &map->mlx_endian);
	if (map->save == 1)
		map->mlx_sili = map->rx * 4;
	while (x < map->rx)
	{
		ft_setinfo(x, map);
		ft_initialstep(map);
		ft_hitwall(map);
		ft_heightdraw(map);
		ft_painttex(map);
		ft_verline(x, map);
		x++;
	}
	ft_raycastingb(map);
	if (map->save == 1)
		ft_copyimage(map);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	mlx_destroy_image(map->mlx_ptr, map->mlx_img);
	return (0);
}

void			ft_copyimage(t_map *map)
{
	t_bmp	*bmp;

	if (map->save == 1)
	{
		map->save++;
		if (!(bmp = malloc(sizeof(t_bmp))))
		{
			ft_printerr("Error\n23.- Failed while allocating memory");
			ft_freecopy(map, bmp);
			exit(-23);
		}
		ft_writeheader(map, bmp);
		ft_freecopy(map, bmp);
		exit(0);
	}
}

void			ft_writeheader(t_map *map, t_bmp *bmp)
{
	ft_initsave(map, bmp);
	write(bmp->fdsave, "B", sizeof(unsigned char));
	write(bmp->fdsave, "M", sizeof(unsigned char));
	write(bmp->fdsave, &bmp->filesize, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->offset_begin, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->header_bytes, sizeof(unsigned int));
	write(bmp->fdsave, &map->rx, sizeof(unsigned int));
	write(bmp->fdsave, &map->ry, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->bmpplane, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->bmpbxp, sizeof(unsigned short int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	write(bmp->fdsave, &bmp->unused, sizeof(unsigned int));
	ft_writebmp(map, bmp);
	close(bmp->fdsave);
}

void			ft_initsave(t_map *map, t_bmp *bmp)
{
	bmp->filesize = 54 + map->ry * map->mlx_sili;
	bmp->pixelsize = (map->ry * map->rx);
	bmp->unused = 0;
	bmp->offset_begin = 54;
	bmp->header_bytes = 40;
	bmp->bmpplane = 1;
	bmp->bmpbxp = map->mlx_bxp;
	bmp->fdsave = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (bmp->fdsave < 0)
	{
		ft_printerr("Error\n22.- Screenshot file not created");
		ft_freecopy(map, bmp);
		exit(-22);
	}
}
