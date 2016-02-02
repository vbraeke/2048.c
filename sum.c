/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sum.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/02/02 18:10:57 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

void			sum_l(t_player *map)
{
	int			i;
	int			j;

	i = -1;
	while (++i < map->size_map)
	{
		j = -1;
		while (++j < map->size_map)
		{
			if (((j + 1 < map->size_map) && map->map[i][j] != 0) \
					&& (map->map[i][j] == map->map[i][j + 1]))
			{
				map->map[i][j] = map->map[i][j] *= 2;
				map->score += map->map[i][j];
				map->map[i][j + 1] = 0;
				map->used--;
				replace_l(map, i, j);
			}
			else if (map->map[i][j] != 0)
				replace_l(map, i, j);
		}
	}
}

void			sum_r(t_player *map)
{
	int			i;
	int			j;

	i = -1;
	j = map->size_map - 1;
	while (++i < map->size_map)
	{
		while (j >= 0)
		{
			if (((j - 1 >= 0) && map->map[i][j] != 0) \
					&& (map->map[i][j] == map->map[i][j - 1]))
			{
				map->map[i][j] = map->map[i][j] *= 2;
				map->score += map->map[i][j];
				map->map[i][j - 1] = 0;
				map->used--;
				replace_r(map, i, j);
			}
			else if (map->map[i][j] != 0)
				replace_r(map, i, j);
			j--;
		}
		j = map->size_map - 1;
	}
}

void			sum_t(t_player *map)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (j < map->size_map)
	{
		while (i < map->size_map)
		{
			if (((i + 1 < map->size_map) && map->map[i][j] != 0) \
					&& (map->map[i][j] == map->map[i + 1][j]))
			{
				map->map[i][j] = map->map[i][j] *= 2;
				map->score += map->map[i][j];
				map->map[i + 1][j] = 0;
				map->used--;
				replace_t(map, i, j);
			}
			else if (map->map[i][j] != 0)
				replace_t(map, i, j);
			i++;
		}
		i = 0;
		j++;
	}
}

void			sum_b(t_player *map)
{
	int			i;
	int			j;

	i = map->size_map - 1;
	j = 0;
	while (j < map->size_map)
	{
		while (i >= 0)
		{
			if (((i - 1 >= 0) && map->map[i][j] != 0) \
					&& (map->map[i][j] == map->map[i - 1][j]))
			{
				map->map[i][j] = map->map[i][j] *= 2;
				map->score += map->map[i][j];
				map->map[i - 1][j] = 0;
				map->used--;
				replace_b(map, i, j);
			}
			else if (map->map[i][j] != 0)
				replace_b(map, i, j);
			i--;
		}
		i = map->size_map - 1;
		j++;
	}
}
