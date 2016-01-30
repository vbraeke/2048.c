/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/22 16:11:38 by avallete          #+#    #+#             */
/*   Updated: 2016/01/27 20:56:48 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		check_back_slash_n(char *buf)
{
	int		i;

	i = -1;
	while (++i && buf[i])
	{
		if (buf[i] == '\n')
		{
			return (1);
		}
	}
	return (-1);
}

int		check_my_line(char *buf)
{
	int		i;

	while (++i && buf[i])
	{
		if (buf[i] == '\n')
		{
			return (i + 1);
		}
	}
	return (i);
}

int		send_right_line(char *buf, char **rest, char **line)
{
	int		check;
	char 	*tmp;

	check = check_my_line(buf);
	check = check_my_line(*rest);
	*line = ft_strdup(*rest);
	tmp = ft_strdup(buf + check);
	free(*rest);
	*rest = tmp;
	if (buf)
		ft_strdel(&buf);
	return (1);


}

void	join_my_rest(char *buf, char **rest)
{
	char	*tmp_buf = NULL;
	char	*tmp_rest = NULL;

	if (*buf)
	{
		tmp_buf = ft_strdup(buf);
		if (*rest)
		{
			tmp_rest = ft_strdup(*rest);
			ft_strdel(rest);
		}
		*rest = ft_strjoin(tmp_buf, tmp_rest);
		if (tmp_rest != NULL)
			ft_strdel(&tmp_rest);
		if (tmp_buf != NULL)
			ft_strdel(&tmp_buf);
	}
}

int		get_next_line(int const fd, char **line)
{
	int		ret;
	char	buf[BUFF_SIZE + 1];
	static	char *rest;
	int			check;


	if (fd <= 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		check = check_back_slash_n(buf);
		if (check != 1)
			join_my_rest(buf, &rest);
	}
	if (ret <= 0)
		return (-1);
	if (ret > 0)
		join_my_rest(buf, &rest);
	if (rest != '\0')
	{
		return (send_right_line(buf, &rest, line));	
	}
	if (rest)
		ft_strdel(&rest);
	return (0);
}