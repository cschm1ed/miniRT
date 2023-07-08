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
int 		trace_ray(t_data *data, t_line line, int depth);
void		draw_image(t_mlx_data *ui, t_data *data);
int			closest_intersection(t_scene *scene, t_intersect *intersect);
//shading
t_vector get_intensity(t_scene *scene, t_intersect inter);
t_vector ambient_illumination(t_list *obj, t_scene *scene);
int is_obscured(t_scene *scene, double distance, t_vector intersect);
int calculate_color(t_data *data, t_intersect intersect);

//slice_utils
int			double_checker(char *str);
long double	ft_atod(const char *str);
int			count_elements(char **str);
int			trgb(int t, int r, int g, int b);
int			get_center(char *str, t_vector *center );
int			get_single_double(char *str, double *variable);
int			get_single_integer(char *str, int *variable);

int			check_integerString(char *str);
int			check_centerString(char *str);
int			check_doubleString(char *str);
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
int			no_event(t_data *data);

// math stuff
int 		intersection_line_sphere(void *objecet, t_line line, t_vector *result);
int			intersection_line_plane(void *object, t_line line, t_vector *result);
int			line_cylinder(void *cylinder, t_line line, t_vector *result);
int			intersection_line_triangle(t_triangle triangle, t_line line, t_vector *result);

t_vector	normal_sphere(void *sphere, t_vector point);
t_vector	normal_plane(void *plane, t_vector point);
t_vector normal_cylinder(void *cylinder, t_vector point);

t_vector	_rotate(t_vector vec, double xy_degree, double xz_degree);
double 		rad_to_deg(double rad);
double 		angle_between_vectors(t_vector v1, t_vector v2);
t_vector	_multiply(t_vector vector, double scalar);
double		_len(t_vector vec);
t_vector	_add(t_vector v1, t_vector v2);
double		_dot(t_vector v1, t_vector v2);
t_vector 	_cross(t_vector v1, t_vector v2);
t_vector	_subtract(t_vector v1, t_vector v2);
t_vector	angles_to_vector(double ayx, double axz);
t_vector		_multiply(t_vector vec, double factor);
double		vector_scalar(t_vector vector1, t_vector vector2);
t_vector		_divide(t_vector vector, double factor);
t_vector	sqrtf_vector(t_vector vector);
t_vector	_pow(t_vector vector);
t_vector	_multiply_element_wise(t_vector v1, t_vector v2);
t_vector	_reflect(t_vector incoming, t_vector normal);

int			c_multiply(int colour, t_vector intensity);
t_vector	colour_to_vector(int colour);
int 		vector_to_colour(t_vector colour);
int 		c_add(int c1, int c2);



int			free_stuff(t_data *data);
void		free_stringArray(char **str);

void		print_vector(t_vector vector);

t_vector	get_direction(t_data *data, t_plane vp, double x, double y);
void		create_vision_plane(t_data *data, t_plane *vp);

t_vector	get_colour_sphere(t_list *obj);
t_vector	get_colour_plane(t_list *obj);
t_vector	get_colour_cylinder(t_list *obj);
t_vector	get_colour_triangle(t_list *obj);
t_vector	get_colour_lightsource(t_list *obj);


#endif
