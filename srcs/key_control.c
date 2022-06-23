/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/23 16:15:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/23 16:17:00 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key_control.h"

int	key_hook(int keycode, t_data *data)
{
	if (keycode == XK_Escape)
		ft_exit(data);
	return (0);
}

