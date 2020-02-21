/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:16:10 by tpons             #+#    #+#             */
/*   Updated: 2020/02/21 15:25:59 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef FOV
#  define FOV 66
# endif
# include <fcntl.h>
# include <math.h>
# include <string.h>
# include <stdlib.h>
# include <errno.h>
# include <mlx.h>
# include "Libft/libft.h"
# include <stdio.h> // A retirer

typedef	struct	s_scene
{
	char		**param;
}				t_scene;

typedef	struct	s_param
{
	t_scene		*s;
}				t_param;

int				close_win(void);
void			leave(char *str);

void			get_param(int fd, t_param *p);
void			init_param(t_param	*p);
char			*set_line(char *str);

#endif