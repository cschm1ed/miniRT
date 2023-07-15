

#include "../../includes/minirt.h"

int	free_stuff(t_data *data)
{
	printf("free and end stuff\n");
	mlx_destroy_image(data->mlx_data.mlx, data->mlx_data.img);
	mlx_destroy_window(data->mlx_data.mlx, data->mlx_data.win);
	free(data->mlx_data.mlx);
	ft_lstclear(&data->scene->all_objs, free);
	exit(0);
}
