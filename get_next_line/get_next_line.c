/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:45:59 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/10 12:19:59 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_take_line_update_buffer(char **line, char buffer[]);
static char *ft_read_while_buffer(int fd,char *buffer, char **line);

char	*get_next_line(int fd)
{
	static char	buffer[BUFFER_SIZE + 1];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = ft_strdup(buffer);
	if (!line)
		return (NULL);
	if (ft_take_line_update_buffer(&line, buffer))
		return (line);
	
	return (ft_read_while_buffer(fd, buffer, &line));
}

static char *ft_read_while_buffer(int fd,char *buffer, char **line)
{
	ssize_t		bytes_read;
	char		*temp;

	bytes_read = read(fd, buffer, BUFFER_SIZE);
	while (bytes_read > 0)
	{
		buffer[bytes_read] = '\0';
		temp = ft_strjoin(*line, buffer);
		free(*line);
		*line = temp;
		if (ft_take_line_update_buffer(line, buffer))
			return (*line);
		bytes_read = read(fd, buffer, BUFFER_SIZE);
	}
	buffer[0] = '\0';
	if (!(*line)[0])
	{
		free(*line);
		return (NULL);
	}
	return (*line);
}

static int	ft_take_line_update_buffer(char **line, char buffer[])
{
	char	*salto;

	salto = ft_strchr(*line, '\n');
	if (salto)
	{
		ft_memcpy(buffer, salto + 1, ft_strlen(salto + 1) + 1);
		salto[1] = '\0';
		return (1);
	}
	return (0);
}

// char	*get_next_line(int fd)
// {
// 	static char	buffer[BUFFER_SIZE + 1];
// 	ssize_t		bytes_read;
// 	char		*line;
// 	char		*salto;
// 	char		*temp;
// 	char		*new;

// 	if (fd < 0 || BUFFER_SIZE <= 0)
// 		return (NULL);
// 	line = ft_strdup(buffer);
// 	if (!line)
// 		return (NULL);
// 	salto = ft_strchr(line, '\n');
// 	if (salto)
// 	{
// 		ft_memcpy(buffer, salto + 1, ft_strlen(salto + 1) + 1);
// 		salto[1] = '\0';
// 		return (line);
// 	}
// 	while (1)
// 	{
// 		bytes_read = read(fd, buffer, BUFFER_SIZE);
// 		if (bytes_read <= 0)
// 			break ;
// 		buffer[bytes_read] = '\0';
// 		if (!ft_strchr(buffer, '\n'))
// 		{
// 			new = ft_strjoin(line, buffer);
// 			free(line);
// 			line = new;
// 		}
// 		else
// 		{
// 			salto = ft_strchr(buffer, '\n');
// 			temp = malloc(salto - buffer + 2);
// 			ft_memcpy(temp, buffer, salto - buffer + 1);
// 			temp[salto - buffer + 1] = '\0';
// 			new = ft_strjoin(line, temp);
// 			free(temp);
// 			free(line);
// 			line = new;
// 			ft_memcpy(buffer, salto + 1, ft_strlen(salto + 1) + 1);
// 			return (line);
// 		}
// 	}
// 	if (!line[0])
// 	{
// 		free(line);
// 		return (NULL);
// 	}
// 	else
// 	{
// 		buffer[0] = '\0';
// 		return (line);
// 	}
// }
