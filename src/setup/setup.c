/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pauvicto <pauvicto@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 01:01:46 by pauvicto          #+#    #+#             */
/*   Updated: 2023/11/10 20:15:00 by pauvicto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	setup(t_cub3D *cub3D)
{
	if (!start_player(cub3D))
		return (0);
	start_textures(cub3D);
	return (1);
}
