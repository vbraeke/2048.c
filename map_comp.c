/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_comp.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/31 20:54:38 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

int			**map_cpy(t_player *player)
{
	int		**tmp;
	int		i;
	int		j;

	tmp = (int **)malloc(sizeof(int *) * player->size_map + 1);
	i = -1;
	j = 0;
	while (++i < player->size_map)
		tmp[i] = (int *)malloc(sizeof(int) * (player->size_map + 1));
	i = 0;
	while (i < player->size_map)
	{
		while (j < player->size_map)
		{
			tmp[i][j] = player->map[i][j];
			j++;
		}
		j = 0;
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

int			map_comp(t_player *player)
{
	int		i;
	int		j;

	i = -1;
	while (++i < player->size_map)
	{
		j = -1;
		while (++j < player->size_map)
		{
			if (player->map[i][j] != player->tmp[i][j])
				return (1);
		}
	}
	return (0);
}
