/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/22 17:33:33 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/02 17:13:32 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char) * (ft_strlen((char *)s1)
										+ ft_strlen((char *)s2) + 1))))
		return (NULL);
	ft_strcpy(new, (char *)s1);
	ft_strcat(new, (const char *)s2);
	return (new);
}
