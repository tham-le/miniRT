/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:54:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/10/26 21:35:14 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include "stdlib.h"

void	ft_lstaddback(t_objs **alst, t_objs *new);
double	ft_atod(const char *str);
int		clean(t_data *data, int state);
int		ft_print_help(void);
int		ft_tabsize(char **tab);
void	add_colors(t_color *res, const t_color *c1, const t_color *c2);
void	mult_color(t_color *res, const t_color *color, double val);
void	sub_colors(t_color *res, const t_color *c1, const t_color *c2);
void	blend_colors(t_color *res, const t_color *c1, const t_color *c2);
void	ft_freearr(char **tab);
void	ft_freearr_int(int **tab);
void	init_obj_value(t_objs	*obj);
void	ft_clear_light(t_light **lst, void (*del)(void *));
void	ft_clear_obj(t_objs **lst, void (*del)(void *));
void	ft_swapd(double *a, double *b);
int		ft_atoi_base(char *str, char *base);
#endif
