/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:38 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/08 09:53:18 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

//trace stuff
int			trace_ray(t_data *data, t_line line, int depth);
int			draw_image(t_data *data);
int			closest_intersection(t_scene *scene, t_intersect *intersect);
t_vector	get_direction(t_data *data, t_plane vp, double x, double y);
int			average_pixel(t_data *data, t_line cam, t_plane vp, t_touple pos);

//shading
int			is_obscured(t_scene *scene, t_intersect intersect);
int			calculate_color(t_data *data, t_intersect intersect, int depth);
t_vector	get_reflection(t_data *data, t_intersect inter, int depth);

//slice_utils
int			double_checker(char *str);
double		ft_atod(const char *str);
int			count_elements(char **str);
int			get_colour(int t, int r, int g, int b);
int			get_center(char *str, t_vector *center );
int			get_single_double(char *str, double *variable);

int			check_integerString(char *str);
int			check_centerstring(char *str);
int			get_trgb(char *str, int *colour);
int			check_rgbstring(char *str);
// inits
t_scene		*init_scene(t_scene *scene);
int			init_parsing(t_data *data);
int			init_data(int argc, char **argv, t_data *data);
int			check_map(t_data *data);

// mlx stuff
int			handle_keypress(int keysym, t_data *data);
void		loop_mlx(t_data *data);
void		put_pixel(int x, int y, int color, t_data *data);
int			no_event(t_data *data);

// math stuff
double		rad_to_deg(double rad);
t_vector	_multiply(t_vector vector, double scalar);
double		_len(t_vector vec);
t_vector	_add(t_vector v1, t_vector v2);
double		_dot(t_vector v1, t_vector v2);
t_vector	_cross(t_vector v1, t_vector v2);
t_vector	_subtract(t_vector v1, t_vector v2);
t_vector	_multiply(t_vector vec, double factor);
t_vector	_divide(t_vector vector, double factor);
t_vector	_multiply_element_wise(t_vector v1, t_vector v2);
t_vector	_reflect(t_vector incoming, t_vector normal);

t_vector	colour_to_vector(int colour);
int			vector_to_colour(t_vector colour);

int			set_dsr(t_list *obj, char **str, int i);
int			check_light_source(t_light_source *new_light, char **str);
int			check_camera(t_camera *new_camera, char **str);
int			check_ambient_light(t_ambient_light *new_ambient_light, char **str);
int			check_plane(t_plane *new_plane, t_list *new_element, char **str);
int			check_sphere(t_sphere *new_sphere, t_list *new_element, char **str);
int			check_cylinder(t_cylindner *new_cylindner, \
					t_list *new_element, char **str);
int			check_triangle(t_triangle *new_triangle, \
					t_list *new_element, char **str);

int			free_stuff(t_data *data);
void		free_stringarray(char **str);

t_vector	get_colour_sphere(t_list *obj);
t_vector	get_colour_plane(t_list *obj);
t_vector	get_colour_cylindner(t_list *obj);
t_vector	get_colour_triangle(t_list *obj);
t_vector	get_colour_lightsource(t_list *obj);

int			average_colours(int c1, int c2, int c3, int c4);

#endif
