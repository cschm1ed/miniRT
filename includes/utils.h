/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:38 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:22:12 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//slice_utils
int			float_checker(char *str);
long double	ft_atod(const char *str);
int			count_elements(char **str);
int			trgb(int t, int r, int g, int b);
int			get_center(char *str, t_vector *center);
int			get_single_float(char *str, float *variable);
int			get_single_integer(char *str, int *variable);

int			check_integerString(char *str);
int			check_centerString(char *str);
int			check_floatString(char *str);
int			get_trgb(char *str, int *colour);
int			check_rgbString(char *str);
// inits
t_scene		*init_scene(t_scene *scene);
int			init_parsing(t_data *data);
int			init_data(int argc, char **argv, t_data *data);

// mlx stuff
void		loop_mlx(t_data *data);
void		put_pixel(int x, int y, int color, t_data *data);

// math stuff
int 		intersection_line_sphere(t_sphere sphere, t_line line, t_vector *result);
int 		interesction_line_plane(t_plane plane, t_line line, t_vector *result);
int 		intersection_line_cylinder(t_cylinder, t_line line);

t_vector	vector_x_scalar(t_vector vector, float scalar);
float		vector_len(t_vector vec);
t_vector	vector_add(t_vector v1, t_vector v2);
float		dot(t_vector v1, t_vector v2);
t_vector 	cross(t_vector v1, t_vector v2);
t_vector	vector_substract(t_vector v1, t_vector v2);
t_vector	angles_to_vector(float ayx, float axz);


int			free_stuff(t_data *data);
void		free_stringArray(char **str);

#endif
