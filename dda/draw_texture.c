/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:03:03 by tpons             #+#    #+#             */
/*   Updated: 2020/03/10 14:46:47 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	which_wall(t_param *p)
{
	p->d->hit = 1;
	if (!p->d->side)
	{
		if (p->d->raydirx < 0)
			p->d->side = 1;
		else if (p->d->raydirx > 0)
			p->d->side = 2;
	}
	else if (p->d->side == 1)
	{
		if (p->d->raydiry < 0)
			p->d->side = 3;
		else if (p->d->raydiry > 0)
			p->d->side = 4;
	}
}

void	set_texture(t_param *p)
{
	if (p->d->side == 1 || p->d->side == 2)
	{
		p->d->wallx = p->s->pos_y + p->d->walldist * p->d->raydiry;
		p->d->wallx -= floor(p->d->wallx);
		p->d->textx = (int)(p->d->wallx * (double)p->i[p->d->side]->width);
		if (p->d->raydirx > 0)
			p->d->textx = p->i[p->d->side]->width - p->d->textx - 1;
	}
	else if (p->d->side == 3 || p->d->side == 4)
	{
		p->d->wallx = p->s->pos_x + p->d->walldist * p->d->raydirx;
		p->d->wallx -= floor(p->d->wallx);
		p->d->textx = (int)(p->d->wallx * (double)p->i[p->d->side]->width);
		if (p->d->raydiry < 0)
			p->d->textx = p->i[p->d->side]->width - p->d->textx - 1;
	}
}

int		draw_textures(t_param *p, int y)
{
	int i;

	i = 0;
	set_texture(p);
	p->d->step = y * p->i[0]->size_line - p->s->y * p->i[p->d->side]->size_line + p->d->lineheight * p->i[p->d->side]->size_line;
	p->d->textpos = (p->d->drawstart - p->s->y / 2 + p->d->lineheight / 2) * p->d->step;
	while (y < p->d->drawend)
	{
		p->d->texty = (int)p->d->textpos & (p->i[p->d->side]->height - 1);
		p->d->textpos += p->d->step;
		// p->d->texty = ((p->d->step * p->i[p->d->side]->height) / p->d->lineheight) / p->i[p->d->side]->size_line;
		p->i[0]->image_data[p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y] 
			= p->i[p->d->side]->image_data[p->d->textx * (p->i[p->d->side]->bpp / 8) + p->d->texty * p->i[p->d->side]->size_line];
		p->i[0]->image_data[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 1]
			= p->i[p->d->side]->image_data[(p->d->textx * (p->i[p->d->side]->bpp / 8) + p->d->texty * p->i[p->d->side]->size_line) + 1];
		p->i[0]->image_data[(p->d->screenx * p->i[0]->bpp / 8 + p->i[0]->size_line * y) + 2]
			= p->i[p->d->side]->image_data[(p->d->textx * (p->i[p->d->side]->bpp / 8) + p->d->texty * p->i[p->d->side]->size_line) + 2];
		y++;
		i++;
	}
	return (i);
}
