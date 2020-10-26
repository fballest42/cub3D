/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_inundacion.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 15:43:00 by fballest          #+#    #+#             */
/*   Updated: 2020/10/02 13:07:53 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>

void			ft_imprimelo(char *mapa)
{
	int		x;

	x = 0;
	while (mapa[x])
	{
		printf("%s\n", mapa);
		x++;
	}
}

int             main()
{
	char    **map = NULL;
	int     x = 0;
	int     y = 0;
	int		a = 0;
	int		b = 0;
	int		j = 0;
	int		k = 0;
	char	c = '0';

	if (!(map = (char **)malloc(11*sizeof(char *))))
		return (-1);
	while (x < 10)
	{
		if (!(map[x] = (char *)malloc(11*sizeof(char))))
			return (-1);
		x++;
	}
	x = 0;
	map[0] = "1111111111";
	map[1] = "100000 001";
	map[2] = "10 0000001";
	map[3] = "1000  0001";
	map[4] = "1000  0001";
	map[5] = "1000030000";
	map[6] = "1000000001";
	map[7] = "1000000001";
	map[8] = "1000000001";
	map[9] = "1111111111";

	if (!*map)
	{
		printf("%s\n", "NO EXISTE NINGUN MAPA");
		return (-1);
	}
	while (map[x])
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			if (map[x][y] == 51)
				j++;
			y++;
		}
		x++;
	}
	if (j > 1 || j < 1)
	{
		printf("%s\n", "NUMERO DE JUGADORES INCORRECTO EN EL MAPA");
		return (-1);
	}
	x = 0;
	y = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y] != '\0')
		{
			while (map[x][y] == '1' || map[x][y] == '0' || map[x][y] == ' ')
				y++;
			/*if (map[x][y] == ' ')
			{
				write(1, "C\n", 2);
				//map[x][y] = c;
				write(1, "D\n", 2);
				y++;
			}*/
			if (map[x][y] == '3')
			{
				a = y - 1;
				b = y + 1;
				j = x - 1;
				k = x + 1;
				write(1, "AQUI1\n", 6);
		   		if (map[j][a] == '\0' || map[j][y] == '\0' || map[j][b] == '\0' 
					|| map[x][a] == '\0' || map[x][b] == '\0' || map[k][a] == '\0'
					|| map[k][y] == '\0' || map[k][b] == '\0')
				{
					write(1, "AQUI2\n", 6);

					printf("%s\n", "ERROR EL MAPA ESTA ABIERTO");
					return(-1);
				}
				else
				{
					if (map[j][a] == '0' || map[j][a] == ' ' || map[j][a] == '2')
						map[j][a] = '3';
					if (map[j][y] == '0' || map[j][y] == ' ' || map[j][y] == '2')
						map[j][y] = '3';
					if (map[j][b] == '0' || map[j][b] == ' ' || map[j][b] == '2')
						map[j][b] = '3';
					if (map[x][a] == '0' || map[x][a] == ' ' || map[x][a] == '2')
						map[x][a] = '3';
					if (map[x][b] == '0' || map[x][b] == ' ' || map[x][b] == '2')
						map[x][b] = '3';
					if (map[k][a] == '0' || map[k][a] == ' ' || map[k][a] == '2')
						map[k][a] = '3';
					if (map[k][y] == '0' || map[k][y] == ' ' || map[k][y] == '2')
						map[k][y] = '3';
					if (map[k][b] == '0' || map[k][b] == ' ' || map[k][b] == '2')
						map[k][b] = '3';
					if (map[j][b] == '0' || map[j][b] == ' ' || map[j][b] == '2')
						map[j][b] = '3';
				}
			}
			y++;
		}
		x++;
	}
	printf("%s\n", "MAPA OK");
	//ft_imprimelo(map);
	return (0);
}
