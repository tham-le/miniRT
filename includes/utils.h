/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thi-le <thi-le@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 18:54:01 by thi-le            #+#    #+#             */
/*   Updated: 2023/09/10 20:02:51 by thi-le           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "structs.h"
# include "stdlib.h"
# include "miniRT.h"

void	        ft_lstaddback(t_objs **alst, t_objs *new);
double			ft_atod(const char *str);
int	            clean(t_data *data, int state);
int	            ft_print_help(void);
int		ft_tabsize(char **tab);



#endif
