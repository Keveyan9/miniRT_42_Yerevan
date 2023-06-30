#include "minirt.h"

t_sphere	*ft_lstlast_sp(t_sphere *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_sp(t_sphere **lst, t_sphere *new)
{
	t_sphere *position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_sp(*lst);
		position->next = new;
	}
}

t_sphere	*initSphere(t_vec orig, t_color tint, float radius)
{
	t_sphere *sphere;
	int i;

	i = -1;
	sphere = malloc(sizeof(t_sphere));
	if (!sphere)
		exit_code(1, "sphere malloc failed");
	initVector(orig, &(sphere->center));
	initColor(tint, &(sphere->tint));
	sphere->radius = radius;
	return (sphere);
}

void	checkerSp(char **splitted_sp, t_scene *scene)
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
	checkVector(center, &centerVec, INT_MIN, FLT_MAX);
	checkColor(tint, &tintVec);
	radius = ft_atof(splitted_sp[2]);
    ft_lstadd_back_sp(&scene->sphere, initSphere(centerVec, tintVec, radius));
}