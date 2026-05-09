/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Carles Llauradó <cllaurad@student.42belg  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/08 18:45:59 by Carles Llaura     #+#    #+#             */
/*   Updated: 2026/05/08 18:46:01 by Carles Llaura    ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buffer[BUFFER_SIZE + 1];
    ssize_t     bytes_read;
    char        *line;
    char        *salto;
    char        *temp;
    char        *new;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    line = ft_strdup(buffer);
    if (!line)
        return (NULL);
    salto = ft_strchr(line, '\n');
    if (salto)
    {
        ft_memcpy(buffer, salto + 1, ft_strlen(salto + 1) + 1);
        salto[1] = '\0';
        return (line);
    }

    while (1)
    {
        bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read <= 0)
            break;
        buffer[bytes_read] = '\0';

        if (!ft_strchr(buffer, '\n'))
        {
            new = ft_strjoin(line, buffer);
            free(line);
            line = new;
        }
        else
        {
            salto = ft_strchr(buffer, '\n');
            temp = malloc(salto - buffer + 2);
            ft_memcpy(temp, buffer, salto - buffer + 1);
            temp[salto - buffer + 1] = '\0';
            new = ft_strjoin(line, temp);
            free(temp);
            free(line);
            line = new;
            ft_memcpy(buffer, salto + 1,ft_strlen(salto + 1) + 1);
            return (line);
        }
    }

    if (!line[0])
    {
        free(line);
        return (NULL);
    }
    else
    {
        buffer[0] = '\0';
        return (line);
    }
}

// char *get_next_line(int fd)
// {
//     static char buffer[BUFFER_SIZE + 1];
//     ssize_t bytes_read;
//     size_t len;
//     char *newline;
//     char *res;
//     char *temp;

//     if (fd < 0 || BUFFER_SIZE <= 0)
//         return (NULL);
    
//     res = ft_strdup(buffer);
//     if (!res)
//         return (NULL);

//     bytes_read = 1
//     while (bytes_read > 0)
//     {
//         newline = ft_strchr(buffer, '\n');
//         if (newline)
//         {
//             len = newline - res + 1
//             res = malloc(newline - buffer + 2);
//             ft_memcpy(res, buffer, newline - buffer + 1);
//             res[newline - buffer + 1] = '\0';

//             ft_memcpy(buffer, newline + 1, ft_strlen(newline + 1) + 1);
//             return res;
//         }
        
//         bytes_read = read(fd, buffer, BUFFER_SIZE);
//         if (bytes_read < 0)
//         {
//             free(res);
//             return (NULL);
//         }
//         buffer[bytes_read] = '\0';
//         temp = ft_strjoin(res, buffer);

//         free(res)
//         res = temp;
//     } 
// }