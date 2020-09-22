/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_all.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 17:51:08 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 17:51:08 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int		ft_count_words(char *str, char *charset)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (str[i])
	{
		while (str[i] && ft_is_sep(str[i], charset))
			i++;
		if (str[i])
		{
			while (str[i] && !ft_is_sep(str[i], charset))
				i++;
			nb_words++;
		}
	}
	return (nb_words);
}

char	**ft_split_all(char *str, char *charset)
{
	char	**tab;
	int		size;
	int		i;
	int		len;

	size = ft_count_words(str, charset);
	if (!(tab = (char **)malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	tab[size] = 0;
	i = 0;
	while (i < size)
	{
		len = 0;
		while (*str && ft_is_sep(*str, charset))
			str++;
		while (str[len] && !ft_is_sep(str[len], charset))
			len++;
		if (!(tab[i] = ft_strndup(str, len)))
			return (NULL);
		str += len;
		i++;
	}
	return (tab);
}