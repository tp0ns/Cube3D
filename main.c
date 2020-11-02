/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:39:10 by tpons             #+#    #+#             */
/*   Updated: 2020/11/02 14:37:00 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	file_name(char *str)
{
	int	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'b' && str[len - 1] == 'u' && str[len - 2] == 'c'
	&& str[len - 3] == '.')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_param		p;
	// int	i = 0;
	init_param(&p);
	p.s->fd = 0;
	if (ac == 2 && file_name(av[1]))
	{
		p.s->fd = open(av[1], O_RDONLY);
		p.d->mlx_ptr = mlx_init();
		get_param(p.s->fd, &p);
		game(&p);
	}
	else
		leave(&p, "You must use .cub extension for your scene file");
	return (0);
}
	// while (p.s->brut_map[i])
	// 	printf("%s\n", p.s->brut_map[i++]);
	// printf("\nxxxxxxxxxxxxxxxxxx\n\n");
	// i = 0;
	// while (p.s->map[i])
	// 	printf("%s\n", p.s->map[i++]);
	// printf("\nxxxxxxxxxxxxxxxxxx\n\n");