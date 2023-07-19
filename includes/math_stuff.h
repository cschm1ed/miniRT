
#ifndef MATH_STUFF_H
#define MATH_STUFF_H

double 		rad_to_deg(double rad);
t_vector	_multiply(t_vector vector, double scalar);
double		_len(t_vector vec);
t_vector	_add(t_vector v1, t_vector v2);
double		_dot(t_vector v1, t_vector v2);
t_vector 	_cross(t_vector v1, t_vector v2);
t_vector	_subtract(t_vector v1, t_vector v2);
t_vector	_multiply(t_vector vec, double factor);
t_vector	_divide(t_vector vector, double factor);
int			_parallel(t_vector v1, t_vector v2);
int			_opposite(t_vector v1, t_vector v2);
t_vector	_multiply_element_wise(t_vector v1, t_vector v2);
t_vector	_reflect(t_vector incoming, t_vector normal);
t_vector _norm(t_vector v);

// math stuff
int 		intersection_line_sphere(void *object, t_line line, t_intersect *result);
int			intersection_line_plane(void *object, t_line line, t_intersect *inter);
int			line_cylindner(void *object, t_line line, t_intersect *inter);
int			intersection_line_triangle(void *object, t_line line, t_intersect *result);
int			line_cone(void *object, t_line line, t_intersect *inter);
//int			bottom_cap_intersection(t_cylindner cylindner, t_vector ray_direction, t_vector point);
//int			top_cap_intersection(t_cylindner cylindner, t_vector ray_direction, t_vector point);
t_vector	normal_tube_cylinder(t_vector point, t_cylindner cylindner);

#endif
