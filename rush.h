/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vbraeke <vbraeke@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/30 00:00:50 by vbraeke           #+#    #+#             */
/*   Updated: 2016/01/30 04:33:22 by vbraeke          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# ifndef RUSH_H
#define RUSH_H

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

enum e_const
{
	WIN_VALUE = 2048
};

typedef struct grid 
{
    char grid[4][4];
} 			Grid;

void srand (unsigned int seed);
int rand (void);

#endif
