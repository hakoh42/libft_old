/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 21:10:25 by hakoh             #+#    #+#             */
/*   Updated: 2019/12/04 18:19:45 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_itoa(int n)
{
	char	*rslt;
	long	nb;
	int		len;

	len = ft_nb_len((long)n);
	if (!(rslt = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	rslt[len--] = '\0';
	nb = n;
	if (n < 0)
	{
		rslt[0] = '-';
		nb *= -1;
	}
	while (nb > 9)
	{
		rslt[len--] = (nb % 10) + 48;
		nb /= 10;
	}
	if (nb < 10)
		rslt[len] = nb + 48;
	return (rslt);
}
