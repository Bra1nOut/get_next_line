/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: levincen <levincen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 13:23:55 by levincen          #+#    #+#             */
/*   Updated: 2024/11/25 15:28:15 by levincen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
char	*stocker(int fd, char *buffer)
{
	read(fd, buffer, BUFFER_SIZE);
	return (buffer);
}
// char	*get_next_line(int fd)
// {
// 	char	*buffer;
// 	char	*stock;
// 	char	*new;

// 	buffer = malloc(sizeof(char) * BUFFER_SIZE + 1);
// 	if (BUFFER_SIZE <= 0)
// 	{
// 		free (buffer);
// 		buffer = NULL;
// 		return (NULL);
// 	}
// 	if (!fd || !buffer)
// 		return (NULL);
// }

int	main(int argc, char **argv)
{
	int	fd;
	char *result;
	char	*buffer;

	fd = open(argv[1], O_RDONLY);
	(void) argc;
	result = stocker(fd, buffer);
	printf("%s\n", result);
	return 0;
}
