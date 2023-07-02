#include "minirt.h"

t_ray   createRay(t_vec orig, t_vec dir)
{
    t_ray ray;

    ray.dir = dir;
    ray.orig = orig;
    return (ray);
}

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

t_ray   rayGenerate(float x, float y, t_cam camera)
{
    t_ray   ray;
    t_vec   to;
    t_matrix lookAt;

    to.x = 0;
    to.y = 0;
    to.z = 20;
    ray.orig = camera.orig;
    LookAt(&lookAt, camera, to);
    ray.dir = rayDirGenerate(lookAt, camera, x, y);
    return (ray);
}