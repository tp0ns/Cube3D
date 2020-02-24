/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:39:10 by tpons             #+#    #+#             */
/*   Updated: 2020/02/24 14:56:48 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	int			fd;
	t_param		p;
	int			i = 0; //for printf

	fd = 0;
	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		get_param(fd, &p);
	}
	// if (ac == 3) Pour Screenshot
	printf("RES :\n x %d y %d\n", p.s->x, p.s->y);
	printf("TEXTURE :\n N      %s\n S      %s\n W      %s\n E      %s\n Sprite %s\n", p.s->north, p.s->south, p.s->west, p.s->east, p.s->sprite);
	printf("COLORS :\n Ceiling %d\n Floor %d\n", p.s->c_col, p.s->f_col);
	while (p.s->map[i])
		printf("%s\n", p.s->map[i++]);
	close(fd);
	return (0);
}
