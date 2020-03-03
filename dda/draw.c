/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:30:43 by tpons             #+#    #+#             */
/*   Updated: 2020/03/03 17:52:17 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_lineheight(t_param *p)
{
	p->d->lineheight = (int)(p->s->y / p->d->walldist);
    p->d->drawstart = -p->d->lineheight / 2 + p->s->y / 2;
    if(p->d->drawstart < 0)
		p->d->drawstart = 0;
    p->d->drawend = p->d->lineheight / 2 + p->s->y / 2;
    if(p->d->drawend >= p->s->y)
		p->d->drawend = p->s->y - 1;
}

void	draw(t_param *p)
{
	int endian;
	int	y;

	y = 0;
	set_lineheight(p);
	while (y < p->d->drawstart)
		y++;
	while (y < p->d->drawend)
	{
		p->d->image_data[p->d->screenx * p->d->bpp / 8 + p->d->size_line * y] = 0xFFFFFF;
		y++;
	}
}
