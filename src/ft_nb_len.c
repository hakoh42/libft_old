/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nb_len.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 18:02:07 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:32:42 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_nb_len(long nb)
{
	int		len;

	len = 1;
	if (nb == -9223372854775808)
		return (20);
	if (nb < 0)
	{
		nb *= -1;
		len++;
	}
	while (nb > 9)
	{
		nb /= 10;
		len++;
	}
	return (len);
}