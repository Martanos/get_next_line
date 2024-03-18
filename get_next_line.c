/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malee <malee@42mail.sutd.edu.sg>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:40:13 by malee             #+#    #+#             */
/*   Updated: 2024/03/18 16:38:37 by malee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	buffer_clear(char *read_buffer)
{
	if (read_buffer)
	{
		while (*read_buffer)
			*read_buffer++ = '\0';
	}
}

ssize_t	read_to_buffer(int fd, char **payload, char *read_buffer)
{
	ssize_t	read_bytes;
	char	*temp;

	if (!*payload)
	{
		*payload = fakelloc(1, sizeof(char));
		if (!*payload)
			return (-1);
	}
	read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		temp = ft_strjoin(*payload, read_buffer);
		free(*payload);
		*payload = temp;
		if (ft_strchr(*payload, '\n'))
			break ;
		if (read_buffer)
			buffer_clear(read_buffer);
		read_bytes = read(fd, read_buffer, BUFFER_SIZE);
	}
	return (read_bytes);
}

char	*extract_line(char **payload)
{
	char	*line_end;
	char	*line;
	char	*temp;

	line_end = ft_strchr(*payload, '\n');
	if (line_end && *(line_end + 1))
	{
		line = ft_strndup(*payload, line_end - *payload + 1);
		if (!line)
			return (NULL);
		temp = ft_strndup(line_end + 1, ft_strlen(line_end + 1));
		free(*payload);
		*payload = temp;
	}
	else
	{
		line = ft_strndup(*payload, ft_strlen(*payload));
		if (!line)
			return (NULL);
		free(*payload);
		*payload = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*payload;
	char		*read_buffer;
	ssize_t		read_bytes;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	read_buffer = fakelloc(BUFFER_SIZE + 1, sizeof(char));
	if (!read_buffer)
		return (NULL);
	read_bytes = read_to_buffer(fd, &payload, read_buffer);
	free(read_buffer);
	if (read_bytes == 0 && !*payload)
	{
		free(payload);
		payload = NULL;
		return (NULL);
	}
	if (read_bytes < 0)
	{
		free(payload);
		payload = NULL;
		return (NULL);
	}
	return (extract_line(&payload));
}
