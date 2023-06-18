/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 19:21:38 by estruckm          #+#    #+#             */
/*   Updated: 2023/06/18 19:22:12 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// inits
int		init_parsing(t_data *data);
int		init_data(int argc, char **argv, t_data *data);

// mlx stuff
void	loop_mlx(t_data *data);
void	put_pixel(int x, int y, int color, t_data *data);

int		free_stuff(t_data *data);

#endif
