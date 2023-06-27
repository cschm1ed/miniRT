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
}	t_data;

typedef struct s_vector
{
	float		x;
	float		y;
	float		z;
}	t_vector;

typedef struct s_pos
{
	float		x;
	float		y;
	float		z;
} t_pos;

typedef struct s_parsing
{
	char		*name;
	int			(*f)(char **str, t_data *data);
} t_parsing;

typedef struct s_sphere
{
	t_vector	center;
	float		diameter;
	int			colour;
} t_sphere;

typedef struct s_plane
{
	t_vector	base;
	t_vector	v1;
	t_vector 	v2;
	int 		colour;
} t_plane;

typedef struct s_line
{
    t_vector	base;
    t_vector	direction;
}   t_line;

typedef struct s_cylinder
{
	t_vector	center;
	t_vector	vector;
	float		diameter;
	float		height;
	int			colour;
} t_cylinder;

typedef struct s_triangle
{
	t_vector A;
	t_vector B;
	t_vector C;
	int colour;
} t_triangle;

typedef struct s_camera
{
	t_vector 	center;
	t_vector 	vector;
	int 		degrees;
} t_camera;

typedef struct s_ambient_light
{
	float 		light_ratio;
	int 		colour;
} t_ambient_light;

typedef struct s_light_source
{
	t_vector	center;
	float		light_ratio;
	int 		colour;
} t_light_source;

typedef struct s_scene
{
	t_list		*camera;
	t_list		*light_lst;
	t_list 		*ambient_light;
	t_list 		*sphere_lst;
	t_list 		*plane_lst;
	t_list 		*cylinder_lst;
	t_list		*triangle_lst;
	t_list		*cylinder;

} t_scene;

#endif
