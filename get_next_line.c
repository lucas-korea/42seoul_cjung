/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cjung <cjung@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:04:16 by cjung             #+#    #+#             */
/*   Updated: 2021/01/24 00:05:37 by cjung            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_next_line(int fd, char **line)
{
	static char	*r_thread[8092];
	char		buf[BUFFER_SIZE + 1];
	int			read_len;

	if ((fd < 0) || line == 0 || BUFFER_SIZE <= 0 || read(fd, buf, 0) < 0)
		return (-1);
	while ((read_len = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_len] = '\0';
		if (!r_thread[fd])
			r_thread[fd] = ft_strdup("");
		r_thread[fd] = ft_strjoin(r_thread[fd], buf);
		if (is_newline(r_thread[fd]) >= 0)
		{
			split_line(&r_thread[fd], line);
			return (1);
		}
	}
	return (return_function(&r_thread[fd], line, read_len));
}

void		split_line(char **r_thread, char **line)
{
	size_t	index;
	char	*temp;

	index = is_newline(*r_thread);
	*line = malloc(sizeof(char) * (index + 1));
	ft_strlcpy(*line, *r_thread, index + 1);
	if (ft_strlen(*r_thread + index + 1) == 0)
	{
		free(*r_thread);
		*r_thread = 0;
	}
	else
	{
		temp = ft_strdup(*r_thread + index + 1);
		free(*r_thread);
		*r_thread = temp;
	}
}

int			return_function(char **r_thread, char **line, int read_len)
{
	if (read_len < 0)
		return (-1);
	else if (*r_thread && is_newline(*r_thread) >= 0)
	{
		split_line(r_thread, line);
		return (1);
	}
	else if (*r_thread)
	{
		*line = *r_thread;
		*r_thread = 0;
		return (0);
	}
	else
	{
		*line = ft_strdup("");
		return (0);
	}
}

int			is_newline(char *buf)
{
	size_t		i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}
