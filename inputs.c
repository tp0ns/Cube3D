/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/04 14:18:07 by tpons             #+#    #+#             */
/*   Updated: 2020/03/04 17:44:25 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	forward(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x + p->d->dirx * M)][(int)p->s->pos_y] != '1'
	&& p->s->map[(int)(p->s->pos_x + p->d->dirx * M)][(int)p->s->pos_y] != 'Z')
		p->s->pos_x += p->d->dirx * M;
	if (p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y + p->d->diry * M)] != '1'
	&& p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y + p->d->diry * M)] != 'Z')
		p->s->pos_y += p->d->diry * M;
}

void	backward(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x - p->d->dirx * M)][(int)p->s->pos_y] != '1'
	&& p->s->map[(int)(p->s->pos_x - p->d->dirx * M)][(int)p->s->pos_y] != '2')
		p->s->pos_x -= p->d->dirx * M;
	if (p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y - p->d->diry * M)] != '1'
	&& p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y - p->d->diry * M)] != 'Z')
		p->s->pos_y -= p->d->diry * M;
}

void	left(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x - p->d->planx * M)][(int)p->s->pos_y] != '1'
	&& p->s->map[(int)(p->s->pos_x - p->d->planx * M)][(int)p->s->pos_y] != 'Z')
		p->s->pos_x -= p->d->planx * M;
	if (p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y - p->d->plany * M)] != '1'
	&& p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y - p->d->plany * M)] != 'Z')
		p->s->pos_y -= p->d->plany * M;
}

void	right(t_param *p)
{
	if (p->s->map[(int)(p->s->pos_x + p->d->planx * M)][(int)p->s->pos_y] != '1'
	&& p->s->map[(int)(p->s->pos_x + p->d->planx * M)][(int)p->s->pos_y] != 'Z')
		p->s->pos_x += p->d->planx * M;
	if (p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y + p->d->plany * M)] != '1'
	&& p->s->map[(int)p->s->pos_x][(int)(p->s->pos_y + p->d->plany * M)] != 'Z')
		p->s->pos_y += p->d->plany * M;
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
