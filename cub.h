/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tpons <tpons@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/21 11:16:10 by tpons             #+#    #+#             */
/*   Updated: 2020/03/10 15:05:02 by tpons            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# ifndef FOV
#  define FOV 0.66
# endif
# ifndef M
#  define M 0.1
# endif
# ifndef RS
#  define RS 0.1
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
	char		*linear_map;
	char		**brut_map;
	char		**map;
	double		pos_x;
	double		pos_y;
	int			max_x;
	int			max_y;
	int			x;
	int			y;
	char		*north;
	char		*south;
	char		*east;
	char		*west;
	char		*sprite;
	int			c_col;
	int			f_col;
}				t_scene;

typedef	struct	s_dda
{
	void		*mlx_ptr;
	void		*win_ptr;
	double		dirx;
	double		diry;
	double		planx;
	double		plany;
	double		camx;
	int			screenx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		walldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			textx;
	int			texty;
	double		step;
	double		textpos;
}				t_dda;

typedef struct	s_image
{
	void		*image_ptr;
	char		*image_data;
	int			width;
	int			height;
	int			bpp;
	int			size_line;
}				t_image;

typedef	struct	s_param
{
	t_scene		*s;
	t_dda		*d;
	t_image		**i;
}				t_param;

int				close_win(void);
void			leave(char *str);

void			get_param(int fd, t_param *p);
void			init_param(t_param	*p);
void			sort_param(char *line, t_param *p);
char			*skip_spaces(char *str);
void			push_map(int fd, t_param *p);
char			*clean_map_line(char *line);
int				line_length(char *line);
int				is_map_char(char c);
char			*cut_spaces(char *str);
void			path_spaces(t_param *p, int flag);
void			init_text(t_param *p, int flag, char *path);
void			push_text(char *line, t_param *p, int flag);
void			push_res(char *line, t_param *p);
void			push_c_col(char *line, t_param *p);
void			push_f_col(char *line, t_param *p);
void			color_check(int r, int g, int b);
void			check_param(t_param *p);
void			init_map(t_param *p);
void			map_size(t_param *p);
void			match_maps(t_param *p);
void			check_map(t_param *p, int x, int y);

void			game(t_param *p);

int				key_management(int key, t_param *p);

void			dda(t_param *p);
void			set_dda(t_param *p);
void			set_player(t_param *p, int x, int y);
void			set_sidedist(t_param *p);

void			draw(t_param *p);
void			set_lineheight(t_param *p);
int				draw_ceiling(t_param *p, int y);
int				draw_textures(t_param *p, int y);
void			set_texture(t_param *p);
void			which_wall(t_param *p);
void			draw_floor(t_param *p, int y);

void			rotate(t_param *p, int key);
void			right(t_param *p);
void			left(t_param *p);
void			backward(t_param *p);
void			forward(t_param *p);

#endif