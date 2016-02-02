/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <jmontija@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 04:01:24 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 14:25:58 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *item;

	item = (t_list*)malloc(sizeof(t_list));
	if (item && content == NULL)
	{
		item->content = NULL;
		item->content_size = 0;
		item->next = NULL;
		return (item);
	}
	else if (item)
	{
		item->content = (void *)malloc(sizeof(char) * content_size);
		ft_memcpy(item->content, content, content_size);
		item->content_size = content_size;
		item->next = NULL;
		return (item);
	}
	return (NULL);
}
