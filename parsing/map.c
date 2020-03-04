/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:56:53 by tpons             #+#    #+#             */
/*   Updated: 2020/03/04 14:01:11 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

int		is_map_char(char c)
{
	if (c == '0' || c == '1' || c == '2' || c == 'N' || c == 'S'
		|| c == 'W' || c == 'E')
		return (1);
	return (0);
}

int		line_length(char *line)
{
	int	i;
	int	length;

	i = 0;
	length = 0;
	while (line[i])
	{
		if (is_map_char(line[i]))
			length++;
		i++;
	}
	return (length);
}

char	*clean_map_line(char *line)
{
	char	*clean_line;
	int		length;
	int		i;
	int		j;

	i = 0;
	j = 0;
	length = line_length(line) + 1;
	if (!(clean_line = malloc(sizeof(char) * length)))
		leave("Something went wrong with Map allocation.");
	while (line[i])
	{
		if (line[i] != ' ' && !is_map_char(line[i]))
			leave("Unknown character in scene file");
		if (is_map_char(line[i]))
			clean_line[j++] = line[i];
		i++;
	}
	clean_line[j] = '-';
	clean_line[length] = '\0';
	return (clean_line);
}

void	push_map(int fd, t_param *p)
{
	char	*line;
	int		rtn;
	int		mod;
	int		i;

	rtn = 1;
	mod = 0;
	while (rtn > 0)
	{
		i = 0;
		if ((rtn = get_next_line(fd, &line)) == -1)
			leave("Scene file can't be read");
		while (line[i] == ' ') //coucou
			i++;
		if ((line[i] == '1' || line[i] == '0' || line[i] == '2') && mod != 1)
		{
			line = clean_map_line(line);
			p->s->linear_map = ft_strjoin_gnl(p->s->linear_map, line);
		}
		else if (mod == 1 && line[i] != '\0')
			leave("Your scene file is uncorrect");
		else
			mod = 1;
	}
	p->s->brut_map = ft_split(p->s->linear_map, '-');
}
