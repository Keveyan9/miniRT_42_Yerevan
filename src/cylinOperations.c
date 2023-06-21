#include "minirt.h"

t_cylinder	*ft_lstlast_cylin(t_cylinder *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_cy(t_cylinder **lst, t_cylinder *new)
{
	t_cylinder *position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_cylin(*lst);
		position->next = new;
	}
}

t_cylinder	*initCylinder(t_vec center, t_vec normal, t_color tint, float radius, float height)
{
	t_cylinder *cylinder;
	int i;

	i = -1;
	cylinder = malloc(sizeof(t_cylinder));
	if (!cylinder)
		exit_code(1, "cylinder malloc failed");
	initVector(center, &(cylinder->center));
	initVector(normal, &(cylinder->axis));
	initColor(tint, &(cylinder->tint));
	cylinder->radius = radius;
	cylinder->height = height;
	return (cylinder);
}

void	checkerCy(char **splitted_cy, t_scene *scene)
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
	radius = ft_atof(splitted_cy[3]) / 2;
	height = ft_atof(splitted_cy[4]);
	checkVector(origin, &originVec, INT_MIN, FLT_MAX);
	checkVector(orientationSplitted, &orientVec, -1, 1);
	checkColor(tint, &tintVec);
	ft_lstadd_back_cy(&scene->cylin, initCylinder(originVec, orientVec, tintVec, radius, height));
	// scene->cylin = initCylinder(originVec, orientVec, tintVec, radius, height);
}