/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/30 07:38:57 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef RUSH_H
#define RUSH_H

#define ENTER 10
#define ESCAPE 27

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <ncurses.h>
#include <termios.h>
#include "libft.h"

enum e_const
{
	WIN_VALUE = 2048
};


typedef struct s_grid 
{
    char grid[4][4];
} 				t_grid;

void 	srand (unsigned int seed);
int  	rand (void);
void	ft_tab(int y, int x);
void	ft_put_random(struct s_grid *g);
int		ft_rand(void);
void	ft_print_tab(struct s_grid *g);
void	init_tab(struct s_grid *g);
void	check_key(int key);
void 	pre_launcher(struct s_grid *g);
void 	launcher(int key);

#endif
