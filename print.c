/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/02/02 18:23:55 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/all.h"

void		print_cols(void)
{
	int		j;

	j = -1;
	while (++j < LINES)
		mvprintw(j, 0, "|||");
	j = -1;
	while (++j < LINES)
		mvprintw(j, COLS - 3, "|||");
	j = -1;
	while (++j < LINES)
		mvprintw(j, COLS / 2, "|||");
	j = -1;
	while (++j < LINES)
		mvprintw(j, COLS / 2 / 2, "|||");
	j = -1;
	while (++j < LINES)
		mvprintw(j, COLS / 4 * 3, "|||");
}

void		print_lines(void)
{
	int		x;

	x = -1;
	while (++x < COLS)
		mvprintw(0, x, "*");
	x = -1;
	while (++x < COLS)
		mvprintw(LINES / 2, x, "*");
	x = -1;
	while (++x < COLS)
		mvprintw(LINES - 1, x, "*");
	x = -1;
	while (++x < COLS)
		mvprintw(LINES / 2 / 2, x, "*");
	x = -1;
	while (++x < COLS)
		mvprintw(LINES / 4 * 3, x, "*");
}

void		print_score(t_player *map)
{
	mvprintw(LINES / 16, COLS / 16, "Score %d", map->score);
}

void		print_map(t_player *player)
{
	int x;
	int y;

	y = -1;
	print_cols();
	print_lines();
	print_score(player);
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		{
			if (player->map[y][x] != 0)
				mvprintw((y * (LINES / 4)) + LINES / 8, \
				(x * (COLS / 4)) + COLS / 8, "%d", player->map[y][x]);
		}
	}
}

int			play(t_player *map)
{
	initscr();
	noecho();
	while (1)
	{
		clear();
		map->key = get_next_key();
		if (map->end == 1)
		{
			clear();
			mvprintw(COLS / 2, LINES / 2, "YOU LOSE");
			sleep(2);
			refresh();
			return (-1);
		}
		if (map->key == 27)
			break ;
		if (map->key > 64 && map->key < 69)
			play_game(map);
		if (map->win == 1)
			ft_win(map);
		print_map(map);
		refresh();
	}
	endwin();
	return (0);
}
