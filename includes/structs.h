/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cschmied <cschmied@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:48:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/29 18:06:57 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

# include "minirt.h"

typedef struct s_data		t_data;
typedef struct s_parsing	t_parsing;
typedef struct s_mlx_data	t_mlx_data;
typedef struct s_scene		t_scene;
typedef struct s_list		t_list;

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

typedef struct s_parsing
{
	char		*name;
	int			(*f)(char **str, t_data *data);
}	t_parsing;

typedef struct s_proj_len
{
	double		*pl1;
	double		*pl2;
}	t_proj_len;

typedef struct s_data
{
	char			*scene_filename;
	t_parsing		parsing[7];
	t_mlx_data		mlx_data;
	struct s_scene	*scene;
}	t_data;

typedef struct s_vector
{
	double		x;
	double		y;
	double		z;
}	t_vector;

typedef struct s_sphere
{
	int			colour;
	t_vector	center;
	double		diameter;
}	t_sphere;

typedef struct s_var_dump
{
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	t;
	double	discriminant;
}	t_var_dump;

typedef struct s_plane
{
	int			colour;
	t_vector	base;
	t_vector	v1;
	t_vector	v2;
}	t_plane;

typedef struct s_line
{
	t_vector	base;
	t_vector	dir;
}	t_line;

typedef struct s_cylindner
{
	int			colour;
	t_vector	center;
	t_vector	axis_dir;
	double		diameter;
	double		height;
}	t_cylindner;

typedef struct s_triangle
{
	int			colour;
	t_vector	a;
	t_vector	b;
	t_vector	c;
}	t_triangle;

typedef struct s_touple {
	float	x;
	float	y;
}	t_touple;

typedef struct s_c
{
	t_vector	normal;
	double		a;
	double		b;
	double		c;
	double		dot1;
	double		dot2;
	t_vector	w;
	t_vector	v;
}	t_c;

typedef struct s_camera
{
	t_vector	center;
	t_vector	vector;
	double		degrees;
}	t_camera;

typedef struct s_ambient_light
{
	int			colour;
	double		light_ratio;
}	t_ambient_light;

typedef struct s_light_source
{
	int			colour;
	t_vector	center;
	double		light_ratio;
}	t_light_source;

typedef struct s_scene
{
	t_camera		*camera;
	t_ambient_light	*ambient_light;
	t_list			*light_lst;
	t_list			*all_objs;
}	t_scene;

typedef struct s_intersect
{
	t_list		*obj;
	t_vector	point;
	t_line		ray;
	t_vector	normal;
}	t_intersect;

#endif
