#include "minirt.h"

t_vec   vecInit(float x, float y, float z)
{
    t_vec tmp;

    tmp.x = x;
    tmp.y = y;
    tmp.z = z;
    return (tmp);
}

void    LookAt(t_matrix *matrix, t_cam camera)
{
    t_vec       arbitrary;

    arbitrary = vecInit(0, 1, 0);
    matrix->camZ = normalize(camera.orientation);
    matrix->camX = normalize(cross(arbitrary, matrix->camZ));
    matrix->camY = normalize(cross(matrix->camZ, matrix->camX));
}