/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakoh <hakoh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/06 06:43:11 by hakoh             #+#    #+#             */
/*   Updated: 2020/09/16 10:19:33 by hakoh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/get_next_line.h"

static char		*ft_strdupcat_gnl(char *over, char *buf)
{
	int			i;
	int			j;
	char		*str;

	i = ft_strlen(over);
	j = ft_strlen(buf);
	if (!(str = (char *)malloc(sizeof(char) * (i + j + 1))))
	{
		free(over);
		return (str);
	}
	ft_strcpy(str, over);
	j = 0;
	while (buf && buf[j])
	{
		str[i + j] = buf[j];
		j++;
	}
	str[i + j] = '\0';
	free(over);
	return (str);
}

static int		ft_read_gnl(int fd, char **over)
{
	char		*buf;
	int			ret;

	ret = 0;
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE_GNL + 1))))
		return (-1);
	while ((ret = read(fd, buf, BUFFER_SIZE_GNL)) > 0)
	{
		buf[ret] = '\0';
		if (!(*over = ft_strdupcat_gnl(*over, buf)))
			return (-1);
		if (c_pos_in_str(*over, '\n') > -1)
			break ;
	}
	free(buf);
	if (ret == -1)
		return (-1);
	if (ret == 0)
		return (0);
	return (1);
}

static int		ft_split_gnl(char *over, char **line)
{
	int			size;
	int			i;

	size = c_pos_in_str(over, '\n');
	if (!(*line = (char *)malloc(sizeof(char) * (size + 1))))
	{
		free(over);
		return (0);
	}
	i = 0;
	while (i < size)
	{
		(*line)[i] = over[i];
		i++;
	}
	(*line)[i] = '\0';
	i = 1;
	while (over[size + i])
	{
		over[i - 1] = over[size + i];
		i++;
	}
	over[i - 1] = '\0';
	return (1);
}

static t_lst_gnl	*ft_getnode_gnl(int fd, t_lst_gnl **lst)
{
	t_lst_gnl	*ptr;

	ptr = *lst;
	while (ptr && ptr->fd != fd)
		ptr = ptr->next;
	if (!ptr)
	{
		if (!(ptr = (t_lst_gnl *)malloc(sizeof(t_lst_gnl))))
			return (NULL);
		ptr->fd = fd;
		ptr->over = NULL;
		ptr->next = *lst;
		*lst = ptr;
	}
	return (ptr);
}

int				get_next_line(int fd, char **line)
{
	static t_lst_gnl	*lst = NULL;
	t_lst_gnl			*ptr;
	int				ret;

	if (BUFFER_SIZE_GNL <= 0 || !line || !(ptr = ft_getnode_gnl(fd, &lst)))
	{
		return (-1);
	}
	ret = 1;
	if (c_pos_in_str(ptr->over, '\n') == -1)
		if ((ret = ft_read_gnl(ptr->fd, &(ptr->over))) == -1)
			return (-1);
	if (ret == 0)
	{
		*line = ptr->over;
		ptr->over = NULL;
		ft_finalfree_gnl(ptr, &lst);
		if (!*line)
			if (!(*line = ft_strdup("")))
				return (-1);
		return (0);
	}
	if (!ft_split_gnl(ptr->over, line))
		return (-1);
	return (1);
}
