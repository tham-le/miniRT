#include "miniRT.h"

void set_texture(t_objs **obj, void *mlx_ptr)
{
	(void)obj;
	(void)mlx_ptr;
	return;
    // if((*obj)->bump_img)
    //     (*obj)->surface = load_img((*obj)->bump_img, mlx_ptr);
}

t_xpm_img *load_img(char *bmp_img, void *mlx_ptr)
{
    t_xpm_img	*img;

	img = ft_calloc(1, sizeof(t_xpm_img));
    if (!img)
		return (NULL);
    if (ft_strcmp(&bmp_img[ft_strlen(bmp_img) - 4], ".xpm") != 0)
		write(STDERR_FILENO, "Wrong format image file [.xpm]\n", 31);
    img->img_ptr = mlx_xpm_file_to_image(mlx_ptr, bmp_img, &img->width, &img->height);
    if (!img->img_ptr)
		write(STDERR_FILENO, "Failed to load [.xpm] image file\n", 33);
	  img->addr = mlx_get_data_addr(img->img_ptr, \
		  &img->bpp, &img->line, &img->endian);
	return (img);
}
