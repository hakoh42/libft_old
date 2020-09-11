/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 06:26:41 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/02 13:48:26 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_finalfree_gnl(t_lst *ptr, t_lst **lst)
{
	t_lst	*tmp;

	tmp = *lst;
	if (*lst == ptr)
	{
		*lst = (*lst)->next;
		free(tmp);
	}
	else
	{
		while (tmp->next != ptr)
			tmp = tmp->next;
		tmp->next = ptr->next;
		free(ptr);
	}
}
