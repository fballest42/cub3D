/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:07:09 by fballest          #+#    #+#             */
/*   Updated: 2020/10/06 08:57:18 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_delline(char **del)
{
	if (del != NULL && *del != NULL)
	{
		free(*del);
		*del = NULL;
	}
}

static int		ft_addline(char **aux, char **line, int fd)
{
	int			len;
	char		*tmp;

	len = 0;
	while (aux[fd][len] != '\n')
		len++;
	*line = ft_substrc(aux[fd], 0, len);
	tmp = ft_strdupc(&aux[fd][len + 1]);
	free(aux[fd]);
	aux[fd] = tmp;
	return (1);
}

static int		ft_salida(char **aux, char **line, int cnt, int fd)
{
	if (cnt < 0)
		return (-1);
	else if (cnt == 0 && (aux[fd] == NULL || aux[fd][0] == '\0'))
	{
		*line = ft_strdupc("");
		ft_delline(&aux[fd]);
		return (0);
	}
	else if (ft_strchrc(aux[fd], '\n'))
		return (ft_addline(aux, line, fd));
	else
	{
		*line = ft_strdupc(aux[fd]);
		ft_delline(&aux[fd]);
		return (0);
	}
}

int				get_next_line(int fd, char **line)
{
	char			*buff;
	static char		*aux[4096];
	char			*tmp;
	int				cnt;

	if (!line || fd < 0 || BUFFER_SIZE < 1 ||
		(!(buff = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1)))))
		return (-1);
	while ((cnt = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[cnt] = '\0';
		if (aux[fd] == NULL)
			aux[fd] = ft_strdupc(buff);
		else
		{
			tmp = ft_strjoinc(aux[fd], buff);
			free(aux[fd]);
			aux[fd] = tmp;
		}
		if (ft_strchrc(aux[fd], '\n'))
			break ;
	}
	free(buff);
	return (ft_salida(aux, line, cnt, fd));
}
