#include "minirt.h"

int color_range_check(float vec[3], int lower_bound, int upper_bound)
{
	if ((vec[0] < lower_bound || vec[0] > upper_bound)
		|| (vec[1] < lower_bound || vec[1] > upper_bound)
		|| (vec[2] < lower_bound || vec[2] > upper_bound))
		return (0);
	return (1);
}

void check_vector(char **vec_splitted, float (*vec)[3], int lower_bound, int upper_bound)
{
	printf("vec_splitted[0] == %s\n", vec_splitted[0]);
	if (ft_double_len(vec_splitted) != 3)
		exit_code(1, "Invalid number of parameters for vector\n");
	(*vec)[0] = ft_atof(vec_splitted[0]);
	(*vec)[1] = ft_atof(vec_splitted[1]);
	(*vec)[2] = ft_atof(vec_splitted[2]);
	if (color_range_check(*vec, lower_bound, upper_bound) == 0)
		exit_code(1, "Vector coordinates are out of range\n");
}

void checker_A(char **splitted_A, t_head *head)
{
	float	ratio;
	char	**rgb_splitted;
	float	color[3];

	printf("splitted[0] == %s\n", splitted_A[0]);
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

	if (ft_double_len(splitted_C) != 3)
		exit_code(1, "Invalid number of parameters for A\n");
	origin = ft_split(splitted_C[1], ',');
	orientation_splitted = ft_split(splitted_C[2], ',');
	check_vector(origin, &origin_vec, INT_MIN, INT_MAX);
	check_vector(orientation_splitted, &orient_vec, -1, 1);
	fov = ft_atof(splitted_C[3]);
	if (fov < 0.0 || fov > 180.0)
		exit_code(1, "fov is out of range for C\n");
	head->cam = init_cam(orient_vec, origin_vec, fov);
}

void checker_parsing(char **splitted_line, t_head *head)
{
	if (!splitted_line[0] || !splitted_line[0][0])
		exit_code(1, "Empty or only spaces detected\n");
	if (ft_strncmp(splitted_line[0], "A", 2))
		checker_A(splitted_line, head);
	//else if (ft_strncmp(splitted_line[0], "C", 2))
	//	checker_C(splitted_line, head);
	// else if (ft_strncmp(splitted_line[0], "L", 2))
	// else if (ft_strncmp(splitted_line[0], "pl", 3))
	// //
	// else if (ft_strncmp(splitted_line[0], "sp", 3))
	// //
	// else if (ft_strncmp(splitted_line[0], "cy", 3))
	//     //
	// else
	//     exit_code(1, "Invalid argument");
}