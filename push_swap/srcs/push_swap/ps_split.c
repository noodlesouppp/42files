/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousong <yousong@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 12:03:25 by yousong           #+#    #+#             */
/*   Updated: 2024/06/17 00:36:44 by yousong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	count_words(char *s, char c)
{
	int	count;
	int	lever;

	count = 0;
	while (*s)
	{
		lever = 0;
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
		{
			if (!lever)
			{
				count++;
				lever = 1;
			}
			s++;
		}
	}
	if (count == 0)
		write(2, "Error\n", 6);
	return (count);
}

static char	*get_next_word(char *s, char c)
{
	static int	cursor = 0;
	int			i;
	int			len;
	char		*word;

	i = 0;
	len = 0;
	while (s[cursor] == c)
		cursor++;
	while (s[cursor + len] != c && s[cursor + len])
		len++;
	word = malloc((size_t)len * sizeof(char) + 1);
	if (!word)
		return (NULL);
	while ((s[cursor] != c) && s[cursor])
		word[i++] = s[cursor++];
	word[i] = '\0';
	return (word);
}

char	**split(char *s, char c)
{
	char	**tab;
	int		i;
	int		word_count;

	i = 0;
	word_count = count_words(s, c);
	if (!word_count)
		exit(1);
	tab = malloc(sizeof(char *) * (size_t)(word_count + 2));
	if (!tab)
		return (NULL);
	while (word_count-- >= 0)
	{
		if (i == 0)
		{
			tab[i] = malloc(sizeof(char));
			if (!tab[i])
				return (NULL);
			tab[i++][0] = '\0';
			continue ;
		}
		tab[i++] = get_next_word(s, c);
	}
	tab[i] = NULL;
	return (tab);
}
