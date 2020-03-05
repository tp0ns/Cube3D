/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:59 by tpons             #+#    #+#             */
/*   Updated: 2020/03/05 16:19:03 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	leave(char *str)
{
	//free image struct & brut_map & map to avoid leaks
	ft_putstr("ERROR\n");
	ft_putstr(str);
	ft_putstr("\n");
	exit(EXIT_FAILURE);
}

int		close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
