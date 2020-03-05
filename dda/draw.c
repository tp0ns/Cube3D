/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 15:30:43 by tpons             #+#    #+#             */
/*   Updated: 2020/03/05 17:34:26 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_lineheight(t_param *p)
{
	p->d->lineheight = (int)(p->s->y / p->d->walldist);
	p->d->drawstart = -p->d->lineheight / 2 + p->s->y / 2;
	if (p->d->drawstart < 0)
		p->d->drawstart = 0;
	p->d->drawend = p->d->lineheight / 2 + p->s->y / 2;
	if (p->d->drawend >= p->s->y)
		p->d->drawend = p->s->y - 1;
}

int		draw_ceiling(t_param *p, int y)
{
	int	r;
	int	g;
	int	b;

	r = p->s->c_col % 256;
	g = (p->s->c_col / 256) % 256;
	b = ((p->s->c_col / 256) / 256) % 256;
	while (y < p->d->drawstart)
	{
		p->i[0]->image_data
			[p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y] = r;
		p->i[0]->image_data
			[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 1] = g;
		p->i[0]->image_data
			[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 2] = b;
		y++;
	}
	return (y);
}

void	draw_floor(t_param *p, int y)
{
	int	r;
	int	g;
	int	b;

	r = p->s->f_col % 256;
	g = (p->s->f_col / 256) % 256;
	b = ((p->s->f_col / 256) / 256) % 256;
	while (y < p->s->y)
	{
		p->i[0]->image_data
			[p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y] = r;
		p->i[0]->image_data
			[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 1] = g;
		p->i[0]->image_data
			[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 2] = b;
		y++;
	}
}

void	draw(t_param *p)
{
	int	y;

	y = 0;
	set_lineheight(p);
	y += draw_ceiling(p, y);
	while (y < p->d->drawend)
	{
		p->i[0]->image_data
			[p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y] = 0xAAAAAA;
		y++;
	}
	// y += draw_textures(p, y);
	draw_floor(p, y);
}
