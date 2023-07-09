#include "minirt.h"

t_vec   gettingWPrime(t_matrix lookAt)
{
    t_vec   wPrime;
    t_vec   uCoeff;
    t_vec   vCoeff;
    t_vec   wCoeff;

    uCoeff = vecScale((-WIDTH/2), lookAt.right);
    vCoeff = vecScale((HEIGHT/2), lookAt.up);
    wCoeff = vecScale(500, lookAt.forward);
    wPrime = vecAdd(vecAdd(uCoeff, vCoeff), wCoeff);
    return(wPrime);
}

t_vec   rayDirGenerate(t_matrix lookAt, float x, float y)
{
    t_vec   rayDir;
    t_vec   xu;
    t_vec   yMinusv;
    t_vec   wPrime;

    xu = vecScale(x, lookAt.right);
    yMinusv = vecScale(y, vecScale(-1, lookAt.up));
    wPrime = gettingWPrime(lookAt);
    rayDir = vecAdd(vecAdd(xu, yMinusv), wPrime);
    rayDir = normalize(rayDir);
    return (rayDir);
}

t_ray   rayGenerate(float x, float y, t_cam camera)
{
    t_ray       ray;
    t_matrix    lookAt;

    ray.orig = camera.orig;
    LookAt(&lookAt, camera);
    ray.dir = rayDirGenerate(lookAt, x, y);
    return (ray);
}