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

    uCoeff = vecScale((-width/2), u);//why - ?????
    vCoeff = vecScale((height/2), v);
    wCoeff = vecScale(((-height/2)/tan(camera.fov * 0.5)), w);
    wPrime = vecAdd(vecAdd(uCoeff, vCoeff), wCoeff);
    return(wPrime);
}

t_vec   rayDirGenerate(t_vec u, t_vec v, t_vec w, int width, int height, t_cam camera, float x, float y)//t_matrix lookAt, 
{
    t_vec   rayDir;
    t_vec   xu;
    t_vec   yMinusv;
    t_vec   wPrime;

    xu = vecScale(x, u);
    yMinusv = vecScale(y, vecScale(-1, v));
    wPrime = gettingWPrime(u, v, w, width, height, camera);
    rayDir = vecAdd(vecAdd(xu, yMinusv), wPrime);
    rayDir = normalize(rayDir);//changing with address
    return (rayDir);
}

t_ray   rayGenerate(int width, int height, float x, float y)//t_matrix lookAt
{
    t_ray   ray;
    t_vec   u;
    t_vec   v;
    t_vec   w;
    //t_matrix lookAt;
    //lookAt.u; .v; .w;
    t_cam   camera;// = lookAt(lookAt.u, lookAt.v, lookAt.w)

    ray.orig = camera.orig;
    ray.dir = rayDirGenerate(u, v, w, width, height, camera, x, y);
    return (ray);
}

bool    rayTrace()
{
    
}

t_color    rayCast(int width, int height, t_ray ray)
{
    //rays from origin to x, y
}

void    render(int width, int height)//, t_mlx mlxData)
{
    t_ray   ray;
    int     x;
    int     y;

    x = -1;
    y = -1;
    while (++x < width)
    {
        y = -1;
        while (++y < height)
        {
            ray = rayGenerate(width, height, x, y);
            //raycast();
        }
    }
}