/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 20:17:34 by hakoh             #+#    #+#             */
/*   Updated: 2019/12/04 21:50:55 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len)
{
	char	*new;

	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	new = ft_mystrncpy(new, (const char*)str, len);
	return (new);
}
