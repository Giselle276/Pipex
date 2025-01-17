/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmaccha- <gmaccha-@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-28 10:40:13 by gmaccha-          #+#    #+#             */
/*   Updated: 2024-12-28 10:40:13 by gmaccha-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	count_words(char *str, char sep)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (((str[i + 1] == sep) || (str[i + 1] == '\0'))
			&& (!(str[i] == sep) || (str[i] == '\0')))
			word++;
		i++;
	}
	return (word);
}

static void	write_word(char *dest, char *str, char sep)
{
	int	i;

	i = 0;
	while (!((str[i] == sep) || (str[i] == '\0')))
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

static char	**free_words(char **split, int word)
{
	if ((!split[word]))
	{
		while (word > 0)
		{
			free (split[--word]);
		}
	}
	return (0);
}

static void	*write_split(char **split, char *str, char sep)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
		if (((str[i] == sep) || (str[i] == '\0')))
			i++;
	else
	{
		j = 0;
		while (!((str[i + j] == sep) || (str[i + j] == '\0')))
			j++;
		split[word] = (char *) malloc(sizeof(char) * (j + 1));
		if (!split[word])
		{
			return (free_words(split, word));
		}
		write_word (split[word], str + i, sep);
		i = i + j;
		word++;
	}
	split[word] = 0;
	return ((void *)1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	char	*str;
	int		words;

	if (s == 0)
		return (0);
	str = (char *) s;
	words = count_words(str, c);
	res = (char **) malloc(sizeof(char *) * (words + 1));
	if (!res)
		return (0);
	res[words] = 0;
	if (!write_split(res, str, c))
	{
		free(res);
		return (0);
	}
	return (res);
}
