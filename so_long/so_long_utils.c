/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 23:50:29 by yousong           #+#    #+#             */
/*   Updated: 2024/09/05 11:23:21 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	clear_game(t_game *game)
{
	game->walk_count++;
	ft_printf("%s %d %s\n", "You helped Nami in", game->walk_count, "steps!");
	free_all_data(game);
	exit(0);
}

char	*ft_strdup_without_nl(char *s)
{
	char	*new_mem;
	int		size;
	int		i;

	new_mem = NULL;
	size = ft_strlen(s) + 1;
	i = 0;
	new_mem = malloc(size);
	if (!(new_mem))
		return (NULL);
	while (s[i] && s[i] != '\n')
	{
		new_mem[i] = s[i];
		i++;
	}
	new_mem[i] = '\0';
	return (new_mem);
}

int	ft_strlcpy_without_nl(char *dst, char *src, int len)
{
	int	src_len;
	int	i;

	src_len = 0;
	i = 0;
	while (src[src_len])
		src_len++;
	if (len == 0)
	{
		return (src_len);
	}
	while (i < len - 1 && *src && *src != '\n')
	{
		*dst = *src;
		dst++;
		src++;
		i++;
	}
	*dst = '\0';
	return (src_len);
}

char	*ft_strjoin_without_nl(char *s1, char *s2)
{
	char	*new_mem;
	size_t	s1_len;
	size_t	s2_len;

	new_mem = NULL;
	if (s1 == NULL && s2 == NULL)
		return (NULL);
	else if (s1 == NULL)
		return (ft_strdup_without_nl(s2));
	else if (s2 == NULL)
		return (ft_strdup_without_nl(s1));
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	new_mem = malloc(s1_len + s2_len + 1);
	if (!(new_mem))
		return (NULL);
	ft_strlcpy_without_nl(new_mem, s1, s1_len + 1);
	ft_strlcpy_without_nl(new_mem + s1_len, s2, s2_len + 1);
	free(s1);
	free(s2);
	return (new_mem);
}
