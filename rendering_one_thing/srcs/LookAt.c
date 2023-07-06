#include "minirt.h"

t_vec createVec(float x, float y, float z)
{
    t_vec   vec;

    vec.x = x;
    vec.y = y;
    vec.z = z;
    return (vec);
}

// void    LookAt(t_matrix *matrix, t_cam camera, t_vec to)
// {
//     // t_vec   u;
//     // t_vec   v;
//     // t_vec   w;

//     matrix->camZ = normalize(vecSub(camera.orig, to));
//     matrix->camX = normalize(cross(camera.orientation, matrix->camZ));
//     matrix->camY = normalize(cross(matrix->camZ, matrix->camX));
// }

void    LookAt(t_matrix *matrix, t_cam camera)
{
    t_vec   tmp = createVec(0,1,0);
 
    matrix->camZ = camera.orientation;
    matrix->camX = normalize(cross(tmp, matrix->camZ));
    matrix->camY = normalize(cross(matrix->camZ, matrix->camX));
}