/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 14:15:44 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 14:48:44 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*map;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = ft_strnew(ft_strlen(s));
		if (map)
		{
			while (s[i] != '\0')
			{
				map[i] = f(s[i]);
				i++;
			}
		}
	}
	return (map);
}
