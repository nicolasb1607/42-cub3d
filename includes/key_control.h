/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:49 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/29 13:28:12 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_CONTROL_H
# define KEY_CONTROL_H

# include "cub3d.h"

int	key_hook(int keycode, t_data *data);
int	key_release(int key, t_data *data);

#endif