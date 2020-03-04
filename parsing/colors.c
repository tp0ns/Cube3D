/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:08 by tpons             #+#    #+#             */
/*   Updated: 2020/03/04 19:08:29 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	color_check(int r, int g, int b)
{
	if (r > 255 || r < 0 || g > 255 || g < 0 || b > 255 || b < 0)
		leave("RGB values should be between 0 and 255");
}

void	push_f_col(char *line, t_param *p)
{
	int	i;
	int	f_r;
	int	f_g;
	int	f_b;

	i = 0;
	f_r = ft_atoi(line);
	while (line[i] != ',')
		i++;
	f_g = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	f_b = ft_atoi(line + i + 1);
	color_check(f_r, f_g, f_b);
	p->s->f_col = f_r;
	p->s->f_col = (p->s->f_col << 8) + f_g;
	p->s->f_col = (p->s->f_col << 8) + f_b;
}

void	push_c_col(char *line, t_param *p)
{
	int	i;
	int	c_r;
	int	c_g;
	int	c_b;

	i = 0;
	c_r = ft_atoi(line);
	while (line[i] != ',')
		i++;
	c_g = ft_atoi(line + i + 1);
	i++;
	while (line[i] != ',')
		i++;
	c_b = ft_atoi(line + i + 1);
	color_check(c_r, c_g, c_b);
	p->s->c_col = c_r;
	p->s->c_col = (p->s->c_col << 8) + c_g;
	p->s->c_col = (p->s->c_col << 8) + c_b;
}
