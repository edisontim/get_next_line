/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tedison <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 15:57:50 by tedison           #+#    #+#             */
/*   Updated: 2021/04/24 13:04:37 by tedison          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	nl(char *buffer)
{
	unsigned int	i;

	i = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

int	free_all(char *buffer, char **line, char **prev_line, int ret)
{
	if (buffer)
	{
		free(buffer);
		buffer = NULL;
	}
	if (line)
	{
		free(*line);
		*line = NULL;
	}
	if (prev_line)
	{
		free(*prev_line);
		*prev_line = NULL;
	}
	return (ret);
}

int	read_line(char **line, char *buffer, int fd, char **prev_line)
{
	int	ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	while (ret > 0)
	{
		buffer[ret] = 0;
		*line = ft_strjoin(*line, buffer);
		if (!(*line))
			return (free_all(buffer, NULL, prev_line, -1));
		if (nl(buffer) != -1 && BUFFER_SIZE != 1)
		{
			if (!(*prev_line))
				*prev_line = malloc(BUFFER_SIZE + 1);
			ft_strcpy(*prev_line, &buffer[nl(buffer) + 1]);
			return (free_all(buffer, NULL, NULL, 1));
		}
		else if (nl(buffer) == 0)
			return (free_all(buffer, NULL, NULL, 1));
		ret = read(fd, buffer, BUFFER_SIZE);
	}
	if (ret == 0)
		free_all(buffer, NULL, prev_line, 0);
	return (ret);
}

int	treat_prev_line(char **line, char **prev_line, char *buffer)
{
	*line = ft_strjoin(*line, *prev_line);
	if (*line == NULL)
		return (free_all(buffer, NULL, prev_line, -1));
	if (nl(*prev_line) != -1)
	{	
		*prev_line = ft_strdup(*prev_line + nl(*prev_line) + 1, *prev_line);
		if (*prev_line == NULL)
			return (free_all(buffer, line, NULL, -2));
		free(buffer);
		return (1);
	}
	else
		return (free_all(NULL, NULL, prev_line, 0));
}

int	get_next_line(int fd, char **line)
{
	char		*buffer;
	int			ret;
	static char	*prev_line[OPEN_MAX];

	if (fd < 0 || line == NULL || read(fd, "", 0) == -1 || BUFFER_SIZE <= 0)
		return (-1);
	if (!ft_malloc(&buffer, BUFFER_SIZE + 1, BUFFER_SIZE))
		return (free_all(NULL, line, NULL, -1));
	if (!(ft_malloc(line, 1, 0)))
		return (free_all(buffer, NULL, NULL, -1));
	if (!prev_line[fd])
	{
		if (!ft_malloc(&prev_line[fd], BUFFER_SIZE + 1, 0))
			return (free_all(buffer, line, NULL, -1));
	}
	else if (prev_line[fd])
	{	
		ret = treat_prev_line(line, &prev_line[fd], buffer);
		if (ret != 0)
			return (ret);
	}
	ret = read_line(line, buffer, fd, &prev_line[fd]);
	if (ret == -1)
		free_all(buffer, line, &prev_line[fd], -1);
	return (ret);
}
