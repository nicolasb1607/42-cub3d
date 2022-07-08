/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_prgm.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 13:24:43 by nburat-d          #+#    #+#             */
/*   Updated: 2022/07/08 15:30:07 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LAUNCH_PRGM_H
# define LAUNCH_PRGM_H

# include "cub3d.h"

int		launch_prgm(char *file_name);
void	refresh_img(t_data *data);
void	reset_img(t_data *data);
void	render(t_data *data);
int		load_texture(t_data *data);

#endif