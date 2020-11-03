/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:11:26 by tpons             #+#    #+#             */
/*   Updated: 2020/11/03 16:12:38 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	make_screenshot(t_param *p)
{
	int ss_fd;
	
	if ((ss_fd = open("screenshot.bpm", O_WRONLY | O_CREAT, 00777
				| O_APPEND | O_TRUNC)) < 0)
		leave(p, "Couldn't create the screenshot file");
	// header_screenshot(p, ss_fd, );
}

void    screenshot(t_param *p, char *s1)
{
    write(1, "Saving screenshot ...\n", 22);
    p->s->fd = open(s1, O_RDONLY);
    p->s->screenshot = 1;
	p->d->mlx_ptr = mlx_init();
	get_param(p->s->fd, p);
	play(p);
    make_screenshot(p);
	write(1, "Screenshot saved !\n", 19);
}