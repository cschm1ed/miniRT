/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 16:46:43 by estruckm          #+#    #+#             */
/*   Updated: 2023/07/09 14:49:14 by cschmied         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include "X11/keysym.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>
# include "../libft/libft.h"
# include "structs.h"
# include "utils.h"
# include "parsing.h"

# define ANTI_ALIASING 1
# define DISTANCE_FACTOR 5
# define DIFFUSE 0.5
# define SPECULAR 0.3
# define MAX_DEPTH 2

# define WIDTH 1500
# define HEIGHT 1500
# define FOV_HEIGHT 90
# define SUCCESS 1
# define FAILURE -1
# define TRUE 1
# define FALSE 0
# define EPSILON 1e-9
# define DEG_TO_RAD M_PI / 180.0
# define MOVE_RATE 0.5
# define COLOR_BLUE 0xFF0000

# define KEYBOARD_A                     0x00
# define KEYBOARD_S                     0x01
# define KEYBOARD_D                     0x02
# define KEYBOARD_W                     0x0D

# define KEYBOARD_X                     0x07
# define KEYBOARD_Y                     0x10

# define KEYBOARD_1                     0x12
# define KEYBOARD_2                     0x13

#endif
