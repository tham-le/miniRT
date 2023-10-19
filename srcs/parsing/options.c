#include "miniRT.h"

void	add_options(t_objs *obj, char **elems)
{
	add_bmp_file(obj, elems);
	add_reflect_opt(obj, elems);
	add_diffuse_opt(obj, elems);
	add_shine_opt(obj, elems);
	add_specular_opt(obj, elems);
}