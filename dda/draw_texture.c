/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 14:03:03 by tpons             #+#    #+#             */
/*   Updated: 2020/03/05 17:33:29 by tpons            ###   ########.fr       */
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

// int		draw_textures(t_param *p, int y)
// {
// 	if (!p->d->side)
// 	{
		
// 	}
// 	else if (p->d->side == 1)
// 	{
		
// 	}
// 	else if (p->d->side == 2)
// 	{
		
// 	}
// 	else
// 	{
		
// 	}
// }
