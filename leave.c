/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   leave.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 13:52:59 by tpons             #+#    #+#             */
/*   Updated: 2020/02/21 15:26:00 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	leave(char *str)
{
	ft_putstr("ERROR\n");
	ft_putstr(str);
	exit(EXIT_FAILURE);
}

int		close_win(void)
{
	exit(EXIT_SUCCESS);
	return (0);
}
