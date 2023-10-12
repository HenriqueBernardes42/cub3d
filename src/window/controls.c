#include "window.h"

int		exit_button(t_data *data);
void	buttons_hook(t_data *data);
void	update_var(t_data *data);


int	key_press(int key, t_data *data)
{
	update_var(data);

	if (key == ESC_KEY)
		exit_button(data);
	if (key == W_KEY)
		data->player.walk_direction = +1;
	if (key == S_KEY)
		data->player.walk_direction = -1;
	// if (key == A_KEY)
	// {
	// 	data->player.side_direction = +90;
	// 	data->player.walk_direction = +1;
	// }
	// if (key == D_KEY)
	// {
	// 	data->player.side_direction = -1;
	// 	data->player.walk_direction = +1;
	// }
	if (key == RIGHT_KEY)
	 	data->player.turn_direction = +1;
	if (key == LEFT_KEY)
		data->player.turn_direction = -1;
		
	draw(data);
	return (0);
}

int	exit_button(t_data *data)
{
	mlx_loop_end(data->mlx);
	return (0);
}

void	buttons_hook(t_data *data)
{
	mlx_hook(data->win, 17, 0, exit_button, data);
	mlx_hook(data->win, 02, 1L << 0, key_press, data);
}

void update_var(t_data *data)
{
    data->player.rotation_speed = 2 * (PI / 180);
	data->player.turn_direction = 0;
	data->player.walk_direction = 0;
	data->player.side_direction = 1;
}

