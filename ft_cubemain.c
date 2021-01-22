/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cubemain.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 09:21:00 by fballest          #+#    #+#             */
/*   Updated: 2021/01/22 13:49:55 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int				ft_cubemain(t_map *map, t_tex *tex)
{
	ft_getdefres(map, tex);
	map->mlx_ptr = mlx_init();
	ft_loadtex(map);
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
	ft_copyimage(map);
	mlx_put_image_to_window(map->mlx_ptr, map->mlx_win, map->mlx_img, 0, 0);
	mlx_destroy_image(map->mlx_ptr, map->mlx_img);
	return (0);
}

void			ft_copyimage(t_map *map)
{
	if (map->save == 1)
	{
		ft_exportbmp(map);
	}
}

void			ft_fillbmp(char **data, t_map *map)
{
	int i;
	int j;
	int x;
	int y;

	i = HEADER_SIZE;
	y = map->ry;
	while (y--)
	{
		x = -1;
		while (++x < map->rx)
		{
			j = (x * (map->mlx_bxp / 8)) + (y * map->mlx_sili);
			*(*data + i++) = *(map->mlx_imgaddr + j++);
			*(*data + i++) = *(map->mlx_imgaddr + j++);
			*(*data + i++) = *(map->mlx_imgaddr + j);
		}
	}
}

/*
** Initialize the header of bmp (char *data)
**
** HEADER
** Position | Hex	| Description
** 00		| 00	| TYPE OF BMP FILE
** 02		| 02	| TOTAL SIZE OF FILE
** 06-08	| 06-08	| RESERVED TO SIGN
** 10		| 0A	| HEADER SIZE
** =============================================================================
** HEADER INFOS
** Position | Hex	| Description
** 14		| 0E	| HEADER INFOS SIZE
** 18		| 12	| WIDTH OF IMG (PX)
** 22		| 16	| HEIGHT OF IMG (PX)
** 26		| 1A	| NUMBER OF PLANS
** 28		| 1C	| BITS PER PIXELS (1 - 4 - 8 - 24)
** 30		| 1E	| COMPRESSION TYPE
** 34		| 22	| SIZE OF IMG
** 38		| 26	| RES X PX PER METER
** 42		| 2A	| RES Y PX PER METER
** 46		| 2E	| NB OF USED COLOR (0 = MAX)
** 50		| 32	| NB OF INDEX OF COLOR (0 = ALL)
*/

void			ft_headerbmp(char **data, t_map *map)
{
	unsigned int size;

	size = map->rx * map->ry * 3;
	*(unsigned short *)*data = *(const unsigned int *)(unsigned long)"BM";
	*(unsigned int *)(*data + 2) = (size + HEADER_SIZE);
	*(unsigned int *)(*data + 6) = 0u;
	*(unsigned char *)(*data + 10) = HEADER_SIZE;
	*(unsigned int *)(*data + 14) = HEADER_SIZE - 14;
	*(unsigned int *)(*data + 18) = map->rx;
	*(unsigned int *)(*data + 22) = map->ry;
	*(unsigned short *)(*data + 26) = 1;
	*(unsigned short *)(*data + 28) = 24;
	*(unsigned int *)(*data + 30) = 0;
	*(unsigned int *)(*data + 34) = (unsigned int)size;
	*(unsigned int *)(*data + 38) = 3780;
	*(unsigned int *)(*data + 42) = 3780;
	*(int *)(*data + 46) = 0;
	*(int *)(*data + 50) = 0;
}

/*
** Create bmp (char *data), put header and fill it, then put result into
** filename (*.bmp).
*/

void			ft_exportbmp(t_map *map)
{
	int				fd;
	unsigned int	size;
	unsigned int	i;
	char			*data;

	size = map->rx * map->ry * 3;
	if (!(data = malloc((size + HEADER_SIZE))))
		exit(-7);
	i = 0;
	while (i < size + HEADER_SIZE)
		data[i++] = 0;
	ft_headerbmp(&data, map);
	ft_fillbmp(&data, map);
	if ((fd = open("screemshot.bmp", O_CREAT | O_TRUNC | O_RDWR, 7777)) <= 0)
		exit(-8);
	write(fd, &data, (size + HEADER_SIZE));
	close(fd);
}

char			*ft_bmpfile(char *file, int i)
{
	char		*filename;
	int			n;

	if (!(filename = malloc(sizeof(char) * (i + 5))))
		exit(-7);
	n = -1;
	while (++n <= i)
		*(filename + n) = *(file + n);
	*(unsigned int *)(filename + n) =
	*(const unsigned int *)(unsigned long)"bmp\0";
	return (filename);
}

/*void			ft_copyimage(t_map *map)
{
	t_bmp	*bmp;


	if (map->save == 1)
	{
		map->save++;
		if (!(bmp = malloc(sizeof(t_bmp))))
			exit(-23);
		ft_initsave(map, bmp);
		ft_writeheader(map, bmp);
		ft_writebmp(map, bmp);
		close(bmp->fdsave);
		free(bmp);
		exit(0);
	}
}

void			ft_writeheader(t_map *map, t_bmp *bmp)
{
	write(bmp->fdsave, "BM", 2);
	write(bmp->fdsave, &bmp->filesize, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->offset_begin, sizeof(int));
	write(bmp->fdsave, &bmp->header_bytes, sizeof(int));
	write(bmp->fdsave, &map->rx, sizeof(int));
	write(bmp->fdsave, &map->ry, sizeof(int));
	write(bmp->fdsave, &bmp->bmpplane, sizeof(short int));
	write(bmp->fdsave, &bmp->bmpbxp, sizeof(short int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));
	write(bmp->fdsave, &bmp->unused, sizeof(int));

}

void			ft_initsave(t_map *map, t_bmp *bmp)
{
	bmp->bmpbxp = map->mlx_bxp / 8;
	bmp->filesize = (map->ry * map->rx * bmp->bmpbxp) + 48;
	bmp->pixelsize = (map->ry * map->rx * bmp->bmpbxp);
	bmp->unused = 0;
	bmp->offset_begin = 48;
	bmp->header_bytes = 40;
	bmp->bmpplane = 1;
	bmp->fdsave = open("screenshot.bmp", O_RDWR | O_CREAT, S_IRWXU | O_TRUNC);
	if (bmp->fdsave < 0)
	{
		ft_printerr("Error\n22.- Screenshot file not created");
		exit(-22);
	}
}

void			ft_writebmp(t_map *map, t_bmp *bmp)
{
	int		y;
	int		x;
	int		line;

	y = 0;
	while (y < map->ry)
	{
		x = 0;
		line = map->rx * (map->ry - y);
		while (x < map->rx)
		{
			write(bmp->fdsave, &map->mlx_imgaddr[line * bmp->bmpbxp], bmp->bmpbxp);
			line++;
			x++;
		}
		y++;
	}
}*/
void				screenshot(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, mlx->config->resolutionwidth,
							mlx->config->resolutionheight);
	mlx->img_addr = mlx_get_data_addr(mlx->img, &mlx->bpp,
							&mlx->line_lenght, &mlx->endian);
	mlx->player.mapx = (int)mlx->player.posx;
	mlx->player.mapy = (int)mlx->player.posy;
	move_player(mlx);
	raycasting(mlx);
	if (mlx->enablesprite)
		draw_sprites(mlx);
	mlx_destroy_image(mlx->mlx, mlx->img);
	take_screenshot(mlx);
	exit_succes(mlx);
}

void				write_data_header(t_mlx *mlx, int size, int fd)
{
	unsigned char	header[54];

	ft_bzero(header, 54);
	header[0] = (unsigned char)('B');
	header[1] = (unsigned char)('M');
	header[2] = (unsigned char)(size);
	header[3] = (unsigned char)(size >> 8);
	header[4] = (unsigned char)(size >> 16);
	header[5] = (unsigned char)(size >> 24);
	header[10] = (unsigned char)(54);
	header[14] = (unsigned char)(40);
	header[18] = (unsigned char)(map->rx);
	header[19] = (unsigned char)(map->rx >> 8);
	header[20] = (unsigned char)(map->rx >> 16);
	header[21] = (unsigned char)(mlx->config->resolutionwidth >> 24);
	header[22] = (unsigned char)(-mlx->config->resolutionheight);
	header[23] = (unsigned char)(-mlx->config->resolutionheight >> 8);
	header[24] = (unsigned char)(-mlx->config->resolutionheight >> 16);
	header[25] = (unsigned char)(-mlx->config->resolutionheight >> 24);
	header[26] = (unsigned char)(1);
	header[28] = (unsigned char)(32);
	write(fd, header, 54);
}

void				take_screenshot(t_mlx *mlx)
{
	int				fd;
	int				size;
	char			*tmp;
	int				width;

	if ((fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 0777)) < 0)
		error_exit("no se pudo hacer la captura de pantalla");
	width = mlx->config->resolutionwidth;
	size = 54 + (width + mlx->config->resolutionheight) * 4;
	write_data_header(mlx, size, fd);
	tmp = (char *)mlx->img_addr;
	write(fd, tmp, (width * mlx->config->resolutionheight * 4));
	close(fd);
	exit(EXIT_SUCCESS);
}
