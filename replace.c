/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/31 20:50:05 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "includes/all.h"

void			replace_l(t_player *map, int i, int j)
{
	if (j > 0 && map->map[i][j - 1] == 0)
	{
		map->map[i][j - 1] = map->map[i][j];
		map->map[i][j] = 0;
		return (replace_l(map, i, j - 1));
	}
}

void			replace_r(t_player *map, int i, int j)
{
	if (j + 1 < map->size_map && map->map[i][j + 1] == 0)
	{
		map->map[i][j + 1] = map->map[i][j];
		map->map[i][j] = 0;
		return (replace_r(map, i, j + 1));
	}
}

void			replace_t(t_player *map, int i, int j)
{
	if (i - 1 >= 0 && map->map[i - 1][j] == 0)
	{
		map->map[i - 1][j] = map->map[i][j];
		map->map[i][j] = 0;
		return (replace_t(map, i - 1, j));
	}
}

void			replace_b(t_player *map, int i, int j)
{
	if (i + 1 < map->size_map && map->map[i + 1][j] == 0)
	{
		map->map[i + 1][j] = map->map[i][j];
		map->map[i][j] = 0;
		return (replace_b(map, i + 1, j));
	}
}
