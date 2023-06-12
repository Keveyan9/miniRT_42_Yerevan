#include "minirt.h"

int vector_range_check(t_vec *vector, float lower_bound, float upper_bound)
{
	if ((vector->x < lower_bound || vector->x > upper_bound)
		|| (vector->y < lower_bound || vector->y > upper_bound)
		|| (vector->z < lower_bound || vector->z > upper_bound))
		return (0);
	return (1);
}

int color_range_check(t_color *tint)
{
	if ((tint->r < 0 || tint->r > 255)
		|| (tint->g < 0 || tint->g > 255)
		|| (tint->b < 0 || tint->b > 255))
		return (0);
	return (1);
}

int	only_digit_in_str(char *s)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if (s[0] == '\n')
		return (0);
	if (s[0] == '-' || s[0] == '+')
	{
		k = 1;
		i++;
	}
	while (s && s[i] != '\n' && s[i] && i < ft_strlen(s))//the last one is '\n'
	{
		if (!ft_isdigit(s[i]) && k == 0 && s[i] != '.')
		{
			printf("here 0000\n");
			return (0);
		}
		else if (s[i] == '.' && s[i + 1] && !ft_isdigit(s[i + 1]))
			return (0);
		i++;
	}
	return (1);
}

void check_vector(char **vec_splitted, t_vec *vector, float lower_bound, float upper_bound)
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

void check_color(char **vec_splitted, t_color *tint)
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

void checker_A(char **splitted_A, t_scene *scene)
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
	check_color(rgb_splitted, &color);
	scene->amb = init_ambient(ratio, color);
}

void checker_C(char **splitted_C, t_scene *scene)
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
	check_vector(origin, &originVec, INT_MIN, FLT_MAX);
	check_vector(orientation_splitted, &orientVec, -1, 1);
	fov = ft_atof(splitted_C[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n");
	scene->cam = init_cam(orientVec, originVec, fov);
}

void checker_L(char **splitted_L, t_scene *scene)
{
	char	**origin;
	t_vec	origin_vec;
	float	ratio;

	if (ft_double_len(splitted_L) != 3)
		exit_code(1, "Invalid number of parameters for L\n");
	origin = ft_split(splitted_L[1], ',');
	check_vector(origin, &origin_vec, INT_MIN, FLT_MAX);
	ratio = ft_atof(splitted_L[2]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for L\n");
	scene->light = init_light(origin_vec, ratio);
}

void checker_pl(char **splitted_pl, t_scene *scene)
{
	char	**orientationSplitted;
	char	**origin;
	char	**tintSplitted;
	t_vec	originVec;
	t_vec	orientVec;
	t_color	tint;

	if (ft_double_len(splitted_pl) != 4)
		exit_code(1, "Invalid number of parameters for pl\n");
	origin = ft_split(splitted_pl[1], ',');
	orientationSplitted = ft_split(splitted_pl[2], ',');
	tintSplitted = ft_split(splitted_pl[3], ',');
	check_vector(origin, &originVec, INT_MIN, FLT_MAX);
	check_vector(orientationSplitted, &orientVec, -1, 1);
	check_color(tintSplitted, &tint);
	scene->plane = init_plane(orientVec, originVec, tint);
}

void checker_sp(char **splitted_sp, t_scene *scene)
{
	char	**center;
	char	**tint;
	t_vec	centerVec;
	t_color	tintVec;
	float	radius;

	if (ft_double_len(splitted_sp) != 4)
		exit_code(1, "Invalid number of parameters for sp\n");
	center = ft_split(splitted_sp[1], ',');
	tint = ft_split(splitted_sp[3], ',');
	check_vector(center, &centerVec, INT_MIN, FLT_MAX);
	check_color(tint, &tintVec);
	radius = ft_atof(splitted_sp[2]);
	scene->sphere = init_sphere(centerVec, tintVec, radius);
}

void checker_cy(char **splitted_cy, t_scene *scene)
{
	char	**orientationSplitted;
	char	**origin;
	char	**tint;
	t_vec	originVec;
	t_vec	orientVec;
	t_color	tintVec;
	float	radius;
	float	height;

	if (ft_double_len(splitted_cy) != 6)
		exit_code(1, "Invalid number of parameters for cylin\n");
	origin = ft_split(splitted_cy[1], ',');
	orientationSplitted = ft_split(splitted_cy[2], ',');
	tint = ft_split(splitted_cy[5], ',');
	radius = ft_atof(splitted_cy[3]);
	height = ft_atof(splitted_cy[4]);
	check_vector(origin, &originVec, INT_MIN, FLT_MAX);
	check_vector(orientationSplitted, &orientVec, -1, 1);
	check_color(tint, &tintVec);
	scene->cylin = init_cylinder(originVec, orientVec, tintVec, radius, height);
}

int checker_parsing(char **splitted_line, t_scene *scene)
{
	static int	upperLetters = 0;

	if (splitted_line[0][0] == '\n')
		return (0);
	if (ft_strncmp(splitted_line[0], "A", 2) == 0 && ++upperLetters)
		checker_A(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "C", 2) == 0 && ++upperLetters)
		checker_C(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "L", 2) == 0 && ++upperLetters)
		checker_L(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "pl", 3) == 0)
		checker_pl(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "sp", 3) == 0)
		checker_sp(splitted_line, scene);
	else if (ft_strncmp(splitted_line[0], "cy", 3) == 0)
		checker_cy(splitted_line, scene);
	else
	    exit_code(1, "Invalid argument\n");
	return (upperLetters);
}