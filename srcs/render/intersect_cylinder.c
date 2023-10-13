#include "miniRT.h"
#include "render.h"
#include "structs.h"

static bool	within_cylinder_radius(const t_ray *ray, double t)
{
	double	x;
	double	z;

	x = ray->origin.x + ray->direction.x * t;
	z = ray->origin.z + ray->direction.z * t;
	if ((x * x + z * z) <= 1)
		return (true);
	return (false);
}

static bool	check_cylinder_caps(const t_ray *ray, t_objs *obj,
		t_intersect_list *xs)
{
	bool	intersected;
	double	t;

	intersected = false;
	if (fabs(ray->direction.y) > EPSILON)
	{
		t = (-(obj->height / 2) - ray->origin.y) / ray->direction.y;
		if (within_cylinder_radius(ray, t))
		{
			xs->arr[xs->count].t = t;
			xs->arr[xs->count].obj = obj;
			xs->count++;
			intersected = true;
		}
		t = ((obj->height / 2) - ray->origin.y) / ray->direction.y;
		if (within_cylinder_radius(ray, t))
		{
			xs->arr[xs->count].t = t;
			xs->arr[xs->count].obj = obj;
			xs->count++;
			intersected = true;
		}
	}
	return (intersected);
}

static bool	add_cylinder_intersections(t_objs *obj, const t_ray *ray,
		t_intersect_list *xs, double *ts)
{
	double	y0;
	double	y1;
	bool	intersected;

	intersected = false;
	if (ts[0] > ts[1])
		ft_swapd(&ts[0], &ts[1]);
	y0 = ray->origin.y + ts[0] * ray->direction.y;
	if (y0 > (-obj->height / 2) && y0 < (obj->height / 2))
	{
		xs->arr[xs->count].t = ts[0];
		xs->arr[xs->count].obj = obj;
		xs->count++;
		intersected = true;
	}
	y1 = ray->origin.y + ts[1] * ray->direction.y;
	if (y1 > (-obj->height / 2) && y1 < (obj->height / 2))
	{
		xs->arr[xs->count].t = ts[1];
		xs->arr[xs->count].obj = obj;
		xs->count++;
		intersected = true;
	}
	return (intersected);
}

bool	intersect_cylinder(const t_ray *ray, t_objs *obj,
	t_intersect_list *xs)
{
	bool	intersected;
	double	a;
	double	b;
	double	ts[2];
	double	discriminant;

	intersected = check_cylinder_caps(ray, obj, xs);
	a = ray->direction.x * ray->direction.x + ray->direction.z * ray->direction.z;
	if (fabs(a) < 0.0001)
		return (intersected);
	b = 2 * ray->direction.x * ray->origin.x + 2 * ray->direction.z * ray->origin.z;
	discriminant = b * b - 4 * a * \
		(ray->origin.x * ray->origin.x + ray->origin.z * ray->origin.z - 1);
	if (discriminant < 0)
		return (intersected);
	a *= 2;
	b *= -1;
	discriminant = sqrt(discriminant);
	ts[0] = (b - discriminant) / (a);
	ts[1] = (b + discriminant) / (a);
	if (add_cylinder_intersections(obj, ray, xs, ts))
		intersected = true;
	return (intersected);
}
