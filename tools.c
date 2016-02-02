/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/31 22:44:34 by dgalide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

int		get_next_key(void)
{
	char	buf[4];
	int		ret;

	while ((ret = read(0, buf, 3)) == 0)
	{
		buf[ret] = '\0';
	}
	if (ret > 2)
		return (buf[2]);
	return (buf[0]);
}

int		ft_rand(void)
{
	int n;
	int ret;

	n = 0;
	srand(time(NULL));
	n = rand();
	if (n % 2 == 0)
		ret = 2;
	else
		ret = 4;
	return (ret);
}

void	ft_put_random(t_player *player)
{
	int x;
	int y;

	x = rand() % 4;
	y = rand() % 4;
	if (rand() % 2 == 0)
	{
		while (player->map[y][x] != 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		player->map[y][x] = 2;
		player->used++;
	}
	else
	{
		while (player->map[y][x] != 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		player->map[y][x] = 4;
		player->used++;
	}
}

void	check_win(t_player *map)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < map->size_map)
	{
		while (j < map->size_map)
		{
			if (map->map[i][j] == WIN_VALUE)
				map->win = 1;
			j++;
		}
		i++;
	}
}

void	ft_win(t_player *map)
{
	mvprintw(COLS / 5, LINES / 5, "YOU WIN");
	map->win++;
}
