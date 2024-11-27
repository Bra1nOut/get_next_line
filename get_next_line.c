/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:23:55 by levincen          #+#    #+#             */
/*   Updated: 2024/11/27 16:32:31 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*stocker(int fd, char *buffer)
// {
// 	int	bytes;

// 	bytes = read(fd, buffer, BUFFER_SIZE);
// 	buffer[bytes] = '\0';
// 	return (buffer);
// }

char	*get_next_line(int fd)
{
	static char	*buffer;
	char	*temp;
	char	*line;
	int		bytes_read;

	if (fd < 0|| BUFFER_SIZE <= 0)
		return (NULL);
	temp = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!temp)
		return (NULL);
	line = ft_strchr(temp, '\n');
	while (1)
	{
		read(fd, temp, BUFFER_SIZE);
		if (bytes_read == 0)
		{
			free (temp);
			line = NULL;
			break;
		}
		buffer = ft_strjoin(buffer, temp);
		line = ft_strchr(temp, '\n');
	}
	return (line);
}

int	main()
{
	int	fd;
	char	*buffer;

	buffer  = malloc(sizeof(char) * BUFFER_SIZE + 1);
	fd = open("text.txt", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	return 0;
}
