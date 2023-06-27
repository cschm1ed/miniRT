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

//trace stuff
int 		trace_ray(t_data *data, t_line line, int depth);

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
int			handle_keypress(int keysym, t_data *data);
void		loop_mlx(t_data *data);
void		put_pixel(int x, int y, int color, t_data *data);

// math stuff
int 		intersection_line_sphere(void *objecet, t_line line, t_vector *result);
int			intersection_line_plane(void *object, t_line line, t_vector *result);
int 		intersection_line_cylinder(t_cylinder, t_line line);
int			intersection_line_triangle(t_triangle triangle, t_line line, t_vector *result);

t_vector	normal_sphere(void *sphere, t_vector point);
t_vector	normal_plane(void *plane, t_vector point);

float 		rad_to_deg(float rad);
float 		angle_between_vectors(t_vector v1, t_vector v2);
t_vector	vector_x_scalar(t_vector vector, float scalar);
float		vector_len(t_vector vec);
t_vector	vector_add(t_vector v1, t_vector v2);
float		dot(t_vector v1, t_vector v2);
t_vector 	cross(t_vector v1, t_vector v2);
t_vector	substract(t_vector v1, t_vector v2);
t_vector	angles_to_vector(float ayx, float axz);
void		vector_multiply(t_vector vec, float factor);
float		vector_scalar(t_vector vector1, t_vector vector2);
void		vector_divide(t_vector vector, float factor);

int colour_x_intensity(int colour, t_vector intensity);


int			free_stuff(t_data *data);
void		free_stringArray(char **str);

void		print_vector(t_vector vector);

#endif
