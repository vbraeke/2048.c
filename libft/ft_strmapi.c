/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 14:50:53 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 14:51:14 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*map;

	i = 0;
	map = NULL;
	if (s && f)
	{
		map = ft_strnew(ft_strlen(s));
		if (map)
		{
			while (s[i] != '\0')
			{
				map[i] = f(i, s[i]);
				i++;
			}
		}
	}
	return (map);
}
