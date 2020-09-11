/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:47:38 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/02 13:48:29 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct			s_lst
{
	int					fd;
	char				*over;
	struct s_lst		*next;
}						t_lst;

int						get_next_line(int fd, char **line);
void					ft_finalfree_gnl(t_lst *ptr, t_lst **lst);

#endif
