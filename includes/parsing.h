/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:19 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:52:52 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

int interpret_lightsource(char **str, t_data *data);
int interpret_camera(char **str, t_data *data);
int interpret_ambient_light(char **str, t_data *data);
int interpret_plane(char **str, t_data *data);
int interpret_sphere(char **str, t_data *data);
int interpret_cylindner(char **str, t_data *data);
int interpret_triangle(char **str, t_data *data);
int	parsing(t_data *data);

#endif
