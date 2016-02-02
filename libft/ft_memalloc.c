/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 19:39:45 by jmontija          #+#    #+#             */
/*   Updated: 2015/12/11 19:39:47 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *zone;

	zone = (char *)malloc(sizeof(*zone) * size);
	if (zone == NULL || size == 0)
		return (NULL);
	ft_memset(zone, 0, size);
	return (zone);
}
