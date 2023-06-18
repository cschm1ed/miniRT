/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:48:32 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:51:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_mlx t_mlx;
typedef struct s_data t_data;
typedef struct s_parsing t_parsing;

typedef struct s_data
{
	char		*scene_filename;
	t_parsing	*parsing;
}	t_data;

typedef struct s_mlx
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
}	t_mlx;

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

typedef struct s_parsing
{
	char	*name;
	int		(*f)(char **str);
} t_parsing;

#endif
