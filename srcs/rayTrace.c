#include "minirt.h"

t_cross	*loopSphereList(t_sphere *sphere, t_ray ray, t_scene *scene)
{
	t_sphere	*head;
	t_cross		*cross;
	float		tNear;

	head = sphere;
 	tNear = INFINITY;
	cross = malloc(sizeof(t_cross));
	if (!cross)
	 	exit_code(1, "cross malloc failed", scene, NULL);
	cross->t = 0;
	while (head)
	{
		if (intersectSphere(ray, *head, cross) && cross->t < tNear)
			tNear = cross->t;
		head = head->next;
	}
	cross->t = tNear;
	return (cross);
}

t_cross	*loopPlaneList(t_plane *plane, t_ray ray, t_scene *scene)
{
	t_plane	*head;
	t_cross	*cross;
	float	tNear;

	head = plane;
	tNear = INFINITY;
	cross = malloc(sizeof(t_cross));
	if (!cross)
	 	exit_code(1, "cross malloc failed", scene, NULL);
	cross->t = 0;
	while (head)
	{
		if (intersectPlane(ray, *head, cross) && cross->t < tNear)
			tNear = cross->t;
		head = head->next;
	}
	cross->t = tNear;
	return (cross);
}

t_cross	*loopCylinList(t_cylinder *cylin, t_ray ray, t_scene *scene)
{
	t_cylinder	*head;
	t_cross		*cross;
	float		tNear;

	head = cylin;
	tNear = INFINITY;
	cross = malloc(sizeof(t_cross));
	if (!cross)
	 	exit_code(1, "cross malloc failed", scene, NULL);
	cross->t = 0;
	while (head)
	{
		if (intersectCylin2(ray, *head, cross) && cross->t < tNear)
			tNear = cross->t;
		head = head->next;
	}
	cross->t = tNear;
	return (cross);
}

bool	rayTrace(t_scene *scene, t_ray ray, t_cross **finalCross)
{
	float	tNear;
	t_cross	*crossPlane;
	t_cross	*crossSphere;
	t_cross	*crossCylin;

	tNear = INFINITY;
	crossPlane = loopPlaneList(scene->plane, ray, scene);
	crossCylin = loopCylinList(scene->cylin, ray, scene);
	crossSphere = loopSphereList(scene->sphere, ray, scene);
	tNear = findMin(crossPlane->t, crossSphere->t, crossCylin->t);
	if (tNear == crossPlane->t)
	{
		*finalCross = crossPlane;
		free_null(crossSphere);
		free_null(crossCylin);
	}
	else if (tNear == crossSphere->t)
	{
		*finalCross = crossSphere;
		free_null(crossPlane);
		free_null(crossCylin);
	}
	else if (tNear == crossCylin->t)
	{
		*finalCross = crossCylin;
		free_null(crossPlane);
		free_null(crossSphere);
	}
	if (tNear != INFINITY)
		return (1);
	return (0);
}

int create_rgb(int r, int g, int b)
{
    return (r << 16 | g << 8 | b);
}

// void	render(t_scene *scene, t_mlx *mlxData)
// {
// 	int				x = -1;
// 	int				y = -1;
// 	unsigned int	color;
// 	t_ray			ray;
// 	t_cross			*finalCross;
// 	// t_color			col;

// 	finalCross = NULL;
// 	while (++y < HEIGHT)
// 	{
// 		x = -1;
// 		while (++x < WIDTH)
// 		{
// 			ray = rayGenerate(x, y, *(scene->cam));
// 			if(!rayTrace(scene, ray, &finalCross))
// 				color = create_rgb (0, 0, 0);
// 			else
// 			{
// 				// col = final_lighting(scene, finalCross);
// 				// color = makeIntFromRGB(col);
// 				color = create_rgb(255, 0, 0);
// 				// printf("color == %d\n", color);
// 			}
// 			// free_null(finalCross);
// 			my_mlx_pixel_put(mlxData, x, y, color);
// 		}
// 	}
// 	mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
// }
void	render(t_scene *scene, t_mlx *mlxData)
{
	int				xy[2];
	unsigned int	color;
	t_ray			ray;
	t_cross			*finalCross;
	t_color			col;

	finalCross = NULL;
	xy[1] = -1;
	while (++xy[1] < HEIGHT)
	{
		xy[0] = -1;
		while (++xy[0] < WIDTH)
		{
			ray = rayGenerate(xy[0], xy[1], *(scene->cam));
			rayTrace(scene, ray, &finalCross);
			if (finalCross->t == INFINITY)
				color = create_rgb (0, 0, 0);
			else
			{
				col = final_lighting(*scene, finalCross);
				color = makeIntFromRGB(col);
			}
			free_null(finalCross);
			my_mlx_pixel_put(mlxData, xy[0], xy[1], color);
		}
	}
	mlx_put_image_to_window(mlxData->mlx, mlxData->win, mlxData->img, 0, 0);
}