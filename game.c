/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 10:42:16 by tpons             #+#    #+#             */
/*   Updated: 2020/03/03 12:15:07 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int		key_management(int key, void *param)
{
	// printf("%d", key);
	if (key == 53)
		close_win();
	return (0);
}

void	game(t_param *p)
{
	p->d->mlx_ptr = mlx_init();
	p->d->win_ptr = mlx_new_window(p->d->mlx_ptr,
		p->s->x, p->s->y, "Cub3D");
	mlx_key_hook(p->d->win_ptr, key_management, (void *)0);
	mlx_hook(p->d->win_ptr, 17, 1, close_win, (void *)0);
	dda(p);
	// game(p);
	// mlx_loop_hook(p->d->mlx_ptr, game, p);
	mlx_loop(p->d->mlx_ptr);
}
