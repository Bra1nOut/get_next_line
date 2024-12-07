/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 14:01:08 by levincen          #+#    #+#             */
/*   Updated: 2024/12/07 13:56:33 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	malloc_temp(int fd, char **temp)
{
	if (fd < 0 || fd > 4096 || BUFFER_SIZE <= 0)
		return (0);
	*temp = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!*temp)
		return (0);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buffer[4096];
	char		*temp;
	char		*line;
	int			bytes_read;

	if (malloc_temp(fd, &temp) == 0)
		return (NULL);
	while (!ft_strchr(buffer[fd], '\n'))
	{
		bytes_read = read(fd, temp, BUFFER_SIZE);
		if (bytes_read <= 0)
		{
			free(temp);
			if (bytes_read == 0)
				break ;
			return (NULL);
		}
		temp[bytes_read] = '\0';
		buffer[fd] = ft_strjoin(buffer[fd], temp);
	}
	if (ft_strchr(buffer[fd], '\n'))
		free(temp);
	line = search_copy(buffer[fd]);
	buffer[fd] = rm_start(buffer[fd], line);
	return (line);
}
