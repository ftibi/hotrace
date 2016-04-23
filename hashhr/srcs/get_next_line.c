/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tguillot <tguillot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 13:22:54 by tguillot          #+#    #+#             */
/*   Updated: 2016/04/23 11:38:00 by tguillot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/hotrace.h"

static int	ft_checksav(int fd, char **sav, char **line, int *c)
{
	char	*tmp;
	int		a;

	a = 0;
	if (*c != 0)
		a = *c;
	if (sav[fd] != NULL)
	{
		while (sav[fd][a] != '\0')
		{
			if (sav[fd][a] == '\n')
			{
				tmp = sav[fd];
				*line = ft_strsub(sav[fd], 0, a);
				sav[fd] = ft_strsub(sav[fd], (a + 1), (ft_strlen(sav[fd]) - a));
				free(tmp);
				return (1);
			}
			a++;
		}
		*c = a;
	}
	return (0);
}

static int	ft_read(int fd, char **sav)
{
	char	*tmp;
	char	str[BUFF_SIZE + 1];
	int		ret;

	ft_bzero(str, (BUFF_SIZE + 1));
	ret = read(fd, str, BUFF_SIZE);
	if (ret == -1)
		return (-1);
	else if (sav[fd] == NULL)
		sav[fd] = ft_strnew(ret);
	tmp = sav[fd];
	sav[fd] = ft_strjoin(sav[fd], str);
	if (tmp != NULL)
		free(tmp);
	return (ret);
}

static int	ft_end(int b, int fd, char **sav, char **line)
{
	char *tmp;

	if (sav[fd] && b == 0 && sav[fd][0] != '\0' && sav[fd][0] != '\n')
	{
		tmp = sav[fd];
		*line = ft_strdup(sav[fd]);
		sav[fd] = NULL;
		free(tmp);
		return (1);
	}
	*line = NULL;
	return (0);
}

int			get_next_line(int const fd, char **line)
{
	static char	*sav[FD_SIZE];
	int			b;
	int			c;

	c = 0;
	if (!line || fd < 0 || BUFF_SIZE < 1 || fd >= FD_SIZE)
		return (-1);
	else if (ft_checksav(fd, &sav[fd], line, &c) == 1)
		return (1);
	while ((b = ft_read(fd, &sav[fd])))
	{
		if (b == -1)
			return (-1);
		else if (ft_checksav(fd, &sav[fd], line, &c) == 1)
			return (1);
	}
	if (ft_end(b, fd, &sav[fd], line) == 1)
		return (1);
	return (0);
}
