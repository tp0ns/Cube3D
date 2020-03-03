/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:30:43 by tpons             #+#    #+#             */
/*   Updated: 2020/03/03 16:05:49 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_line(t_param *p)
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

	p->d->image_ptr = mlx_new_image(p->d->mlx_ptr, p->s->x, p->s->y);
	p->d->image_data = mlx_get_data_addr(p->d->image_ptr, &p->d->bpp,
	 	&p->d->size_line, &endian);
}
