/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/11 11:00:04 by tpons             #+#    #+#             */
/*   Updated: 2020/03/11 13:41:36 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
		leave("Something went wrong with sprite initialization");
	ft_bzero(p->z, sizeof(t_sprite *) * (p->b->nb_sprite + 1));
	while (x <= p->b->nb_sprite)
	{
		if (!(p->z[x] = malloc(sizeof(t_sprite))))
			leave("Something went wrong with sprite initialization - 2");
		ft_bzero(p->z[x++], sizeof(t_sprite));
	}
	push_sprite(p);
}