

#ifndef RENDERING_AND_SHADING_H
# define RENDERING_AND_SHADING_H

int 		trace_ray(t_data *data, t_line line, int depth);
int 		draw_image(t_data *data);
int			closest_intersection(t_scene *scene, t_intersect *intersect);

double	get_intensity(t_light_source *light_sources, t_vector intersection);
int is_obscured(t_scene *scene, t_vector intersect);
int calculate_color(t_data *data, t_intersect intersect, int depth);
t_vector get_reflection(t_data *data, t_intersect inter, int depth);

t_vector	colour_to_vector(int colour);
int 		vector_to_colour(t_vector colour);

t_vector	get_direction(t_data *data, t_plane vp, double x, double y);
void		create_vision_plane(t_data *data, t_plane *vp);


#endif
