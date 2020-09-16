/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 23:01:15 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:33:14 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int		ft_nb_words(char *str, char c)
{
	int		i;
	int		is_word;

	i = 0;
	is_word = 0;
	while (*str)
	{
		if (is_word == 0 && *str != c)
		{
			is_word = 1;
			i++;
		}
		else if (is_word == 1 && *str == c)
			is_word = 0;
		str++;
	}
	return (i);
}

static int		ft_nb_letters(char *str, char c)
{
	int		len;

	len = 0;
	while (*str && *str != c)
	{
		len++;
		str++;
	}
	return (len);
}

static char		**ft_free_split(int count, char **str)
{
	int		i;

	i = 0;
	while (i < count)
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

char			**ft_split(char const *s, char c)
{
	int		nb_words;
	char	**new;
	int		i;
	char	*sbis;

	if (!s)
		return (NULL);
	sbis = (char *)s;
	nb_words = ft_nb_words(sbis, c);
	if (!(new = (char **)malloc(sizeof(char *) * (nb_words + 1))))
		return (NULL);
	i = 0;
	while (nb_words--)
	{
		while (*sbis && *sbis == c)
			sbis++;
		if (!(new[i] = ft_substr(sbis, 0, ft_nb_letters(sbis, c))))
			return (ft_free_split(i, new));
		sbis += ft_nb_letters(sbis, c);
		i++;
	}
	new[i] = NULL;
	return (new);
}
