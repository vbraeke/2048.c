/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 16:23:00 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 14:30:58 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	c_tmp;
	unsigned char	*dst_tmp;
	unsigned char	*str;

	dst_tmp = (unsigned char *)dst;
	str = (unsigned char *)src;
	c_tmp = (unsigned char)c;
	i = 0;
	while (i < n && str[i] != c_tmp)
	{
		dst_tmp[i] = str[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else if (str[i] == c_tmp)
	{
		dst_tmp[i] = str[i];
		i++;
	}
	return ((void *)dst_tmp + i);
}
