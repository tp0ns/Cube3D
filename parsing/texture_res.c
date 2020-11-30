/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_res.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 13:45:24 by tpons             #+#    #+#             */
/*   Updated: 2020/11/30 15:03:20 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*cut_spaces(char *str)
{
	int	l;

	l = ft_strlen(str) - 1;
	while (str[l] == ' ' && l >= 0)
	{
		str[l] = '\0';
		l--;
	}
	return (str);
}

void	path_spaces(t_param *p, int flag)
{
	if (flag == 1)
		init_text(p, flag, cut_spaces(p->s->north));
	else if (flag == 2)
		init_text(p, flag, cut_spaces(p->s->south));
	else if (flag == 3)
		init_text(p, flag, cut_spaces(p->s->west));
	else if (flag == 4)
		init_text(p, flag, cut_spaces(p->s->east));
	else if (flag == 5)
		init_text(p, flag, cut_spaces(p->s->sprite));
}

void	init_text(t_param *p, int flag, char *path)
{
	int	endian;

	if (!(p->i[flag]->image_ptr = mlx_xpm_file_to_image(
			p->d->mlx_ptr, path, &p->i[flag]->width, &p->i[flag]->height)))
		leave(p, "Texture path isn't valid");
	p->i[flag]->image_data = mlx_get_data_addr(p->i[flag]->image_ptr,
			&p->i[flag]->bpp, &p->i[flag]->size_line, &endian);
}

void	push_text(char *line, t_param *p, int flag)
{
	int	i;

	i = 0;
	while (ft_isspace(line[i]) && line[i])
		i++;
	if (flag == 1)
		p->s->north = ft_strdup(&line[i]);
	else if (flag == 2)
		p->s->south = ft_strdup(&line[i]);
	else if (flag == 3)
		p->s->west = ft_strdup(&line[i]);
	else if (flag == 4)
		p->s->east = ft_strdup(&line[i]);
	else if (flag == 5)
		p->s->sprite = ft_strdup(&line[i]);
	path_spaces(p, flag);
}

void	push_res(char *line, t_param *p)
{
	int	i;

	i = 0;
	mlx_get_screen_size(p->d->mlx_ptr, &p->s->screen_res_x,
		&p->s->screen_res_y);
	p->s->x = ft_atoi(&line[i]);
	while (line[i] == ' ' && line[i])
		i++;
	while (line[i] >= '0' && line[i] <= '9' && line[i])
		i++;
	p->s->y = ft_atoi(&line[i]);
	if (p->s->x > p->s->screen_res_x)
		p->s->x = p->s->screen_res_x;
	else if (p->s->x < 1)
		leave(p, "Resolution is too low or isn't given");
	if (p->s->y > p->s->screen_res_y)
		p->s->y = p->s->screen_res_y;
	else if (p->s->y < 1)
		leave(p, "Resolution is too low or isn't given");
	if (!(p->b->buffer = malloc(sizeof(double) * (p->s->x + 1))))
		leave(p, "Memory allocation failed");
}
