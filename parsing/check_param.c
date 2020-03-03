/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 10:31:01 by tpons             #+#    #+#             */
/*   Updated: 2020/03/03 11:49:06 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	map_size(t_param *p)
{
	int	x;
	int y;
	
	x = 0;
	while (p->s->brut_map[x])
	{
		y = 0;
		while (p->s->brut_map[x][y])
			y++;
		if (y > p->s->max_y)
			p->s->max_y = y;
		x++;
	}
	p->s->max_x = x;
}

void	init_map(t_param *p)
{
	int	x;
	int	y;

	x = 0;
	map_size(p);
	if(!(p->s->map = malloc(sizeof(char *) * (p->s->max_x + 2))))
		leave("Something went wrong during map initialization");
	p->s->map[p->s->max_x + 1] = '\0';
	while (x <= p->s->max_x)
	{
		y = 0;
		if(!(p->s->map[x] = malloc(sizeof(char) * (p->s->max_y + 2))))
			leave("Something went wrong during map initialization");
		while (y < p->s->max_y)
		{
			p->s->map[x][y] = '-';
			y++;
		}
		p->s->map[x][p->s->max_y] = '\0';
		x++;
	}
}

void	match_maps(t_param *p)
{
	int	x;
	int	y;
	int	player;

	x = 0;
	player = 0;
	while (x < p->s->max_x)
	{
		y = 0;
		while (p->s->brut_map[x][y])
		{
			p->s->map[x][y] = p->s->brut_map[x][y];
			if (p->s->brut_map[x][y] == 'N' || p->s->brut_map[x][y] == 'S'
			 || p->s->brut_map[x][y] == 'W' || p->s->brut_map[x][y] == 'E')
			{
				p->s->pos_x = (double)x + 0.5;
				p->s->pos_y = (double)y + 0.5;
				player++;
			}
			y++;
		}
		x++;
	}
	if (player != 1)
		leave("Too much or too few players in scene file");
}

void	check_map(t_param *p, int x, int y)
{
	if (p->s->map[x][y] == '1' || p->s->map[x][y] == 'O'
	 || p->s->map[x][y] == 'Z')
	 return ;
	if (x == 0 || y == 0 || p->s->map[x][y] == '-' || p->s->map[x][y] == '\0')
	 	leave("Map isn't closed around player's spawn");
	if (p->s->map[x][y] == '0')
		p->s->map[x][y] = 'O';
	else if (p->s->map[x][y] == '2')
		p->s->map[x][y] = 'Z';
	check_map(p, x + 1, y);
	check_map(p, x, y + 1);
	check_map(p, x - 1, y);
	check_map(p, x, y - 1);
}

void	check_param(t_param *p)
{
	if (!p->s->c_col || !p->s->f_col || !p->s->x || !p->s->y || !p->s->north
		 || !p->s->south || !p->s->west || !p->s->east || !p->s->sprite)
		leave("Not enough informations in scene file");
	init_map(p);
	match_maps(p);
	check_map(p, (int)p->s->pos_x, (int)p->s->pos_y);
}