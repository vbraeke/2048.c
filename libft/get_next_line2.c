/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/25 16:18:09 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/27 20:44:16 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strnjoin(char *s1, char *s2, size_t n)
{
	char	*res;

	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	ft_bzero(res, sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (NULL);
	ft_strcpy(res, s1);
	ft_strncat(res, s2, n);
	return (res);
}

void	checkbuf(char *buf, char **rest)
{
	int		i;

	i = 0;
	while(buf[i])
	{
		if (buf[i] == '\n')
		{
			*rest = ft_strsub(buf, 0, i);
			printf("%s\n", *rest);

		}
		i++;
	}
}

void		checkrest(char **rest, char **line)
{
	int		i;
	char *tmp;

	i = 0;
	while ((*rest)[i])
	{
		if ((*rest)[i] == '\n')
		{
			*line = ft_strnjoin(*line, *rest, i);
			tmp = ft_strsub(*rest, i + 1, ft_strlen(*rest - i));
			ft_strdel(rest
			*rest = ft_strdup(tmp);
			printf("rest = %s\n", *line);
			free(tmp);
			tmp = NULL;
			return;
		}
		i++;
	}
}

int	readfile(char *buf, char **rest, char **line, const int fd)
{
	int	ret;

	while((ret = read(fd, buf, BUFF_SIZE)))
	{	
		/*if (*rest != NULL)
		{
			printf("first\n");
			checkrest(rest, line);
		}*/
		checkbuf(buf, rest);
		if (ret == 0)
		{
			printf("FINISH\n");
			return (0);
		}
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	int		i;
	char	buf[BUFF_SIZE + 1];
	static char	*rest = NULL;

	if (BUFF_SIZE < 1 || !line || !*line || fd < 0)
		return (-1);
	readfile(buf, &rest, line, fd);
	if ((readfile(buf, &rest, line, fd)) == 0)
		return (0);
	return (1);
}

/*int		main(int argc, char **argv)
{
	char *line;
	int fd;
	//int i = 1;
	int ret;

	line = ft_strnew(BUFF_SIZE);
	if (argc == 2)
	{
		if (!(fd = open(argv[1], O_RDONLY)))
			return (0);
	}
	else
		fd = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		//printf("line = %s\n", line);
		//printf("ret = %d\n", ret);
	}
	//printf("NEXT_LINE: %s\n", line);
	close(fd);
	return (0);
}*/