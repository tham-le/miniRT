/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_bump_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itchinda <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 21:45:58 by itchinda          #+#    #+#             */
/*   Updated: 2023/10/19 22:04:51 by itchinda         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

void	push_bump_color(t_colors_bmp *obj, t_colors_bmp **objs)
{
	t_colors_bmp	*tmp;

	if (!(*objs))
		*objs = obj;
	else
	{
		tmp = *objs;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = obj;
	}
}

unsigned int	stringtohex(const char *input, int i)
{
	unsigned int	result;
	unsigned char	byte;
	unsigned char	uppernibble;
	unsigned char	lowernibble;
	int				length;

	result = 0;
	length = ft_strlen(input);
	byte = 0;
	uppernibble = 0;
	lowernibble = 0;
	while (i < length)
	{
		byte = input[i];
		uppernibble = (byte >> 4) & 0x0F;
		result = (result << 4) | uppernibble;
		lowernibble = byte & 0x0F;
		result = (result << 4) | lowernibble;
		i++;
	}
	return (result);
}

int	str_to_int(char *str)
{
	unsigned int	hexa;
	int				result;
	int				numnibbles;
	int				nibbleindex;
	int				nibblevalue;

	hexa = stringtohex(str, 0);
	result = 0;
	numnibbles = sizeof(unsigned int) * 2;
	nibbleindex = numnibbles - 1;
	while (nibbleindex >= 0)
	{
		nibblevalue = (hexa >> (nibbleindex * 4)) & 0xF;
		result <<= 4;
		result |= nibblevalue;
		nibbleindex--;
	}
	return (result);
}

int	convert_to_color(char pixel, t_colors_bmp **pixel_lst)
{
	t_colors_bmp		*ptr;

	ptr = (*pixel_lst);
	while (ptr)
	{
		if (ptr->c == pixel)
			return (str_to_int(ptr->color));
		ptr = ptr->next;
	}
	return (0);
}
