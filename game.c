/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:42:16 by tpons             #+#    #+#             */
/*   Updated: 2020/11/05 10:03:00 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_management(int key, t_param *p)
{
	if (key == 65307)
		close_win(p);
	else if (key == 119)
		forward(p);
	else if (key == 115)
		backward(p);
	else if (key == 97)
		left(p);
	else if (key == 100)
		right(p);
	else if (key == 65363 || key == 65361)
		rotate(p, key);
	// else if (key == 97)
	// 	rotate(p, key);
	return (0);
}

int		play(t_param *p)
{
	int endian;

	p->i[0]->image_ptr = mlx_new_image(p->d->mlx_ptr, p->s->x, p->s->y);
	p->i[0]->image_data = mlx_get_data_addr(p->i[0]->image_ptr, &p->i[0]->bpp,
		&p->i[0]->size_line, &endian);
	dda(p);
	if (!p->s->screenshot)
	{
		mlx_put_image_to_window(p->d->mlx_ptr, p->d->win_ptr,
		p->i[0]->image_ptr, 0, 0);
		mlx_destroy_image(p->d->mlx_ptr, p->i[0]->image_ptr);
	}
	return (0);
}

void	game(t_param *p)
{
	p->d->win_ptr = mlx_new_window(p->d->mlx_ptr,
		p->s->x, p->s->y, "Cub3D");
	mlx_hook(p->d->win_ptr, 2, 5, key_management, p);
	mlx_hook(p->d->win_ptr, 17, 1, close_win, p);
	mlx_loop_hook(p->d->mlx_ptr, play, p);
	mlx_loop(p->d->mlx_ptr);
}
