/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/13 18:00:52 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 15:21:14 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			ft_fill(char const *s, char c, size_t idx, char *split)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
				{
					split[letter] = s[i];
					letter++;
				}
				i++;
			}
			split[letter] = '\0';
			word++;
		}
		i++;
	}
}

unsigned int		ft_letter(char const *s, char c, size_t idx)
{
	unsigned int word;
	unsigned int letter;
	unsigned int i;

	word = 0;
	letter = 0;
	i = 0;
	while (s[0] && s[i] != '\0')
	{
		if (s[i] != c)
		{
			while (s[i] != c)
			{
				if (word == idx)
					letter++;
				i++;
			}
			word++;
		}
		i++;
	}
	return (letter);
}

static char			**ft_prefill(char const *s, char c)
{
	char			**split;
	unsigned int	word;
	unsigned int	letter;
	unsigned int	i;

	i = -1;
	word = ft_wordnb(s, c);
	split = (char **)malloc(sizeof(char *) * (word + 1));
	if (split)
		split[word] = NULL;
	else
		return (NULL);
	while (++i < word)
	{
		letter = ft_letter(s, c, i);
		split[i] = (char *)malloc(sizeof(char) * (letter + 1));
		if (split[i])
			ft_fill(s, c, i, split[i]);
		else
			return (NULL);
	}
	return (split);
}

char				**ft_strsplit(char const *s, char c)
{
	if (s)
		return (ft_prefill(s, c));
	return (NULL);
}
