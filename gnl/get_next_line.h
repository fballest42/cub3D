/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fballest <fballest@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/10 09:13:23 by fballest          #+#    #+#             */
/*   Updated: 2020/10/15 14:02:16 by fballest         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _GET_NEXT_LINE_H
# define _GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

#define BUFFER_SIZE 25

char			*ft_strchrc(const char *s, int c);
size_t			ft_strlenc(const char *str);
char			*ft_strdupc(const char *s1);
char			*ft_strjoinc(char const *s1, char const *s2);
char			*ft_substrc(char const *s, unsigned int start, size_t len);
int				get_next_line(int fd, char **line);

#endif
