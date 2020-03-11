/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dda.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 12:11:08 by tpons             #+#    #+#             */
/*   Updated: 2020/03/11 13:42:00 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_player(t_param *p, int x, int y)
{
	if (p->s->map[x][y] == 'N')
	{
		p->d->plany = FOV;
		p->d->dirx = -1;
	}
	else if (p->s->map[x][y] == 'S')
	{
		p->d->plany = -FOV;
		p->d->dirx = 1;
	}
	else if (p->s->map[x][y] == 'W')
	{
		p->d->planx = -FOV;
		p->d->diry = -1;
	}
	else if (p->s->map[x][y] == 'E')
	{
		p->d->planx = FOV;
		p->d->diry = 1;
	}
}

void	set_sidedist(t_param *p)
{
	if (p->d->raydirx < 0)
	{
		p->d->stepx = -1;
		p->d->sidedistx = (p->s->pos_x - p->d->mapx) * p->d->deltadistx;
	}
	else
	{
		p->d->stepx = 1;
		p->d->sidedistx = (p->d->mapx + 1.0 - p->s->pos_x) * p->d->deltadistx;
	}
	if (p->d->raydiry < 0)
	{
		p->d->stepy = -1;
		p->d->sidedisty = (p->s->pos_y - p->d->mapy) * p->d->deltadisty;
	}
	else
	{
		p->d->stepy = 1;
		p->d->sidedisty = (p->d->mapy + 1.0 - p->s->pos_y) * p->d->deltadisty;
	}
}

void	set_walldist(t_param *p)
{
	p->d->hit = 0;
	p->d->side = 0;
	while (p->d->hit == 0)
	{
		if (p->d->sidedistx < p->d->sidedisty)
		{
			p->d->sidedistx += p->d->deltadistx;
			p->d->mapx += p->d->stepx;
			p->d->side = 0;
		}
		else
		{
			p->d->sidedisty += p->d->deltadisty;
			p->d->mapy += p->d->stepy;
			p->d->side = 1;
		}
		if (p->s->map[p->d->mapx][p->d->mapy] == '1')
			which_wall(p);
	}
	if (p->d->side == 1 || p->d->side == 2)
		p->d->walldist = (p->d->mapx - p->s->pos_x +
			(1 - p->d->stepx) / 2) / p->d->raydirx;
	else if (p->d->side == 3 || p->d->side == 4)
		p->d->walldist = (p->d->mapy - p->s->pos_y +
			(1 - p->d->stepy) / 2) / p->d->raydiry;
}

void	set_dda(t_param *p)
{
	p->d->camx = 2 * (double)p->d->screenx / (double)p->s->x - 1;
	p->d->raydirx = p->d->dirx + p->d->planx * p->d->camx;
	p->d->raydiry = p->d->diry + p->d->plany * p->d->camx;
	p->d->mapx = (int)p->s->pos_x;
	p->d->mapy = (int)p->s->pos_y;
	p->d->deltadistx = fabs(1 / p->d->raydirx);
	p->d->deltadisty = fabs(1 / p->d->raydiry);
	set_sidedist(p);
	set_walldist(p);
}

void	dda(t_param *p)
{
	p->d->screenx = 0;
	while (p->d->screenx < p->s->x)
	{
		set_dda(p);
		draw(p);
		p->b->buffer[p->d->screenx] = p->d->walldist;
		p->d->screenx++;
	}
}
