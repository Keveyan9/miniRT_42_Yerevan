#include "minirt.h"

void	LookAt(t_matrix *matrix, t_cam camera, t_vec to)
{
    // t_vec   u;
    // t_vec   v;
    // t_vec   w;

	matrix->camZ = normalize(vecSub(camera.orig, to));
	matrix->camX = normalize(cross(camera.orientation, matrix->camZ));
	matrix->camY = normalize(cross(matrix->camZ, matrix->camX));
}
