/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmontija <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/05 16:53:12 by jmontija          #+#    #+#             */
/*   Updated: 2016/01/05 16:53:28 by jmontija         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nb, int power)
{
	int total;

	total = nb;
	if (power > 1)
	{
		while (power > 1)
		{
			total = total * nb;
			power--;
		}
	}
	else if (power == 0)
		return (1);
	else
		return (0);
	return (total);
}
