#include "minirt.h"

int color_range_check(float vec[3], float lower_bound, float upper_bound)
{
	printf("vec[0] == %f\n", vec[0]);
	printf("vec[1] == %f\n", vec[1]);
	printf("vec[2] == %f\n", vec[2]);
	if ((vec[0] < lower_bound || vec[0] > upper_bound)
		|| (vec[1] < lower_bound || vec[1] > upper_bound)
		|| (vec[2] < lower_bound || vec[2] > upper_bound))
		return (0);
	return (1);
}

void check_vector(char **vec_splitted, float (*vec)[3], float lower_bound, float upper_bound)
{
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for vector\n");
	(*vec)[0] = ft_atof(vec_splitted[0]);
	(*vec)[1] = ft_atof(vec_splitted[1]);
	(*vec)[2] = ft_atof(vec_splitted[2]);
	if (color_range_check(*vec, lower_bound, upper_bound) == 0)
	{
		printf("lower_range is == %f\n", lower_bound);
		exit_code(1, "Vector coordinates are out of range\n");
	}
}

void checker_A(char **splitted_A, t_head *head)
{
	float	ratio;
	char	**rgb_splitted;
	float	color[3];

	if (ft_double_len(splitted_A) != 3)
		exit_code(1, "Invalid number of parameters for A\n");
	ratio = ft_atof(splitted_A[1]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for A\n");
	rgb_splitted = ft_split(splitted_A[2], ',');
	check_vector(rgb_splitted, &color, 0, 255);
	head->amb = init_ambient(ratio, color);
}

void checker_C(char **splitted_C, t_head *head)
{
	char	**orientation_splitted;
	char	**origin;
	float	origin_vec[3];
	float	orient_vec[3];
	float	fov;

	if (ft_double_len(splitted_C) != 4)
		exit_code(1, "Invalid number of parameters for C\n");
	origin = ft_split(splitted_C[1], ',');
	orientation_splitted = ft_split(splitted_C[2], ',');
	check_vector(origin, &origin_vec, INT_MIN, FLT_MAX);
	check_vector(orientation_splitted, &orient_vec, -1, 1);
	fov = ft_atof(splitted_C[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n");
	head->cam = init_cam(orient_vec, origin_vec, fov);
}

void checker_L(char **splitted_L, t_head *head)
{
	char	**origin;
	float	origin_vec[3];
	float	ratio;

	if (ft_double_len(splitted_L) != 3)
		exit_code(1, "Invalid number of parameters for L\n");
	origin = ft_split(splitted_L[1], ',');
	check_vector(origin, &origin_vec, INT_MIN, FLT_MAX);
	ratio = ft_atof(splitted_L[2]);
	if (ratio < 0.0 || ratio > 1.0)
		exit_code(1, "Ratio is out of range for L\n");
	head->light = init_light(origin_vec, ratio);
}

void checker_pl(char **splitted_pl, t_head *head)
{
	char	**orientation_splitted;
	char	**origin;
	char	**tint;
	float	origin_vec[3];
	float	orient_vec[3];
	float	tint_vec[3];

	if (ft_double_len(splitted_pl) != 4)
		exit_code(1, "Invalid number of parameters for pl\n");
	origin = ft_split(splitted_pl[1], ',');
	orientation_splitted = ft_split(splitted_pl[2], ',');
	tint = ft_split(splitted_pl[3], ',');
	check_vector(origin, &origin_vec, INT_MIN, FLT_MAX);
	check_vector(orientation_splitted, &orient_vec, -1, 1);
	check_vector(tint, &tint_vec, 0, 255);
	head->plane = init_plane(orient_vec, origin_vec, tint_vec);
}

void checker_sp(char **splitted_sp, t_head *head)
{
	char	**center;
	char	**tint;
	float	center_vec[3];
	float	tint_vec[3];
	float	radius;

	if (ft_double_len(splitted_sp) != 4)
		exit_code(1, "Invalid number of parameters for sp\n");
	center = ft_split(splitted_sp[1], ',');
	tint = ft_split(splitted_sp[3], ',');
	check_vector(center, &center_vec, INT_MIN, FLT_MAX);
	check_vector(tint, &tint_vec, 0, 255);
	radius = ft_atof(splitted_sp[2]);
	head->sphere = init_sphere(center_vec, tint_vec, radius);
}

void checker_cy(char **splitted_cy, t_head *head)
{
	char	**orientation_splitted;
	char	**origin;
	char	**tint;
	float	origin_vec[3];
	float	orient_vec[3];
	float	tint_vec[3];
	float	radius;
	float	height;

	if (ft_double_len(splitted_cy) != 6)
		exit_code(1, "Invalid number of parameters for cylin\n");
	origin = ft_split(splitted_cy[1], ',');
	orientation_splitted = ft_split(splitted_cy[2], ',');
	tint = ft_split(splitted_cy[5], ',');
	radius = ft_atof(splitted_cy[3]);
	height = ft_atof(splitted_cy[4]);
	check_vector(origin, &origin_vec, INT_MIN, FLT_MAX);
	check_vector(orientation_splitted, &orient_vec, -1, 1);
	check_vector(tint, &tint_vec, 0, 255);
	head->cylin = init_cylinder(origin_vec, orient_vec, tint_vec, radius, height);
}

void checker_parsing(char **splitted_line, t_head *head)
{
	if (!splitted_line[0] || !splitted_line[0][0])
		exit_code(1, "Empty or only spaces detected\n");
	printf("0 == %s\n", splitted_line[0]);
	if (ft_strncmp(splitted_line[0], "A", 2) == 0)
		checker_A(splitted_line, head);
	else if (ft_strncmp(splitted_line[0], "C", 2) == 0)
		checker_C(splitted_line, head);
	// else if (ft_strncmp(splitted_line[0], "L", 2) == 0)
	// 	checker_L(splitted_line, head);
	// else if (ft_strncmp(splitted_line[0], "pl", 3) == 0)
	// 	checker_pl(splitted_line, head);
	// else if (ft_strncmp(splitted_line[0], "sp", 3) == 0)
	// 	checker_sp(splitted_line, head);
	// else if (ft_strncmp(splitted_line[0], "cy", 3) == 0)
	// 	checker_cy(splitted_line, head);./GI	
	else
	    exit_code(1, "Invalid argument");
}