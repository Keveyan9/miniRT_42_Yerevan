#include "minirt.h"

t_plane	*ft_lstlast_pl(t_plane *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back_pl(t_plane **lst, t_plane *new)
{
	t_plane *position;

	if (!lst || !new)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		position = ft_lstlast_pl(*lst);
		position->next = new;
	}
}

static t_plane	*initPlane(t_vec point, t_vec normal, t_color tint, t_scene *scene)
{
	t_plane *plane;

	plane = malloc(sizeof(t_plane));
	if (!plane)
		exit_code(1, "plane malloc failed",scene,NULL);
	initVector(point, &(plane->point));
	initVector(normal, &(plane->normal));
	initColor(tint, &(plane->tint));

	plane->next = NULL;
	return (plane);
}

void	checkerPl(char **splitted_pl, t_scene *scene)
{
	char	**orientationSplitted;
	char	**origin;
	char	**tintSplitted;
	t_vec	originVec;
	t_vec	orientVec;
	t_color	tint;

	if (ft_double_len(splitted_pl) != 4)
		exit_code(1, "Invalid number of parameters for pl\n",scene,NULL);
	origin = ft_split(splitted_pl[1], ',');
	orientationSplitted = ft_split(splitted_pl[2], ',');
	tintSplitted = ft_split(splitted_pl[3], ',');
	checkVector(origin, &originVec, INT_MIN, FLT_MAX,scene);
	if(origin)
		frik(origin);
	checkVector(orientationSplitted, &orientVec, -8, 1,scene);
	if(orientationSplitted)
		frik(orientationSplitted);
	checkColor(tintSplitted, &tint,scene);
	if(tintSplitted)
		frik(tintSplitted);
	if (!scene->plane)
		scene->plane = initPlane(originVec, orientVec, tint,scene);
	else
		ft_lstadd_back_pl(&scene->plane, initPlane(originVec, orientVec, tint,scene));
}