#include "minirt.h"

static t_vec   vecInit(float x, float y, float z)
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
    matrix->forward = normalize(vecInverse(camera.orientation));
    matrix->right = normalize(cross(arbitrary, matrix->forward));
    matrix->up = normalize(cross(matrix->forward, matrix->right));
}
