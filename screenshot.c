/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screenshot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 14:11:26 by tpons             #+#    #+#             */
/*   Updated: 2020/11/25 14:29:05 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	flip_screenshot(t_param *p)
{
	int		line_length;
	int		cursor_image;
	int		cursor_line;
	int		fill;
	char	*new_str;

	line_length = p->s->x * 4;
	cursor_image = ((p->s->x * p->s->y) * 4) - line_length;
	fill = 0;
	if (!(new_str = malloc(sizeof(char) * (((p->s->x * p->s->y) * 4) + 1))))
		leave(p, "Oupsie, something bad happend during memory allocation");
	new_str[(p->s->x * p->s->y) * 4] = '\0';
	while (cursor_image >= 0)
	{
		cursor_line = 0;
		while (cursor_line < line_length)
		{
			new_str[fill] = p->i[0]->image_data[cursor_image + cursor_line];
			cursor_line++;
			fill++;
		}
		cursor_image = cursor_image - line_length;
	}
	mlx_destroy_image(p->d->mlx_ptr, p->i[0]->image_ptr);
	p->i[0]->image_data = new_str;
}

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
}

void	make_screenshot(t_param *p)
{
	int	ss_fd;
	int	file_size;
	int	first_pix;
	int i;
	int	j;

	i = (p->s->x * p->s->y) * 4 - 1;
	j = 0;
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
	flip_screenshot(p);
	while (j <= i)
	{
		write(ss_fd, &p->i[0]->image_data[j], 1);
		j++;
	}
}

void	screenshot(t_param *p, char *s1)
{
	write(1, "Saving screenshot ...\n", 22);
	p->s->fd = open(s1, O_RDONLY);
	p->s->screenshot = 1;
	p->d->mlx_ptr = mlx_init();
	get_param(p->s->fd, p);
	play(p);
	make_screenshot(p);
	write(1, "Screenshot saved !\n", 19);
	free(p->i[0]->image_data);
	close(p->s->fd);
	free_all(p);
	free(p->d->mlx_ptr);
	free(p->d);
	exit(EXIT_SUCCESS);
}
