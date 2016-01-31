/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 07:51:01 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/31 07:51:04 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	create_tab(int y, int x)
{
	while (++y < LINES)
		mvprintw(y, 0, "|||");
	y = 0;
	while (++y < LINES)
		mvprintw(y, (COLS / 2), "|||");
	y = 0;
	while (++y < LINES)
		mvprintw(y, (COLS - 1), "|||");
	y = 0;
	while (++y < LINES)
		mvprintw(y, (COLS / 4), "|||");
	y = 0;
	while (++y < LINES)
		mvprintw(y, ((COLS / 4) * 3), "|||");
	while (++x < COLS)
		mvprintw(0, x, "*");
	x = 0;
	while (++x < COLS)
		mvprintw((LINES / 2), x, "*");
		x++;
	x = 0;
	while (++x < COLS)
		mvprintw((LINES - 1), x, "*");
	x = 0;
	while (++x < COLS)
		mvprintw((LINES / 4), x, "*");
	x = 0;
	while (++x < COLS)
		mvprintw(((LINES / 4) * 3), x, "*");
}

void	ft_put_random(struct s_grid *g)
{
	int x;
	int y;

	x = rand() % 4;
	y = rand() % 4;
	if (rand() % 2 == 0)
	{
		while (g->grid[x][y] != 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		g->grid[y][x] = 2;
		mvprintw(y, x, "%d", g->grid[y][x]);

	}
	else
	{
		while (g->grid[y][x] != 0)
		{
			x = rand() % 4;
			y = rand() % 4;
		}
		g->grid[y][x] = 4;
		mvprintw(y, x, "%d", g->grid[y][x]);
	}
	
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

void	ft_print_tab(struct s_grid *g)
{
	int y;
	int x;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			mvprintw((y * LINES / 4) + LINES / 8,(x * COLS / 4) + COLS / 8, "%d", g->grid[y][x]);
	}
}

void	init_tab(struct s_grid *g)
{
	int y;
	int x;
	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
		g->grid[y][x] = 0;	
	}
}

void	check_key(int key)
{
	int x;
	int y;

	x = COLS / 8;
	y = LINES / 8;

		if (key == KEY_DOWN)
	{
		if (y == (LINES / 8) + (3 * (LINES / 4)))
			y = y;
		else
			y = y + (LINES / 4);
	}
	else if (key == KEY_UP)
	{
		if (y == LINES / 8)
			y = y;
		else
			y = y - (LINES / 4);
	}
	else if (key == KEY_LEFT)
	{
		if (x == COLS / 8)
			x = x;
		else
			x = x - (COLS / 4);
	}
	else if (key == KEY_RIGHT)
	{
		if (x == (COLS / 8) + (3 * (COLS / 4)))
			x = x;
		else
			x = x + (COLS / 4);
	}
}

void 	pre_launcher(struct s_grid *g)
{
	create_tab(0, 0);
	init_tab(g);
	ft_print_tab(g);
}

void 	launcher(int key)
{
	struct s_grid	*g;

	g = (t_grid*)malloc(sizeof(t_grid));
	initscr();
	raw();
	keypad(stdscr, TRUE);
	noecho();
	curs_set(FALSE);
	while (1)
	{
		clear();
		pre_launcher(g);
		key = getch();
		if (key == ESCAPE)
			break ;
		if (key == ENTER)
		{
			ft_put_random(g);
			ft_put_random(g);
		}
	
		check_key(key);
		refresh();
	}
	endwin();
}

int		main(void)
{	
	int		key;
	int		x;
	int		y;
	int 	n;

	n = ft_rand();
	mvprintw(y, x, "%d", n);
	launcher(key);
	return (0);
}
