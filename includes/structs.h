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
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	char		*titel;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			width;
	int			height;
}	t_mlx_data;

typedef struct s_data
{
	char			*scene_filename;
	t_parsing		*parsing;
	t_mlx_data		mlx_data;
	struct s_scene	*scene;
}	t_data;

typedef struct s_direction
{
	float	x;
	float	y;
	float	z;
}	t_direction;

typedef struct s_pos
{
	float	x;
	float	y;
	float	z;
} t_pos;

typedef struct s_vector
{
	float	x;
	float	y;
	float	z;
} t_vector;

typedef struct s_parsing
{
	char	*name;
	int		(*f)(char **str, t_data *data);
} t_parsing;

typedef struct s_sphere
{
	t_pos	*center;
	int		diameter;
	int		colour;
} t_sphere;

typedef struct s_plane
{
	t_pos		*point;
	t_vector	*vector;
	int colour;
} t_plane;

typedef struct s_cylinder
{
	t_pos *center;
	t_vector *vector;
	int diameter;
	int height;
	int colour;
} t_cylinder;

typedef struct s_camera
{
	t_pos *center;
	t_vector *s_vector;
	int degrees;
} t_camera;

typedef struct s_ambient_light
{
	float light_ratio;
	int colour;
} t_ambient_light;

typedef struct s_light_source
{
	t_pos *center;
	float light_ratio;
	int colour;
} t_light_source;

typedef struct s_scene
{
	t_list *camera;
	t_list *light_lst;
	t_list *ambient_light;
	t_list *sphere_lst;
	t_list *plane_lst;
	t_list *cylinder_lst;
} t_scene;

#endif
