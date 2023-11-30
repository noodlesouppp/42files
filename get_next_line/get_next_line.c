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

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static	node	*stash = NULL;
	char			*line;
	
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, &line, 0) < 0)
		return (NULL);
	ft_list(&stash, fd);
	if (stash == NULL)
		return (NULL);
	line = ft_line(stash);
	ft_leftover(&stash);
	return (line);
}

void	ft_list(node **stash, int fd)
{
	int		char_read;
	char	*buf;

	while (!ft_newline(*stash))
	{
		buf = malloc(sizeof(node) * (BUFFER_SIZE + 1));
		if (!buf)
			return ;
		char_read = (int)read(fd, buf, BUFFER_SIZE);
		if (!char_read)
		{
			free(buf);
			return ;
		}
		buf[char_read] = '\0';
		ft_append(stash, buf);
	}
}

void	ft_append(node **stash, char *buf)
{
	node	*new;
	node	*end;

	end = ft_last_node(*stash);
	new = malloc(sizeof(node));
	if (new == NULL)
		return ;
	if (end == NULL)
		*stash = new;
	else
		end->next = new;
	new->content = buf;
	new->next = NULL;
}

char	*ft_line(node *stash)
{
	int		length;
	char	*next_line;

	if (stash == NULL)
		return (NULL);
	length = count_to_newline(stash);
	next_line = malloc(length + 1);
	if (next_line == NULL)
		return (NULL);
	ft_strcpy(stash, next_line);
	return (next_line);
}

void	ft_leftover(node **stash)
{
	node	*end;
	node	*clean;
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = malloc(BUFFER_SIZE + 1);
	clean = malloc(sizeof(node));
	if (buf == NULL || clean == NULL)
		return ;
	end = ft_last_node(*stash);
	while (end->content[i] != '\0' && end->content[i] != '\n')
		++i;
	while (end->content[i] != '\0')
		buf[j++] = end->content[i++];
	buf[j] = '\0';
	end->content = buf;
	end->next = NULL;
	ft_dealloc(stash, clean, buf);
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
		printf("%s\n", line);
		free(line);
	}
	return (0);
}