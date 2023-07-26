/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:48:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 21:02:51 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include "minirt.h"

typedef struct s_data t_data;
typedef struct s_parsing t_parsing;
typedef struct s_mlx_data t_mlx_data;
typedef struct s_scene t_scene;
typedef struct s_list t_list;

typedef struct s_mlx_data
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*img_addr;
	char			*titel;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
	int				width;
	int				height;
}	t_mlx_data;

typedef struct s_data
{
	char			*scene_filename;
	t_parsing		*parsing;
	t_mlx_data		mlx_data;
	struct s_scene	*scene;
    t_list          *tmp;
	int 			redraw;
}	t_data;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}	t_vector;

typedef struct s_pos
{
	double		x;
	double		y;
	double		z;
} t_pos;

typedef struct s_parsing
{
	char		*name;
	int			(*f)(char **str, t_data *data);
} t_parsing;

typedef struct s_sphere
{
	int			colour;
	t_vector	center;
	double		diameter;
} t_sphere;

typedef struct s_plane
{
	int 		colour;
	t_vector	base;
	t_vector	v1;
    t_vector    v2;
} t_plane;

typedef struct s_line
{
    t_vector	base;
    t_vector	direction;
}   t_line;

typedef struct s_cylindner
{
	int			colour;
	t_vector	center;
	t_vector	axis_direction;
	double		diameter;
	double		height;
} t_cylindner;

typedef struct s_triangle
{
	int colour;
	t_vector A;
	t_vector B;
	t_vector C;
} t_triangle;

typedef struct s_cone
{
	int colour;
	t_vector apex;
	t_vector axis_direction;
	double height;
	double	opening_angle;
} t_cone;

typedef struct s_ptr_touple {
	double *d1;
	double *d2;
} t_ptr_touple;

typedef struct	s_touple {
	float	x;
	float	y;
} t_touple;

typedef struct s_c {
	t_vector	normal;
	double		a;
	double		b;
	double		c;
	double		dot1;
	double 		dot2;
	t_vector	w;
	t_vector	v;
} t_c;

typedef struct s_camera
{
	t_vector 	center;
	t_vector 	vector;
	double		degrees;
} t_camera;

typedef struct s_ambient_light
{
	int 		colour;
	double 		light_ratio;
} t_ambient_light;

typedef struct s_light_source
{
	int 		colour;
	t_vector	center;
	double		light_ratio;
} t_light_source;

typedef struct s_scene
{
	t_camera		*camera;
	t_ambient_light	*ambient_light;
	t_list			*light_lst;
	t_list 			*sphere_lst;
	t_list 			*plane_lst;
	t_list 			*cylindner_lst;
	t_list			*triangle_lst;
	t_list			*cone_lst;
	t_list			*all_objs;
} t_scene;

typedef struct s_intersect
{
    t_list      *obj;
    t_vector    point;
    t_line      ray;
    t_vector    normal;
}   t_intersect;

#endif
