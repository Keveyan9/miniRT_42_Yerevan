#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# define SPLIT_SET " \t\v\b"


typedef struct s_ambient
{
	float	ratio;
	float	tint[3];

}t_ambient;
typedef struct s_cam
{
	float	orig[3];
	float	orientation[3];
	float	fov;
}	t_cam;

typedef struct s_light
{
	float	orig[3];
	float	ratio;
}	t_light;

typedef struct s_sphere
{
	float		center[3];
	float		tint[3];
	float		radius;

	t_sphere	*prev;
	t_sphere	*next;
}	t_sphere;

typedef struct s_plane
{
	float	point[3];
	float	normal[3];
	int		tint[3];

	t_plane	*prev;
	t_plane	*next;
}	t_plane;
typedef struct s_cylinder
{
	float		center[3];
	float		normal[3];
	float		radius;
	float		height;
	int			tint[3];
	t_cylinder	*prev;
	t_cylinder	*next;

}	t_cylinder;

typedef struct s_head
{
	t_cam		*cam;
	t_light		*light;
	t_sphere	*sphere;
	t_plane		*plane;
	t_cylinder	*cylin;
	int			cofficient;

}t_head;

typedef struct s_window
{
	int	width;
	int	height;
}t_window;

void	parsing(int argc, char **argv, t_head *head);
void	exit_code(int code, char *msg);

// int 	is_in_set(char c);
// char	**ft_split_m(char const *s);
// int		ft_double_len(char **str);
// float 	ft_atof(char *str);
#endif