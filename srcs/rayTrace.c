#include "minirt.h"

t_cross *loopSpherelist(t_sphere *sphere, t_ray ray, t_scene *scene)
{
	t_sphere *head;
	t_cross *cross;
	t_cross tmpCross;

	head = sphere;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersect_sphere(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	return (cross);
}

t_cross *loopPlanelist(t_plane *plane, t_ray ray, t_scene *scene)
{
	t_plane *head;
	t_cross *cross;
	t_cross tmpCross;

	head = plane;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersect_plane(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	return (cross);
}

t_cross *loopCylinlist(t_cylinder *cylin, t_ray ray, t_scene *scene)
{
	t_cylinder *head;
	t_cross *cross;
	t_cross tmpCross;

	head = cylin;
	cross = malloc(sizeof(t_cross));
	if (!cross)
		exit_code(1, "cross malloc failed", scene, NULL);
	tmpCross.t = INFINITY;
	while (head)
	{
		if (intersect_cylin(ray, *head, cross) && cross->t < tmpCross.t)
			tmpCross = *cross;
		head = head->next;
	}
	*cross = tmpCross;
	//printf("t ==== %f\n", cross->t);
	return (cross);
}

bool rayTrace(t_scene *scene, t_ray ray, t_cross **finalCross)
{
	float tNear;
	t_cross *crossPlane;
	t_cross *crossSphere;
	t_cross *crossCylin;

	tNear = INFINITY;
	crossPlane = loopPlanelist(scene->plane, ray, scene);
	crossCylin = loopCylinlist(scene->cylin, ray, scene);
	crossSphere = loopSpherelist(scene->sphere, ray, scene);
	tNear = find_min(crossPlane->t, crossSphere->t, crossCylin->t);
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

void	render(t_scene *scene, t_mlx *mlx_data)
{
	int xy[2];
	unsigned int color;
	t_ray ray;
	t_cross *finalCross;
	t_color col;

	finalCross = NULL;
	xy[1] = -1;
	while (++xy[1] < HEIGHT)
	{
		xy[0] = -1;
		while (++xy[0] < WIDTH)
		{
			ray = ray_generate(xy[0], xy[1], *(scene->cam));
			if (!rayTrace(scene, ray, &finalCross))
				color = create_rgb(0, 0, 0);
			else
			{
				col = final_lighting(scene, finalCross);
				color = makeIntFromRGB(col);
				//color = create_rgb(0, 0, 255);
			}
			free_null(finalCross);
			my_mlx_pixel_put(mlx_data, xy[0], xy[1], color);
		}
	}
	mlx_put_image_to_window(mlx_data->mlx, mlx_data->win, mlx_data->img, 0, 0);
}