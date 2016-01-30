/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordnb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:02:17 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 16:19:43 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int		ft_wordnb(char const *s, char c)
{
	unsigned int word;
	unsigned int i;

	word = 0;
	i = 0;
	if (s && c)
	{
		if (s[i] && s[i] != c)
			word = 1;
		else
			word = 0;
		i++;
		while (s[0] && s[i] != '\0')
		{
			if (s[i - 1] == c && s[i] != c)
				word++;
			i++;
		}
	}
	return (word);
}
