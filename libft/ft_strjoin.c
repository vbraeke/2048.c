/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 16:22:50 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/12 16:22:54 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*fresh;

	if (s1 && s2)
	{
		fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
		if (fresh)
		{
			ft_strcpy(fresh, (char *)s1);
			ft_strcat(fresh, s2);
			return (fresh);
		}
	}
	return (NULL);
}
