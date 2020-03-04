/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:18:07 by tpons             #+#    #+#             */
/*   Updated: 2020/03/04 16:03:33 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	forward(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x + p->d->dirx * MS)]
	[(int)p->s->pos_y] == 'O')
		p->s->pos_x += p->d->dirx * MS;
	if (p->s->map[(int)p->s->pos_x]
	[(int)(p->s->pos_y + p->d->diry * MS)] == 'O')
		p->s->pos_y += p->d->diry * MS;
}

void	backward(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x - p->d->dirx * MS)]
	[(int)p->s->pos_y] == 'O')
		p->s->pos_x -= p->d->dirx * MS;
	if (p->s->map[(int)p->s->pos_x]
	[(int)(p->s->pos_y - p->d->diry * MS)] == 'O')
		p->s->pos_y -= p->d->diry * MS;
}

void	left(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x - p->d->planx * MS)]
	[(int)p->s->pos_y] == 'O')
		p->s->pos_x -= p->d->planx * MS;
	if (p->s->map[(int)p->s->pos_x]
	[(int)(p->s->pos_y - p->d->plany * MS)] == 'O')
		p->s->pos_y -= p->d->plany * MS;
}

void	right(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x + p->d->planx * MS)]
	[(int)p->s->pos_y] == 'O')
		p->s->pos_x += p->d->planx * MS;
	if (p->s->map[(int)p->s->pos_x]
	[(int)(p->s->pos_y + p->d->plany * MS)] == 'O')
		p->s->pos_y += p->d->plany * MS;
}

void	rotate(t_param *p, int key)
{
	double olddirx;
	double oldplanex;

	if (key == 124)
	{
		olddirx = p->d->dirx;
		p->d->dirx = p->d->dirx * cos(-RS) - p->d->diry * sin(-RS);
		p->d->diry = olddirx * sin(-RS) + p->d->diry * cos(-RS);
		oldplanex = p->d->planx;
		p->d->planx = p->d->planx * cos(-RS) - p->d->plany * sin(-RS);
		p->d->plany = oldplanex * sin(-RS) + p->d->plany * cos(-RS);
	}
	if (key == 123)
	{
		olddirx = p->d->dirx;
		p->d->dirx = p->d->dirx * cos(RS) - p->d->diry * sin(RS);
		p->d->diry = olddirx * sin(RS) + p->d->diry * cos(RS);
		oldplanex = p->d->planx;
		p->d->planx = p->d->planx * cos(RS) - p->d->plany * sin(RS);
		p->d->plany = oldplanex * sin(RS) + p->d->plany * cos(RS);
	}
}
