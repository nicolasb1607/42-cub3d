/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpottier <rpottier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/29 13:54:08 by rpottier          #+#    #+#             */
/*   Updated: 2022/07/05 11:29:19 by rpottier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mapping.h"

void draw_all_raycasting(t_data *data, t_list *all_rays)
{
	t_ray	*ray;
	t_2d	a;
	t_2d	b;

	while (all_rays)
	{
		ray = (t_ray*)all_rays->content;
		a.x = data->player->x_pos;
		a.y = data->player->y_pos;
		b.x = ray->closest_wall.x;
		b.y = ray->closest_wall.y;
		
		if (ray->facing_left_right == RIGHT)
			b.x = b.x - 1;
		if (ray->facing_up_down == DOWN)
			b.y = b.y - 1;

		// printf("draw_raycating\n");

		// printf("%f %f\n", ray->closest_wall.x, ray->closest_wall.y);
		// printf("%d %d\n", b.x, b.y);
		// set_color player
		data->ceiling_color->red = 255;
		data->ceiling_color->green = 0;
		data->ceiling_color->blue = 0;

		bresenham(a, b, data);
		all_rays = all_rays->next;
	}
}

/*
void	draw_raycasting(t_data *data, t_ray *ray)
{
	t_2d	a;
	t_2d	b;

	a.x = data->player->x_pos;
	a.y = data->player->y_pos;
	b.x = ray->closest_wall.x;
	b.y = ray->closest_wall.y;


	printf("draw_raycating\n");

	printf("%f %f\n", ray->closest_wall.x, ray->closest_wall.y);
	printf("%d %d\n", b.x, b.y);
	// set_color player
	data->ceiling_color->red = 255;
	data->ceiling_color->green = 0;
	data->ceiling_color->blue = 0;

	bresenham(a, b, data);
}
*/
int	is_hiting_a_wall(t_map *map, int x, int y)
{
	if (x < 0 || x > TILE_SIZE * map->width || y < 0 || y > TILE_SIZE * map->height)
		return (TRUE);
	if (map->content[y / TILE_SIZE][x / TILE_SIZE] == '1')
		return (TRUE);
	return (FALSE);
}

void	update_player(t_data *data)
{
//	printf("update_player\n");

	int move_step;
	int new_player_x = 0;
	int new_player_y = 0;

	//SET_UP direction des mouvements

	move_step = (data->player->walk_direction * data->player->walk_speed);
	data->player->rotation_angle = data->player->rotation_angle - (data->player->left_right_rotation * data->player->rotation_speed);
	if (data->player->rotation_angle < 0)
		data->player->rotation_angle += (2 * PI);
	data->player->rotation_angle = fmod(data->player->rotation_angle, 2 * PI);
	//MAJ de la position du joueur
	new_player_x = round(data->player->x_pos + (cos(data->player->rotation_angle + data->player->side_move_angle) * move_step));
	new_player_y = round(data->player->y_pos + (sin(data->player->rotation_angle + data->player->side_move_angle) * move_step));
	
	if (!is_hiting_a_wall(data->map, new_player_x, new_player_y))
	{
		data->player->x_pos = new_player_x;
		data->player->y_pos = new_player_y;
	}
	//Remise à zéro des variables de mouvements
	data->player->left_right_rotation = 0;
	data->player->walk_direction = 0;
	data->player->side_move_angle = 0;
}

void	draw_player(t_data *data)
{
	t_2d a;
	
	// set direction line
	a.x = data->player->x_pos;
	a.y = data->player->y_pos;
	// set_color player
	data->ceiling_color->red = 0;
	data->ceiling_color->green = 255;
	data->ceiling_color->blue = 0;

	//draw direction line
	// printf("-------------------------\n");
	// printf("draw player:\n");
	// printf("a.x = %d; a.y = %d\n", a.x, a.y);
	// printf("b.x = %d; b.y = %d\n", b.x, a.y);
	// printf("-------------------------\n");
	// bresenham(a, b, data);

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