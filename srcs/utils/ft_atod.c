#include "utils.h"
#include "stdbool.h"

static bool	ft_iswhite(char c)
{
	if (c == '\n' || c == ' ' || c == '\f' || c == '\t' || c == '\v'
		|| c == '\r')
		return (true);
	return (false);
}

double ft_atod(const char *str) {
    double nb = 0.0;
    double part = 0.0;
    double sign = 1.0;

    while (ft_iswhite(*str)) {
        str++;
    }

    if (*str == '-') {
        sign = -1.0;
        str++;
    } else if (*str == '+') {
        str++;
    }

    while (*str >= '0' && *str <= '9') {
        nb = nb * 10 + (*str - '0');
        str++;
    }

    if (*str == '.' || *str == ',') {
        str++;
        double divider = 10.0;
        while (*str >= '0' && *str <= '9') {
            part += (*str - '0') / divider;
            divider *= 10.0;
            str++;
        }
    }

    return (nb + part) * sign;
}
