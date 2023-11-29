/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 17:12:46 by yousong           #+#    #+#             */
/*   Updated: 2023/11/17 21:54:18 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	node	*stash = NULL;
	char			*line;
	int				read_count;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	read_count = 1;
	line = NULL;
	ft_storage(fd, &stash, &read_count);
	if (stash == NULL)
		return (NULL);
	return (line);
}

void	ft_storage(int fd, node **stash, int *read_count)
{
	char	*buf;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (NULL);
	while ((ft_newline(*stash) == NULL) && *read_count != 0)
	{
		*read_count = (int)read(fd, buf, BUFFER_SIZE);
		if ((*stash == NULL && *read_count == 0) || *read_count == -1)
		{
			free(buf);
			return;
		}
		buf[*read_count] = '\0';
	}
}

int	main(void)
{
	int	fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		printf("%s, line");
		free(line);
	}
	return (0);
}