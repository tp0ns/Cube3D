/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprite.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 10:58:13 by tpons             #+#    #+#             */
/*   Updated: 2020/03/11 15:24:39 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	sort_dist_sprite(t_param *p)
{
	int			i;
	t_sprite	*swap;

	i = 0;
	while (i < p->b->nb_sprite)
	{
		p->z[i]->s_order = i;
		p->z[i]->s_dist = ((p->s->pos_x - p->z[i]->x) * (p->s->pos_x -
		p->z[i]->x) + (p->s->pos_y - p->z[i]->y) * (p->s->pos_y - p->z[i]->y));
		i++;
	}
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
	int	y;

	while (p->b->stripe < p->b->drawendx)
	{
		p->b->texx = (int)(256 * (p->b->stripe - (-p->b->spritewidth / 2 +
		p->b->spritescreenx)) * p->i[5]->width / p->b->spritewidth) / 256;
		y = p->b->drawstarty;
		while (y < p->b->drawendy)
		{
			p->b->d = y * 256 - p->s->y * 128 + p->b->spriteheight * 128;
			p->b->texy = ((p->b->d * p->i[5]->height) / p->b->spriteheight)
			/ 256;
			if (!is_black(p))
			{
				
			}
			y++;
		}
		p->b->stripe++;
	}
}

void	set_sprite(t_param *p)
{
	int	i;

	i = 0;
	sort_dist_sprite(p);
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
		set_sprite_b(p);
		draw_sprite(p);
		i++;
	}
}
