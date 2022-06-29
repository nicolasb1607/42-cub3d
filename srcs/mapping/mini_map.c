/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nburat-d <nburat-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 14:02:37 by rpottier          #+#    #+#             */
/*   Updated: 2022/06/29 14:07:05 by nburat-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

void	update_player(t_data *data)
{
	printf("update_player\n");
	
	int move_step;

	//SET_UP direction des mouvements

	move_step = (data->player->walk_direction * data->player->walk_speed);
	data->player->rotation_angle += (data->player->turn_direction * data->player->turn_speed);
	
	//MAJ de la position du joueur

	data->player->x_pos += (cos(data->player->rotation_angle + data->player->side_angle) * move_step);
	data->player->y_pos += (sin(data->player->rotation_angle + data->player->side_angle) * move_step);

	//Remise à zéro des variables de mouvements
	data->player->turn_direction = 0;
	data->player->walk_direction = 0;
	data->player->side_angle = 0;
}

void	draw_player(t_data *data)
{
	t_2d a;
	t_2d b;

	// set direction line
	a.x = data->player->x_pos;
	a.y = data->player->y_pos;
	b.x = ceil(data->player->x_pos + cos(data->player->rotation_angle) * 20); // cos(angle) = (adjacent/hypotenuse) la dernière valeur étant la longeur de la ligne
	b.y = ceil(data->player->y_pos + sin(data->player->rotation_angle) * 20); // sin(angle) = (opposee/hypotenuse)

	// set_color player
	data->ceiling_color->red = 0;
	data->ceiling_color->green = 255;
	data->ceiling_color->blue = 0;

	//draw direction line
	printf("a.x = %d; a.y = %d\n", a.x, a.y);
	printf("b.x = %d; b.y = %d\n", b.x, a.y);
	bresenham(a, b , data);

	// draw_player
	my_mlx_pixel_put(a.x, a.y, data->gui->img_data, encode_rgb(255,0,0));
}

void	draw_minimap(t_data *data)
{
	int	i;
	int	j;
	t_rectangle rec;
	i = 0;
	while (i < data->map->height)
	{
		j = 0;
		while (j < data->map->width)
		{
			rec.x_top_left_corner = j * TILE_SIZE * MINIMAP_SCALE;
			rec.y_top_left_corner = i * TILE_SIZE * MINIMAP_SCALE;
			rec.width_size = TILE_SIZE * MINIMAP_SCALE;
			rec.height_size = TILE_SIZE * MINIMAP_SCALE;
			set_tile_color(data, i, j);
			draw_rec(&rec, data, TILE_SIZE);
			j++;
		}
		i++;
	}
}

void	set_tile_color(t_data *data, int i, int j)
{
	if (data->map->content[i][j] == '1')
	{
		data->ceiling_color->red = 255;
		data->ceiling_color->green = 255;
		data->ceiling_color->blue = 255;
	}
	else
	{
		data->ceiling_color->red = 0;
		data->ceiling_color->green = 0;
		data->ceiling_color->blue = 0;
	}	
}
