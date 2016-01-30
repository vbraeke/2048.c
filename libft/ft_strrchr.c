/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 19:39:01 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/15 19:39:02 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		len;
	char	occ;

	len = ft_strlen(s);
	occ = (char)c;
	while (len >= 0 && s[len] != occ)
		len--;
	if (len < 0)
		return (0);
	else
		return ((char *)s + len);
	return (NULL);
}
