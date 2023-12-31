#ifndef STRUCTS_H

# define STRUCTS_H

# include <macros.h>
# include <stdint.h>

typedef struct s_texture_path
{
	char *TEX_NO;
	char *TEX_SO;
	char *TEX_WE;
	char *TEX_EA;
} t_texture_path;

typedef struct s_colors
{
	int ceiling;
	int floor;
} t_colors;

typedef struct s_file_info
{
	t_texture_path	texture_path;
	t_colors	colors;
} t_file_info;

typedef struct s_projection
{
	float		correct_wall_distance;
	float		proj_wall_height;
	int			wall_strip_height;
	int			wall_top_pixel;
	int			wall_bottom_pixel;
	int			x;
	int			y;
	int			texture_offset_x;
	int			texture_off_sety;
	int			tex_num;
	int			distance_from_top;
	uint32_t	texel_color;
}				t_projection;

typedef struct s_aux_ray
{
	int		found_wall_hit;
	float	wall_hit_x;
	float	wall_hit_y;
	int		wall_content;
	float	next_touchx;
	float	next_touchy;
	float	xto_check;
	float	yto_check;
	float	hit_distance;
}			t_aux_ray;

typedef struct s_utils_ray
{
	float		x_intercept;
	float		y_intercept;
	float		x_step;
	float		y_step;
	int			is_ray_facing_up;
	int			is_ray_facing_down;
	int			is_ray_facing_left;
	int			is_ray_facing_right;
}			t_utils_ray;

typedef struct s_ray
{
	float		ray_angle;
	float		wall_hit_x;
	float		wall_hit_y;
	float		distance;
	int			was_hit_vertical;
	int			wall_hit_cotent;
}				t_ray;

typedef struct s_line
{
	int				x1;
	int				y1;
	int				x2;
	int				y2;
	int				delta_x;
	int				delta_y;
	int				long_side_len;
	float			x_increment;
	float			y_increment;
	float			current_x;
	float			current_y;
	unsigned int	color;

}					t_line;

//turndirection =  -1 for leftl, +1 for right
//walkdirection = -1 for back, +1 for front
typedef struct s_player
{
	float	x;
	float	y;
	float	width;
	float	height;
	int		turn_direction;
	int		side_direction;
	int		walk_direction;
	float	rotation_angle;
	float	walk_speed;
	float	turn_speed;
	int		orientation;
}			t_player;

typedef struct s_pos
{
	int	y;
	int	x;
	int status;
}		t_pos;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bpp;
	int		l_len;
	int		endian;
	t_pos	pos;
}			t_data;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}			t_mlx;

typedef struct s_img
{
	t_data	no;
	t_data	we;
	t_data	so;
	t_data	ea;
}			t_img;

typedef struct s_map_info
{
	int	height;
	int	width;
}		t_map_info;

typedef struct s_rgb
{
	int		red;
	int		green;
	int		blue;
	int		status;
}		t_rgb;

typedef struct s_collor
{
	t_rgb	cell_rgb;
	t_rgb	floor_rgb;
	int		cell;
	int		floor;
	int		status;
}		t_collor;

typedef struct s_cub3D
{
	t_player	player;
	t_ray		rays[NUM_RAYS];
	char		***texture_path;
	char		***colors;
	char		**map;
	char		**content_map;
	t_data		img;
	t_img		sprites;
	t_mlx		s_mlx;
	uint32_t	*textures[NUM_TEXTURES];
	t_collor	collors;
	t_map_info	map_info;
	t_file_info file_info;
	double		dist_proj_plane;
}			t_cub3D;

typedef struct s_node_map
{
    char* line;
	int	  size;
    struct s_node_map *next;
} t_node_map;

typedef struct s_list_map
{
    t_node_map *begin;
    t_node_map *end;
	char		**map;
} t_list_map;

typedef struct s_scale
{
	int width;
	int height;
} t_scale;



#endif
