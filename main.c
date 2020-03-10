/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:39:10 by tpons             #+#    #+#             */
/*   Updated: 2020/03/10 16:13:17 by tpons            ###   ########.fr       */
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
	int			fd;
	t_param		p;

	fd = 0;
	if (ac == 2 && file_name(av[1]))
	{
		fd = open(av[1], O_RDONLY);
		init_param(&p);
		p.d->mlx_ptr = mlx_init();
		get_param(fd, &p);
		// game(&p);
	}
	// else if (ac == 3 && file_name(av[1])) Pour Screenshot;
	// else
	// 	leave("You must use .cub extension for your scene file");
	close(fd);
	return (0);
}
//ADD I FOR PRINT
	// while (p.s->brut_map[i])
	// 	printf("%s\n", p.s->brut_map[i++]);
	// printf("\nxxxxxxxxxxxxxxxxxx\n\n");
	// i = 0;
	// while (p.s->map[i])
	// 	printf("%s\n", p.s->map[i++]);
	// printf("\nxxxxxxxxxxxxxxxxxx\n\n");