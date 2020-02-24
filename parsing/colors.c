/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/24 14:27:08 by tpons             #+#    #+#             */
/*   Updated: 2020/02/24 14:58:57 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

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
	while (line[i] != ',')
		i++;
	f_b = ft_atoi(line + i + 1);
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
	while (line[i] != ',')
		i++;
	c_b = ft_atoi(line + i + 1);
	p->s->c_col = c_r;
	p->s->c_col = (p->s->c_col << 8) + c_g;
	p->s->c_col = (p->s->c_col << 8) + c_b;
}
