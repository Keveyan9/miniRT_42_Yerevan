#include "minirt.h"

void 	checkVector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound,t_scene *scene)
{
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for vector\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[0]))
		exit_code(1, "X coordinate of vector is invalid\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[1]))
		exit_code(1, "Y coordinate of vector is invalid\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[2]))
		exit_code(1, "Z coordinate of vector is invalid\n",scene,vec_splitted);
	vector->x = ft_atof(vec_splitted[0]);
	vector->y = ft_atof(vec_splitted[1]);
	vector->z = ft_atof(vec_splitted[2]);
	if (lower_bound != -8 && vector_range_check(vector, lower_bound, upper_bound) == 0)
		exit_code(1, "Vector coordinates are out of range\n",scene,vec_splitted);
	else if (lower_bound == -8 && vector_norm_check(vector) == 0)
		exit_code(1, "Vector's norm is out of range\n",scene,vec_splitted);
}

void	checkColor(char **vec_splitted, t_color *tint,t_scene *scene)
{
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for color\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[0]))
		exit_code(1, "R of color is invalid\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[1]))
		exit_code(1, "G of color is invalid\n",scene,vec_splitted);
	if (!only_digit_in_str(vec_splitted[2]))
		exit_code(1, "B of color is invalid\n",scene,vec_splitted);
	tint->r = ft_atof(vec_splitted[0]);
	tint->g = ft_atof(vec_splitted[1]);
	tint->b = ft_atof(vec_splitted[2]);
	if (color_range_check(tint) == 0)
		exit_code(1, "Color coordinates are out of range\n",scene,vec_splitted);
}

void	checker_A(char **splitted_A, t_scene *scene)
{
	float	ratio = 1;
	char	**rgb_splitted;
	t_color	color;

	if (ft_double_len(splitted_A) != 3)
			exit_code(1, "Invalid number of parameters for A\n",scene,splitted_A);
	ratio = ft_atof(splitted_A[1]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for A\n",scene,splitted_A);
	rgb_splitted = ft_split(splitted_A[2], ',');\
	if(splitted_A)
		frik(splitted_A);
	checkColor(rgb_splitted, &color,scene);
	if(rgb_splitted)
		frik(rgb_splitted);
	scene->amb = initAmbient(ratio, color,scene);
	if(splitted_A)
		frik(splitted_A);
}

void	checker_C(char **splitted_C, t_scene *scene)
{
	char	**orientation_splitted;
	char	**origin;
	t_vec	originVec;
	t_vec	orientVec;
	float	fov;

	if (ft_double_len(splitted_C) != 4)
		exit_code(1, "Invalid number of parameters for C\n",scene,splitted_C);
	origin = ft_split(splitted_C[1], ',');
	orientation_splitted = ft_split(splitted_C[2], ',');
	checkVector(origin, &originVec, INT_MIN, FLT_MAX,scene);
	checkVector(orientation_splitted, &orientVec, -1, 1,scene);
	if(origin)
		frik(origin);
	if(orientation_splitted)
		frik(orientation_splitted);
	fov = ft_atof(splitted_C[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n",scene,splitted_C);
	scene->cam = initCam(originVec, orientVec, fov,scene);
	if(splitted_C)
		frik(splitted_C);
}

void	checker_L(char **splitted_L, t_scene *scene)
{
	char	**origin;
	char	**rgb_splitted;
	t_vec	origin_vec;
	float	ratio;
	t_color	color;

	if (ft_double_len(splitted_L) != 4)
		exit_code(1, "Invalid number of parameters for L\n",scene,splitted_L);
	origin = ft_split(splitted_L[1], ',');
	checkVector(origin, &origin_vec, INT_MIN, FLT_MAX,scene);
	if(origin)
		frik(origin);
	ratio = ft_atof(splitted_L[2]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for L\n",scene,splitted_L);
	rgb_splitted = ft_split(splitted_L[3], ',');
	checkColor(rgb_splitted, &color,scene);
	if(rgb_splitted)
		frik(rgb_splitted);
	scene->light = initLight(origin_vec, ratio, color,scene);
	if(splitted_L)
		frik(splitted_L);
}