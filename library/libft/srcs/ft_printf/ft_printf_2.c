/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 11:33:57 by thi-le            #+#    #+#             */
/*   Updated: 2023/01/30 15:58:26 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

int	ft_print_str(char *s)
{
	int	len;

	len = 0;
	if (s == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (*s)
	{
		ft_putchar(*s++);
		len++;
	}
	return (len);
}

int	ft_print_uint(unsigned int nbr)
{
	int	len;

	len = 0;
	len += ft_putnum(nbr, 10, "0123456789");
	return (len);
}

int	ft_printpercent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putnum(unsigned long long n, unsigned int base, const char *digits)
{
	int	res;

	res = 1;
	if (n >= base)
		res += ft_putnum(n / base, base, digits);
	ft_putchar(digits[n % base]);
	return (res);
}
