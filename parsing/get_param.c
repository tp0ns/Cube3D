/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:35:25 by tpons             #+#    #+#             */
/*   Updated: 2020/03/11 11:32:10 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_param(t_param *p)
{
	int	j;

	j = 0;
	if (!(p->s = malloc(sizeof(t_scene))))
		leave("Something went wrong with scene initialization");
	ft_bzero(p->s, sizeof(t_scene));
	if (!(p->d = malloc(sizeof(t_dda))))
		leave("Something went wrong with scene initialization - 2");
	ft_bzero(p->d, sizeof(t_dda));
	if (!(p->i = malloc(sizeof(t_image *) * 7)))
		leave("Something went wrong with scene initialization - 3");
	ft_bzero(p->i, sizeof(t_image *) * 7);
	while (j <= 5)
	{
		if (!(p->i[j] = malloc(sizeof(t_image))))
			leave("Something went wrong with scene initialization - 3");
		ft_bzero(p->i[j], sizeof(t_image));
		j++;
	}
}

void	sort_param(char *line, t_param *p)
{
	if (line[0] == '\0')
		return ;
	else if (line[0] == 'R')
		push_res((line + 1), p);
	else if (line[0] == 'N' && line[1] == 'O')
		push_text((line + 2), p, 1);
	else if (line[0] == 'S' && line[1] == 'O')
		push_text((line + 2), p, 2);
	else if (line[0] == 'W' && line[1] == 'E')
		push_text((line + 2), p, 3);
	else if (line[0] == 'E' && line[1] == 'A')
		push_text((line + 2), p, 4);
	else if (line[0] == 'S' && line[1] != 'O')
		push_text((line + 1), p, 5);
	else if (line[0] == 'F')
		push_f_col((line + 1), p);
	else if (line[0] == 'C')
		push_c_col((line + 1), p);
	else
		leave("Unrecognized element in scene file");
}

void	get_param(int fd, t_param *p)
{
	char	*line;
	int		rtn;
	int		i;

	rtn = 1;
	while (rtn > 0)
	{
		i = 0;
		if ((rtn = get_next_line(fd, &line)) == -1)
			leave("Scene file can't be read");
		while (line[i] == ' ')
			i++;
		if (line[i] == '1' || line[i] == '0' || line[i] == '2')
			break ;
		sort_param(&line[i], p);
	}
	if (line[i] == '1' || line[i] == '0' || line[i] == '2')
	{
		line = clean_map_line(line);
		p->s->linear_map = ft_strjoin_gnl(p->s->linear_map, line);
		push_map(fd, p);
	}
	check_param(p);
}
