/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:03:05 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/30 05:01:28 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"
#include <stdio.h>

void 	showGrid (Grid* g)
{
    int y;
	int	x;

	x = -1;
	y = -1;
    while (++y < 16)
	{
	 	while (++x < 16)
		{
            printf ("%4d", g->grid[y][x]);
			if (x == 3 || x == 7 || x == 11)
				printf("\n");
		}
	}
    printf ("\n");
}

void	ft_put_random(Grid *g)
{
	int y;
	int x;

	y = rand()%4;
	x = rand()%4;
	if (rand()%2 == 0)
	{
		while (g->grid[y][x] != 0)
		{
			y = rand()%4;
			x = rand()%4;
		}
		g->grid[y][x] = 2;
	}
	else
	{
		while (g->grid[y][x] != 0)
		{
			y = rand()%4;
			x = rand()%4;
		}
		g->grid[y][x] = 4;
	}
}

int main() 
{
	int x = 0;
	Grid g = {{0,0,0,0, 
               0,0,0,0,
               0,0,0,0, 
               0,0,0,0}};

    showGrid(&g);
    ft_putchar('\n');
    ft_putchar('\n');
    ft_putchar('\n');

	srand(time(NULL));

	ft_put_random(&g);
	showGrid(&g);

	return (0);

}
