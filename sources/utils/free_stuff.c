

#include "../../includes/minirt.h"

int	free_stuff(t_data *data)
{
	mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	free(data->mlx_data.mlx);
	ft_lstclear(&data->scene->all_objs, free);
	if (data->scene->light_lst)
		ft_lstclear(&data->scene->light_lst, free);
	if (data->scene->ambient_light)
		free(data->scene->ambient_light);
	if (data->scene->camera)
		free(data->scene->camera);
	if (data->scene)
		free(data->scene);
//	if (data->parsing)
//		free(data->parsing);
	exit(0);
	return (SUCCESS);
}
