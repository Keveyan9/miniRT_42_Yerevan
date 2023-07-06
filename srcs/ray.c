#include "/Users/zkarapet/Desktop/newminirt/includes/minirt.h"

t_vec   gettingWPrime(t_matrix lookAt, t_cam camera)
{
    t_vec   wPrime;
    t_vec   uCoeff;
    t_vec   vCoeff;
    t_vec   wCoeff;

    uCoeff = vecScale((-WIDTH/2), lookAt.right);//why - ?????
    vCoeff = vecScale((HEIGHT/2), lookAt.up);
    wCoeff = vecScale(((-HEIGHT/2)/tan((camera.fov * 0.5 * M_PI) / 180)), lookAt.forward);
    // print_vec(wCoeff, "Z is ::: ");
    wPrime = vecAdd(vecAdd(uCoeff, vCoeff), wCoeff);
    return(wPrime);
}

t_vec   rayDirGenerate(t_matrix lookAt, t_cam camera, float x, float y)
{
    t_vec   rayDir;
    t_vec   xu;
    t_vec   yMinusv;
    t_vec   wPrime;

    xu = vecScale(x, lookAt.right);
    yMinusv = vecScale(y, vecScale(-1, lookAt.up));
    wPrime = gettingWPrime(lookAt, camera);
    rayDir = vecAdd(vecAdd(xu, yMinusv), wPrime);
    rayDir = normalize(rayDir);
    return (rayDir);
}

// t_vec   vecMultMatrix(t_matrix m, t_vec v)
// {
//     t_vec   dest;

//     // print_vec(m.forward, "forward isss\n");
//     // print_vec(m.up, "up isss\n");
//     // print_vec(m.right, "right isss\n");
//     dest.x = v.x * m.right.x + v.y * m.up.x + v.z * m.forward.x;
//     dest.y = v.x * m.right.y + v.y * m.up.y + v.z * m.forward.y;
//     dest.z = v.x * m.right.z + v.y * m.up.z + v.z * m.forward.z;
//     return (dest);
// }

// t_vec   rayDirGenerate(t_matrix lookAt, t_cam camera, float x, float y)
// {
//     t_vec   rayDir;
//     float   scale;
//     float   aspectRatio;

//     if (HEIGHT < WIDTH)
//         aspectRatio = (float)WIDTH / (float)HEIGHT;
//     else
//         aspectRatio = (float)HEIGHT / (float)WIDTH;
//     // printf("aspectratio == %f\n", aspectRatio);
//     scale = tan((camera.fov * 0.5 * M_PI) / 180);
//     // printf("scale == %f\n", scale);
//     rayDir.x = (2.0 * (x + 0.5) / (float)WIDTH - 1.0) * scale * aspectRatio;
//     // printf("rayDir.x == %f\n", rayDir.x);
//     rayDir.y = (1.0 - 2.0 * (y + 0.5) / (float)HEIGHT) * scale;
//     // printf("rayDir.y == %f\n", rayDir.y);
//     rayDir.z = FOCAL_DIST;
//     rayDir = vecMultMatrix(lookAt, rayDir);
//     rayDir = normalize(rayDir);
//     return (rayDir);
// }

t_ray   rayGenerate(float x, float y, t_cam camera)
{
    t_ray       ray;
    t_matrix    lookAt;

    ray.orig = camera.orig;
    // printf("HEIGHT/2 == %d\n", HEIGHT/2);
    // printf("camera.fov * 0.5 == %f\n", tan((camera.fov * 0.5 * M_PI) / 180));
    // printf("((-HEIGHT/2)/tan(camera.fov * 0.5)) == %f\n", ((-HEIGHT/2)/tan((camera.fov * 0.5 * M_PI) / 180)));
    LookAt(&lookAt, camera);
    ray.dir = rayDirGenerate(lookAt, camera, x, y);
    return (ray);
}