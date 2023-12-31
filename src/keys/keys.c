/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:14 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/09 01:01:16 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_release(int key, t_cub3D *cub3d)
{
	if (key == RIGHT)
		cub3d->player.side_direction = 0;
	if (key == ARROW_RIGHT)
		cub3d->player.turn_direction = 0;
	if (key == LEFT)
		cub3d->player.side_direction = 0;
	if (key == ARROW_LEFT)
		cub3d->player.turn_direction = 0;
	if (key == TOP)
		cub3d->player.walk_direction = 0;
	if (key == DOWN)
		cub3d->player.walk_direction = 0;
	return (0);
}

int	action(int keycode, t_cub3D *cub3D)
{
	if (keycode == ESC)
		close_win(cub3D);
	if (keycode == RIGHT)
		cub3D->player.side_direction = -1;
	if (keycode == ARROW_RIGHT)
		cub3D->player.turn_direction = +1;
	if (keycode == LEFT)
		cub3D->player.side_direction = +1;
	if (keycode == ARROW_LEFT)
		cub3D->player.turn_direction = -1;
	if (keycode == TOP)
		cub3D->player.walk_direction = +1;
	if (keycode == DOWN)
		cub3D->player.walk_direction = -1;
	return (TRUE);
}
