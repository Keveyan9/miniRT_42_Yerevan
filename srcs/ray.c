#include "minirt.h"

t_vec	getting_wprime(t_matrix look_at)
{
	t_vec	w_prime;
	t_vec	u_coeff;
	t_vec	v_coeff;
	t_vec	w_coeff;

	u_coeff = vec_scale(((float)-(WIDTH - 1)/2), look_at.right);
	v_coeff = vec_scale(((float)(HEIGHT - 1)/2), look_at.up);
	w_coeff = vec_scale(500, look_at.forward);
	w_prime = vec_add(vec_add(u_coeff, v_coeff), w_coeff);
	return (w_prime);
}

t_vec	ray_dir_generate(t_matrix look_at, float x, float y)
{
	t_vec	ray_dir;
	t_vec	xu;
	t_vec	yminusv;
	t_vec	w_prime;

	xu = vec_scale(x, look_at.right);
	yminusv = vec_scale(y, vec_scale(-1, look_at.up));
	w_prime = getting_wprime(look_at);
	ray_dir = vec_add(vec_add(xu, yminusv), w_prime);
	ray_dir = normalize(ray_dir);
	return (ray_dir);
}

t_ray	ray_generate(float x, float y, t_cam camera)
{
	t_ray		ray;
	t_matrix	lookat;

	ray.orig = camera.orig;
	look_at(&lookat, camera);
	ray.dir = ray_dir_generate(lookat, x, y);
	return (ray);
}
