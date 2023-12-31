/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:46:43 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/28 19:23:40 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/includes/libft.h"
# include "structs.h"
# include "utils.h"
# include "parsing.h"
# include "intersections.h"

# define DISTANCE_FACTOR 0.1
# define REFLECTIVENES 0.05
# define DIFFUSE 0.6
# define SPECULAR 0.3

# define SPECULAR_N 80

# define ANTI_ALIASING 1
# define MAX_DEPTH 7

# define WIDTH 1000
# define HEIGHT WIDTH

# define SUCCESS 1
# define FAILURE -1
# define TRUE 1
# define FALSE 0
# define EPSILON 1e-7
# define KEYBOARD_ESCAPE	0x35

#endif
