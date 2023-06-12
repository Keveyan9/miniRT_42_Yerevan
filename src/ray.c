#include "minirt.h"

t_ray   createRay(t_vec orig, t_vec dir)
{
    t_ray ray;

    ray.dir = dir;
    ray.orig = orig;
    return (ray);
}

t_vec   gettingWPrime(t_vec u, t_vec v, t_vec w, int width, int height, t_cam camera)
{
    t_vec   wPrime;
    t_vec   uCoeff;
    t_vec   vCoeff;
    t_vec   wCoeff;

    // uCoeff = vecScale((-width/2), u);
    // vCoeff = vecScale((height/2), v);
    // wCoeff = vecScale(((-height/2)/tan(fov * 0.5)), w);
    // wPrime = vecAdd(vecAdd(uCoeff, vCoeff), wCoeff);
    return(wPrime);
}

t_vec   rayDirGenerate(t_vec u, t_vec v, t_vec w, int width, int height, t_cam camera)//t_matrix lookAt, 
{
    t_vec   rayDir;
    t_vec   xu;
    t_vec   yMinusv;
    t_vec   wPrime;

    // xu = vectMult(x, u);
    // yMinusv = vectMult(y, -v);
    // wPrime = gettingWPrime();
    // rayDir = vecAdd(vecAdd(xu, yMinusv), wPrime);
    // normalize(&rayDir)
    return (rayDir);
}

t_ray   rayGenerate(t_vec u, t_vec v, t_vec w, int width, int height, t_cam camera)//t_matrix lookAt
{
    t_ray   ray;

    ray.orig = camera.orig;
    ray.dir = rayDirGenerate(u, v, w, width, height, camera);
     
}