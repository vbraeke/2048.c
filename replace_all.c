/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 20:47:32 by dgalide           #+#    #+#             */
/*   Updated: 2016/02/02 18:11:57 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

void			replace_all(t_player *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (map->key == 65)
		replace_all_t(map);
	else if (map->key == 66)
		replace_all_b(map);
	else if (map->key == 67)
		replace_all_r(map);
	else if (map->key == 68)
		replace_all_l(map);
}

void			replace_all_l(t_player *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < map->size_map)
	{
		while (j < map->size_map)
		{
			if (map->map[i][j] != 0)
				replace_l(map, i, j);
			j++;
		}
		j = 0;
		i++;
	}
}

void			replace_all_r(t_player *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (i < map->size_map)
	{
		j = map->size_map;
		while (j >= 0)
		{
			if (map->map[i][j] != 0)
				replace_r(map, i, j);
			j--;
		}
		i++;
	}
}

void			replace_all_b(t_player *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < map->size_map)
	{
		i = map->size_map - 1;
		while (i >= 0)
		{
			if (map->map[i][j] != 0)
				replace_b(map, i, j);
			i--;
		}
		j++;
	}
}

void			replace_all_t(t_player *map)
{
	int			i;
	int			j;

	j = 0;
	i = 0;
	while (j < map->size_map)
	{
		while (i < map->size_map)
		{
			if (map->map[i][j] != 0)
				replace_t(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}
