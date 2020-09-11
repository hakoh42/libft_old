/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 00:12:46 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/02 13:25:53 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(char *str)
{
	int		len;
	char	*new;

	len = ft_strlen(str);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = ft_strcpy(new, str);
	return (new);
}
