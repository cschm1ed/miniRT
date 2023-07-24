

#include "../../includes/minirt.h"

int	free_stuff(t_data *data)
{
	mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	free(data->mlx_data.mlx);
	ft_lstclear(&data->scene->all_objs, free);
	exit(0);
	return (SUCCESS);
}
