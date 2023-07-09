#include "minirt.h"

t_cross	*loopSphereList(t_sphere *sphere, t_ray ray, t_scene *scene)
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
        if (intersectSphere(ray, *head, cross) && cross->t < tmpCross.t)
            tmpCross = *cross;
        head = head->next;
    }
    *cross = tmpCross;
    return (cross);
}

t_cross	*loopPlaneList(t_plane *plane, t_ray ray, t_scene *scene)
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
        if (intersectPlane(ray, *head, cross) && cross->t < tmpCross.t)
            tmpCross = *cross;
        head = head->next;
    }
    *cross = tmpCross;
    return (cross);
}

t_cross	*loopCylinList(t_cylinder *cylin, t_ray ray, t_scene *scene)
{
    t_cylinder  *head;
    t_cross     *cross;
    t_cross tmpCross;

    head = cylin;
    cross = malloc(sizeof(t_cross));
    if (!cross)
        exit_code(1, "cross malloc failed", scene, NULL);
    tmpCross.t = INFINITY;
    while (head)
    {
        if (intersectCylin2(ray, *head, cross) && cross->t < tmpCross.t)
            tmpCross = *cross;
        head = head->next;
    }
    *cross = tmpCross;
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


static void calculate(t_oll *oll , int x, int y)
{
	t_cross			*finalCross;
	t_ray			ray;
	t_color			col;
	unsigned int	color;
	
	finalCross = NULL;
	ray = rayGenerate(x, y, *(oll->scene->cam));
	rayTrace(oll->scene, ray, &finalCross);
	if (finalCross->t == INFINITY)
		color = create_rgb (0, 0, 0);
		else
		{
			col = final_lighting(oll->scene, finalCross);
			color = makeIntFromRGB(col);
		}
	free_null(finalCross);
	my_mlx_pixel_put(oll->mlxData, x, y, color);
}

void *thread_width_function(void *data)
{
	t_oll 		*oll;
	int			xy[2];
	oll = data;
	xy[0] =	oll->x;
	xy[1] = -1;
	while (++(xy[1]) < HEIGHT)
		calculate(oll,xy[0],xy[1]);
	return (NULL);
}

void	render(t_oll *oll)
{
	int	result_w;
	int	count_treads;
	int	cycle;
	pthread_t threads[WIDTH];

	result_w = 0;
	cycle = 0;
	count_treads = 0;
	
	oll->x = -1;
	while (++(oll->x) <  WIDTH)
	{
		// thread_width_function(oll);
		result_w = pthread_create(&threads[count_treads++], NULL, thread_width_function, oll);
		if (result_w != 0) 
		{
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
		usleep (250);
	}
	while(cycle < WIDTH)
		 pthread_join(threads[cycle++], NULL);
	mlx_put_image_to_window(oll->mlxData->mlx, oll->mlxData->win,oll->mlxData->img, 0, 0);
	return;
}
