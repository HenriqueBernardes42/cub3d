#include "cub3d.h"

int	map_has_wall_at(t_cub3D *cub3D, float x, float y);
int	get_lenght(t_cub3D *cub3D, float line);


void	move_player(t_cub3D *cub3D)
{
	float	move_step;
	float	side_step;
	float	new_player_x;
	float	new_player_y;

	cub3D->player.rotation_angle += cub3D->player.turn_direction
		* cub3D->player.turn_speed;
	side_step = cub3D->player.side_direction * cub3D->player.walk_speed;
	move_step = cub3D->player.walk_direction * cub3D->player.walk_speed;
	if (move_step && side_step)
	{
		move_step /= 2;
		side_step /= 2;
	}
	new_player_x = cub3D->player.x + cos(cub3D->player.rotation_angle) * move_step;
	new_player_y = cub3D->player.y + sin(cub3D->player.rotation_angle) * move_step;
	new_player_x = new_player_x - sin(-cub3D->player.rotation_angle) * side_step;
	new_player_y = new_player_y - cos(-cub3D->player.rotation_angle) * side_step;
	if (!map_has_wall_at(cub3D, new_player_x, new_player_y))
	{
		cub3D->player.x = new_player_x;
		cub3D->player.y = new_player_y;
	}
}



