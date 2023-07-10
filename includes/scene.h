#ifndef SCENE_H
#define SCENE_H

#include "vectorRay.h"

#define SPLIT_SET " \t\v\b"

typedef struct s_ambient
{
	float ratio;
	t_color tint;
} t_ambient;

typedef struct s_cam
{
	t_vec orig;
	t_vec orientation;
	float fov;
} t_cam;

typedef struct s_light
{
	t_vec orig;
	float ratio;
	t_color tint;
} t_light;

typedef struct s_sphere
{
	t_vec center;
	t_color tint;
	float radius;
	int size;
	struct s_sphere *next;
} t_sphere;

typedef struct s_plane
{
	t_vec point;
	t_vec normal;
	t_color tint;
	struct s_plane *next;
} t_plane;

typedef struct s_cylinder
{
	t_vec center;
	t_vec axis;
	t_color tint;
	t_vec topCapCent;
	t_vec bottomCapCent;
	float radius;
	float height;
	struct s_cylinder *next;
} t_cylinder;

typedef	struct	s_parsing
{
	char **orientSplitted;
	char **originSplitted;
	char **tint;
}	t_parsing;

typedef struct s_scene
{
	t_ambient *amb;
	t_cam *cam;
	t_light *light;
	t_sphere *sphere;
	t_sphere *begin_sphere;
	t_plane *plane;
	t_plane *begin_plane;
	t_cylinder *cylin;
	t_cylinder *begin_cylinder;
	char		**vec_splitted;
	// t_parsing pars;
} t_scene;

#endif