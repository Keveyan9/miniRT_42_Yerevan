
#include "minirt.h"
#include <math.h>

// t_ray   createRay(t_vec orig, t_vec dir)
// {
//     t_ray ray;

//     ray.dir = dir;
//     ray.orig = orig;
//     return (ray);
// }

t_vec   gettingWPrime(t_matrix lookAt, t_cam camera)
{
    t_vec   wPrime;
    t_vec   uCoeff;
    t_vec   vCoeff;
    t_vec   wCoeff;

    uCoeff = vecScale((-WIDTH/2), lookAt.camX);//why - ?????
    vCoeff = vecScale((HEIGHT/2), lookAt.camY);
    wCoeff = vecScale(((-HEIGHT/2)/tan(camera.fov * 0.5)), lookAt.camZ);
    wPrime = vecAdd(vecAdd(uCoeff, vCoeff), wCoeff);
    return(wPrime);
}

t_vec   rayDirGenerate(t_matrix lookAt, t_cam camera, float x, float y)
{
    t_vec   rayDir;
    t_vec   xu;
    t_vec   yMinusv;
    t_vec   wPrime;

    xu = vecScale(x, lookAt.camX);
    yMinusv = vecScale(y, vecScale(-1, lookAt.camY));
    wPrime = gettingWPrime(lookAt, camera);
    rayDir = vecAdd(vecAdd(xu, yMinusv), wPrime);
    rayDir = normalize(rayDir);
    return (rayDir);
}
////////////
void    camToWorld(t_matrix lookAT, t_vec *vec)
{
    vec->x = vec->x * lookAT.camX.x + vec->y * lookAT.camX.y + vec->z * lookAT.camX.z;
    vec->y = vec->x * lookAT.camY.x + vec->y * lookAT.camY.y + vec->z * lookAT.camY.z;
    vec->z = vec->x * lookAT.camZ.x + vec->y * lookAT.camZ.y + vec->z * lookAT.camZ.z;
}

t_vec   createRay(float x, float y, t_matrix lookAt, t_cam cam)
{
    t_vec   dir;
    float ratio;

    ratio = WIDTH / HEIGHT;
    dir.x = (2 * ((x + 0.5) / WIDTH) - 1) * tan(cam.fov / 2 * 3.14 / 180) * ratio;
    dir.y = (1 - 2 * (y + 0.5) / HEIGHT) * tan(cam.fov / 2 * 3.14 / 180);
    dir.z = 0.5;
    camToWorld(lookAt, &dir);
    return (dir);
}


t_ray   rayGenerate(float x, float y, t_cam camera)
{
    t_ray   ray;
    t_matrix lookAt;
    // t_vec   to;

    // to.x = 0;
    // to.y = 0;
    // to.z = 0;
    ray.orig = camera.orig;
  //  build_camray(&camera, &ray, x, y);
    LookAt(&lookAt, camera);
    ray.dir = rayDirGenerate(lookAt, camera, x, y);
    // ray.dir = createRay(x, y, lookAt, camera);
    // ray.dir = normalize(ray.dir);
  //  printf("ray dir x == %f, y == %f, z == %f\n", ray.dir.x, ray.dir.y, ray.dir.z);
    return (ray);
}
