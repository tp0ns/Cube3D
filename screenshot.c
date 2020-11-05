/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:11:26 by tpons             #+#    #+#             */
/*   Updated: 2020/11/05 14:48:21 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	header_screenshot(int fd, t_param *p)
{
	int infoheader_size;
	int	plane_number;
	int	i;
	int j;

	infoheader_size = 40;
	plane_number = 1;
	i = 0;
	j = 0;
	write(fd, &infoheader_size, 4);
	write(fd, &p->s->x, 4);
	write(fd, &p->s->y, 4);
	write(fd, &plane_number, 2);
	write(fd, &p->i[0]->bpp, 2);
	while (i < 32)
	{
		write(fd, "\0", 1);
		i++;
	}
	i = (p->s->x * p->s->y) * 4 - 1;
	while (j <= i)
	{
		write(fd, &p->i[0]->image_data[j], 1);
		j++;
	}
}

void	make_screenshot(t_param *p)
{
	int	ss_fd;
	int	file_size;
	int	first_pix;
	
	if ((ss_fd = open("screenshot.bmp", O_WRONLY | O_CREAT, 00777
				| O_APPEND | O_TRUNC)) < 0)
		leave(p, "Couldn't create the screenshot file");
	file_size = 14 + 40 + 4 + ((p->s->y * p->s->x) * 4);
	first_pix = 14 + 40 + 4;
	write(ss_fd, "BM", 2);
	write(ss_fd, &file_size, 4);
	write(ss_fd, "\0\0\0\0", 4);
	write(ss_fd, &first_pix, 4);
	header_screenshot(ss_fd, p);
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