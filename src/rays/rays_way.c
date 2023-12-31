/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays_way.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:43 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:01:44 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3d.h>

int		is_inside_map(float x, float y, t_cub3D *cub3d);
void	find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils, \
	t_cub3D *cub);
void	find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils, \
	t_cub3D *cub);

t_aux_ray	ray_horizontal(t_cub3D *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = FALSE;
	utils->y_intercept = floor(cub->player.y / TILE) * TILE;
	if (utils->is_ray_facing_down == TRUE)
		utils->y_intercept += TILE;
	utils->x_intercept = cub->player.x
		+ (utils->y_intercept - cub->player.y) / tan(angle);
	utils->y_step = TILE;
	if (utils->is_ray_facing_up == TRUE)
		utils->y_step *= -1;
	utils->x_step = TILE / tan(angle);
	if (utils->is_ray_facing_left == TRUE && utils->x_step > 0)
		utils->x_step *= -1;
	if (utils->is_ray_facing_right == TRUE && utils->x_step < 0)
		utils->x_step *= -1;
	find_horz_intersection(&aux, utils, cub);
	return (aux);
}

t_aux_ray	ray_vertical(t_cub3D *cub, t_utils_ray *utils, float angle)
{
	t_aux_ray	aux;

	ft_bzero(&aux, sizeof(t_aux_ray));
	aux.found_wall_hit = FALSE;
	utils->x_intercept = floor(cub->player.x / TILE) * TILE;
	if (utils->is_ray_facing_right == TRUE)
		utils->x_intercept += TILE;
	utils->y_intercept = cub->player.y
		+ (utils->x_intercept - cub->player.x) * tan(angle);
	utils->x_step = TILE;
	if (utils->is_ray_facing_left == TRUE)
		utils->x_step *= -1;
	utils->y_step = TILE * tan(angle);
	if (utils->is_ray_facing_up == TRUE && utils->y_step > 0)
		utils->y_step *= -1;
	if (utils->is_ray_facing_down == TRUE && utils->y_step < 0)
		utils->y_step *= -1;
	find_vert_intersection(&aux, utils, cub);
	return (aux);
}

void	find_vert_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub3D *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(aux->next_touchx, aux->next_touchy, cub) == TRUE)
	{
		aux->yto_check = aux->next_touchy;
		if (utils->is_ray_facing_left == TRUE)
			aux->xto_check = aux->next_touchx + -1;
		else
			aux->xto_check = aux->next_touchx;
		if (map_has_wall_at(cub, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
			[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

void	find_horz_intersection(t_aux_ray *aux, t_utils_ray *utils, t_cub3D *cub)
{
	aux->next_touchx = utils->x_intercept;
	aux->next_touchy = utils->y_intercept;
	while (is_inside_map(aux->next_touchx, aux->next_touchy, cub) == TRUE)
	{
		aux->xto_check = aux->next_touchx;
		if (utils->is_ray_facing_up == TRUE)
			aux->yto_check = aux->next_touchy + -1;
		else
			aux->yto_check = aux->next_touchy;
		if (map_has_wall_at(cub, aux->xto_check, aux->yto_check))
		{
			aux->wall_hit_x = aux->next_touchx;
			aux->wall_hit_y = aux->next_touchy;
			aux->wall_content = cub->map[(int)floor(aux->yto_check / TILE)]
			[(int)floor(aux->xto_check / TILE)] - '0';
			aux->found_wall_hit = TRUE;
			break ;
		}
		else
		{
			aux->next_touchx += utils->x_step;
			aux->next_touchy += utils->y_step;
		}
	}
}

int	is_inside_map(float x, float y, t_cub3D *cub3d)
{
	if (x >= 0 && x <= get_lenght(cub3d, y) * TILE && y >= 0
		&& y <= cub3d->map_info.height * TILE)
		return (TRUE);
	else
		return (FALSE);
}
