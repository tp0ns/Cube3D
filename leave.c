/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:59 by tpons             #+#    #+#             */
/*   Updated: 2020/11/25 15:56:07 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map(t_param *p)
{
	int	j;

	j = 0;
	free(p->s->linear_map);
	while (j <= p->s->max_x && p->s->brut_map)
		free(p->s->brut_map[j++]);
	free(p->s->brut_map);
	j = 0;
	while (j <= p->s->max_x && p->s->map)
		free(p->s->map[j++]);
	free(p->s->map);
}

void	free_images(t_param *p)
{
	int	j;

	j = 0;
	while (j <= p->b->nb_sprite && p->b->nb_sprite != 0 && p->z)
		free(p->z[j++]);
	j = 1;
	free(p->i[0]);
	while (j <= 5)
	{
		if (p->i[j]->image_ptr)
			mlx_destroy_image(p->d->mlx_ptr, p->i[j]->image_ptr);
		free(p->i[j]);
		j++;
	}
}

void	free_all(t_param *p)
{
	free_images(p);
	free_map(p);
	free(p->s->north);
	free(p->s->south);
	free(p->s->west);
	free(p->s->east);
	free(p->s->sprite);
	free(p->b->buffer);
	free(p->b);
	free(p->s);
	free(p->z);
	free(p->i);
}

void	leave(t_param *p, char *str)
{
	if (p->s->fd >= 0)
		close(p->s->fd);
	free_all(p);
	if (p->d->win_ptr)
		mlx_destroy_window(p->d->mlx_ptr, p->d->win_ptr);
	free(p->d->mlx_ptr);
	free(p->d);
	ft_putstr("ERROR\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(EXIT_FAILURE);
}

int		close_win(t_param *p)
{
	close(p->s->fd);
	free_all(p);
	mlx_destroy_window(p->d->mlx_ptr, p->d->win_ptr);
	free(p->d->mlx_ptr);
	free(p->d);
	exit(EXIT_SUCCESS);
	return (0);
}
