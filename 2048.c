/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2048.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:03:05 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/30 07:40:12 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void 	show_grid (Grid* g)
{
    int y;
	int	x;

	x = -1;
	y = -1;
    while (++y < 16)
	{
	 	while (++x < 16)
		{
            printw("%4d", g->grid[y][x]);
			if (x == 3 || x == 7 || x == 11)
				printw("\n");
		}
	}
    printw("\n");
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

/*WINDOW	**draw_menu(int start_col)
{
    int i;
    WINDOW **items;
    items=(WINDOW **)malloc(9*sizeof(WINDOW *));

    items[0]=newwin(10,19,1,start_col);
    box(items[0],ACS_VLINE,ACS_HLINE);
    items[1]=subwin(items[0],1,17,2,start_col+1);
    items[2]=subwin(items[0],1,17,3,start_col+1);
    items[3]=subwin(items[0],1,17,4,start_col+1);
    items[4]=subwin(items[0],1,17,5,start_col+1);
    items[5]=subwin(items[0],1,17,6,start_col+1);
    items[6]=subwin(items[0],1,17,7,start_col+1);
    items[7]=subwin(items[0],1,17,8,start_col+1);
    items[8]=subwin(items[0],1,17,9,start_col+1);
    for (i=1;i<9;i++)
        wprintw(items[i],"Item%d",i);
    wrefresh(items[0]);
    return items;
}*/


int main() 

{
	int score = 0;
	int key;

	Grid g = {{0,0,0,0, 
               0,0,0,0,
               0,0,0,0, 
               0,0,0,0}};

    initscr(); // Initialise la structure WINDOW et autres paramètres 
    raw();
	keypad(stdscr, TRUE);
	//noecho();
	curs_set(FALSE);
     while (1)         
	{   
		clear(); 
		       
		printw("Score %d\n", score); 
		show_grid(&g);
		key = getch();
		if (key == ENTER)
		{
			ft_put_random(&g);
			ft_put_random(&g);
		}
		if (key == KEY_UP)//|| key = KEY_DOWN || key == KEY_LEFT || key == KEY_RIGHT)
		{	
			ft_put_random(&g);
			show_grid(&g);
		}  
		else if (key == ESCAPE)
			return (-1);
		refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
	}
	endwin();               // Restaure les paramètres par défaut du terminal


	srand(time(NULL));
	return (0);
}



/*WINDOW **draw_menu(int start_col)
{
    int i;
    WINDOW **items;
    items=(WINDOW **)malloc(9*sizeof(WINDOW *));

    items[0]=newwin(10,19,1,start_col);
    wbkgd(items[0],COLOR_PAIR(2));
    box(items[0],ACS_VLINE,ACS_HLINE);
    items[1]=subwin(items[0],1,17,2,start_col+1);
    items[2]=subwin(items[0],1,17,3,start_col+1);
    items[3]=subwin(items[0],1,17,4,start_col+1);
    items[4]=subwin(items[0],1,17,5,start_col+1);
    items[5]=subwin(items[0],1,17,6,start_col+1);
    items[6]=subwin(items[0],1,17,7,start_col+1);
    items[7]=subwin(items[0],1,17,8,start_col+1);
    items[8]=subwin(items[0],1,17,9,start_col+1);
    for (i=1;i<9;i++)
        wprintw(items[i],"Item%d",i);
    wbkgd(items[1],COLOR_PAIR(1));
    wrefresh(items[0]);
    return items;
}*/

/*int			main(void)
{
	if (!test_errors())
	{
		ft_putendl("Votre objectif est une mauvaise valeur.");
		return (0);
	}
	game();
	   initscr();              // Initialise la structure WINDOW et autres paramètres 
	   printw("Hello World");  // Écrit Hello World à l'endroit où le curseur logique est positionné
	   refresh();              // Rafraîchit la fenêtre courante afin de voir le message apparaître
	   getch();                // On attend que l'utilisateur appui sur une touche pour quitter
	   endwin();               // Restaure les paramètres par défaut du terminal
	   
	return (0);
} */
