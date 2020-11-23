/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:00:04 by tpons             #+#    #+#             */
/*   Updated: 2020/11/23 13:30:10 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	set_sprite_b(t_param *p)
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
	p->b->stripe = p->b->drawstartx;
}

void	push_sprite(t_param *p)
{
	int	x;
	int	y;
	int	i;

	x = 0;
	i = 0;
	while (p->s->map[x])
	{
		y = 0;
		while (p->s->map[x][y] != '\0')
		{
			if (p->s->map[x][y] == 'Z')
			{
				p->z[i]->x = x;
				p->z[i]->y = y;
				i++;
			}
			y++;
		}
		x++;
	}
}

void	sprite(t_param *p)
{
	int	x;

	x = 0;
	if (!(p->z = malloc(sizeof(t_sprite *) * (p->b->nb_sprite + 1))))
		leave(p, "Something went wrong with sprite initialization");
	ft_bzero(p->z, sizeof(t_sprite *) * (p->b->nb_sprite + 1));
	while (x <= p->b->nb_sprite)
	{
		if (!(p->z[x] = malloc(sizeof(t_sprite))))
			leave(p, "Something went wrong with sprite initialization - 2");
		ft_bzero(p->z[x++], sizeof(t_sprite));
	}
	p->s->free_flag = 2;
	push_sprite(p);
}