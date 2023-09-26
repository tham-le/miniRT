#include "miniRT.h"

unsigned int	clamp_xpm(unsigned int pxl, unsigned int min, unsigned int max)
{
	if (pxl > max)
		pxl = max;
	else if (pxl < min)
		pxl = min;
	return (pxl);
}

// unsigned int	xpm_color(t_xpm_image *img, int x, int y)
// {
// 	char	*dst;

// 	x = clamp_xpm(x, 0, img->width - 1);
// 	y = clamp_xpm(y, 0, img->height - 1);
// 	dst = img->data.addr + (y * img->data.line + x * (img->data.bpp / 8));
// 	return (*(unsigned int *)dst);
// }