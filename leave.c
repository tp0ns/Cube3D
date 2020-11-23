/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:59 by tpons             #+#    #+#             */
/*   Updated: 2020/11/23 13:53:49 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_images(t_param *p)
{
	int	j;

	j = 0;
	while(p->s->free_flag >= 1 && j <= p->b->nb_sprite)
		free(p->z[j++]);
	j = 0;
	while(j <= 5)
	{
		free(p->i[j]->image_data);
		free(p->i[j]);
		j++;
	}
}

void	free_all(t_param *p)
{
	int	j;

	j = 0;
	free(p->s->north);
	free(p->s->south);
	free(p->s->west);
	free(p->s->east);
	free(p->s->sprite);
	free(p->b->buffer);
	free_images(p);
	free(p->d);
	free(p->b);
	free(p->z);
	free(p->i);
}

void	leave(t_param *p, char *str)
{
	//free image struct & brut_map & map to avoid leaks
	ft_putstr("ERROR\n");
	ft_putstr(str);
	ft_putstr("\n");
	close(p->s->fd);
	free(p->d->mlx_ptr);
	free_all(p);
	exit(EXIT_FAILURE);
}

int		close_win(t_param *p)
{
	close(p->s->fd);
	mlx_destroy_window(p->d->mlx_ptr, p->d->win_ptr);
	free(p->d->mlx_ptr);
	free_all(p);
	exit(EXIT_SUCCESS);
	return (0);
}
