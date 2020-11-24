/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:39:10 by tpons             #+#    #+#             */
/*   Updated: 2020/11/24 17:06:43 by tpons            ###   ########.fr       */
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

int	flag_name(char *str)
{
	int len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'e' && str[len - 1] == 'v' && str[len - 2] == 'a'
	&& str[len - 3] == 's' && str[len - 4] == '-' && str[len - 5] == '-')
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_param		p;

	init_param(&p);
	p.s->fd = 0;
	if (ac == 3 && file_name(av[1]) && flag_name(av[2]))
		screenshot(&p, av[1]);
	else if (ac == 2 && file_name(av[1]))
	{
		p.s->fd = open(av[1], O_RDONLY);
		p.d->mlx_ptr = mlx_init();
		get_param(p.s->fd, &p);
		game(&p);
	}
	else
		leave(&p, "Wrong scene file name or flag name");
	return (0);
}
