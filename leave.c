/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:59 by tpons             #+#    #+#             */
/*   Updated: 2020/11/02 14:11:34 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	leave(t_param *p, char *str)
{
	//free image struct & brut_map & map to avoid leaks
	ft_putstr("ERROR\n");
	ft_putstr(str);
	ft_putstr("\n");
	close(p->s->fd);
	exit(EXIT_FAILURE);
}

int		close_win(t_param *p)
{
	close(p->s->fd);
	mlx_destroy_window(p->d->mlx_ptr, p->d->win_ptr);
	exit(EXIT_SUCCESS);
	return (0);
}
