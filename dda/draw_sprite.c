/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:58:13 by tpons             #+#    #+#             */
/*   Updated: 2020/03/11 14:13:21 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	dist_sprite(t_param *p)
{
	int	i;

	i = 0;
	while (i < p->b->nb_sprite)
	{
		p->z[i]->s_order = i;
		p->z[i]->s_dist = ((p->s->pos_x - p->z[i]->x) * (p->s->pos_x -
		p->z[i]->x) + (p->s->pos_y - p->z[i]->y) * (p->s->pos_y - p->z[i]->y));
		i++;
	}
}

void	sort_sprite(t_param *p)
{
	t_sprite	*swap;
	int			i;

	i = 0;
	while (i < p->b->nb_sprite)
	{
		if (p->z[i]->s_dist < p->z[i + 1]->s_dist && (i + 1) != p->b->nb_sprite)
		{
			swap = p->z[i];
			p->z[i] = p->z[i + 1];
			p->z[i + 1] = p->z[i];
			i = -1;
		}
		i++;
	}
}

void	draw_sprite(t_param *p)
{
	if (p->b->drawstarty < 0)
		p->b->drawstarty = 0;
	p->b->drawendy = p->b->spriteheight / 2 + p->s->y / 2;
	if (p->b->drawendy >= p->s->y)
		p->b->drawendy = p->s->y - 1;
	p->b->spritewidth = abs((int)(p->s->y / (p->b->transformy)));
	p->b->drawstartx = -p->b->spritewidth / 2 + p->b->spritescreenx;
	if (p->b->drawstartx < 0)
		p->b->drawstartx = 0;
	p->b->drawendx = p->b->spritewidth / 2 + p->b->spritescreenx;
	if (p->b->drawendx >= p->s->x)
		p->b->drawendx = p->s->x - 1;
}

void	set_sprite(t_param *p)
{
	int	i;

	i = 0;
	dist_sprite(p);
	sort_sprite(p);
	while (i < p->b->nb_sprite)
	{
		p->b->spritex = p->z[i]->x - p->s->pos_x;
		p->b->spritey = p->z[i]->y - p->s->pos_y;
		p->b->invdet = 1.0 / (p->d->planx * p->d->diry - p->d->dirx *
		p->d->plany);
		p->b->transformx = p->b->invdet * (p->d->diry * p->b->spritex -
		p->d->dirx * p->b->spritey);
		p->b->transformy = p->b->invdet * (-p->d->plany *
		p->b->spritex + p->d->planx * p->b->spritey);
		p->b->spritescreenx = (int)((p->s->x / 2) *
		(1 + p->b->transformx / p->b->transformy));
		p->b->spriteheight = abs((int)(p->s->y / (p->b->transformy)));
		p->b->drawstarty = -p->b->spriteheight / 2 + p->s->y / 2;
		draw_sprite(p);
		i++;
	}
}
