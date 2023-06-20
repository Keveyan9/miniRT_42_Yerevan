#include "minirt.h"

void 	checkVector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound)
{
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for vector\n");
	if (!only_digit_in_str(vec_splitted[0]))
		exit_code(1, "X coordinate of vector is invalid\n");
	if (!only_digit_in_str(vec_splitted[1]))
		exit_code(1, "Y coordinate of vector is invalid\n");
	if (!only_digit_in_str(vec_splitted[2]))
		exit_code(1, "Z coordinate of vector is invalid\n");
	vector->x = ft_atof(vec_splitted[0]);
	vector->y = ft_atof(vec_splitted[1]);
	vector->z = ft_atof(vec_splitted[2]);
	if (vector_range_check(vector, lower_bound, upper_bound) == 0)
		exit_code(1, "Vector coordinates are out of range\n");
}

void	checkColor(char **vec_splitted, t_color *tint)
{
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for color\n");
	if (!only_digit_in_str(vec_splitted[0]))
		exit_code(1, "R of color is invalid\n");
	if (!only_digit_in_str(vec_splitted[1]))
		exit_code(1, "G of color is invalid\n");
	if (!only_digit_in_str(vec_splitted[2]))
		exit_code(1, "B of color is invalid\n");
	tint->r = ft_atof(vec_splitted[0]);
	tint->g = ft_atof(vec_splitted[1]);
	tint->b = ft_atof(vec_splitted[2]);
	if (color_range_check(tint) == 0)
		exit_code(1, "Color coordinates are out of range\n");
}

void	checker_A(char **splitted_A, t_scene *scene)
{
	float	ratio = 1;
	char	**rgb_splitted;
	t_color	color;

	if (ft_double_len(splitted_A) != 3)
		exit_code(1, "Invalid number of parameters for A\n");
	ratio = ft_atof(splitted_A[1]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for A\n");
	rgb_splitted = ft_split(splitted_A[2], ',');
	checkColor(rgb_splitted, &color);
	scene->amb = initAmbient(ratio, color);
}

void	checker_C(char **splitted_C, t_scene *scene)
{
	char	**orientation_splitted;
	char	**origin;
	t_vec	originVec;
	t_vec	orientVec;
	float	fov;

	if (ft_double_len(splitted_C) != 4)
		exit_code(1, "Invalid number of parameters for C\n");
	origin = ft_split(splitted_C[1], ',');
	orientation_splitted = ft_split(splitted_C[2], ',');
	checkVector(origin, &originVec, INT_MIN, FLT_MAX);
	checkVector(orientation_splitted, &orientVec, -1, 1);
	fov = ft_atof(splitted_C[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n");
	scene->cam = initCam(orientVec, originVec, fov);
}

void	checker_L(char **splitted_L, t_scene *scene)
{
	char	**origin;
	char	**rgb_splitted;
	t_vec	origin_vec;
	float	ratio;
	t_color	color;

	if (ft_double_len(splitted_L) != 4)
		exit_code(1, "Invalid number of parameters for L\n");
	origin = ft_split(splitted_L[1], ',');
	checkVector(origin, &origin_vec, INT_MIN, FLT_MAX);
	ratio = ft_atof(splitted_L[2]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for L\n");
	rgb_splitted = ft_split(splitted_L[3], ',');
	checkColor(rgb_splitted, &color);
	scene->light = initLight(origin_vec, ratio);
}